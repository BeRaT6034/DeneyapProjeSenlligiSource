#define nemPin A0
#define kirmiziLed D12
#define yesilLed D13
#define buzzerPin D15
String received= "";
String newEsik = "";
int esik = 10;
int sure = 0;
bool isOpen = false;
bool sel = false;

void setup() {
    Serial.begin(9600);
    pinMode(nemPin, INPUT);
    pinMode(kirmiziLed, OUTPUT);
    pinMode(yesilLed, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    
}
            
void loop() {
  if (Serial.available() > 0){
    received = "";
    newEsik = "";
    isOpen = true;
    sure = 0;
    esik = 10;
    
      while(isOpen == true){
        received = Serial.readString();
        
        digitalWrite(yesilLed, HIGH);

        if (received != "" && received!= "STOPED"){
          newEsik = received;
          newEsik.trim();
          esik = newEsik.toInt();
          
          if (digitalRead(nemPin) == HIGH && sure < esik){
            digitalWrite(kirmiziLed, HIGH);
            digitalWrite(yesilLed, LOW);
            digitalWrite(buzzerPin,HIGH);
            Serial.println("SEL");
            sel = true;
        }
          else{
            digitalWrite(buzzerPin,LOW);
            digitalWrite(kirmiziLed, LOW);
            sel = false;

          }
        }
        
        if (digitalRead(nemPin) == HIGH && sure < esik){
          digitalWrite(kirmiziLed, HIGH);
          digitalWrite(yesilLed, LOW);
          digitalWrite(buzzerPin,HIGH);
          Serial.println("SEL");
          sel = true;
        }
        else{
          digitalWrite(buzzerPin,LOW);
          digitalWrite(kirmiziLed, LOW);
          sel = false;

        }

        if (received == "STOPED"){
          isOpen = false;
          sure = 0;
        }
        sure = sure + 1;
        delay(1000);
        }
    
  }
  
  else{
    sure = 0;
    esik = 10;
    while(sel == false && isOpen == false){
      
      digitalWrite(yesilLed, HIGH);
      delay(200);
      digitalWrite(yesilLed, LOW);
      delay(200);
      digitalWrite(yesilLed, HIGH);
      delay(200);
      digitalWrite(yesilLed, LOW);
      delay(200);
      digitalWrite(yesilLed, HIGH);
      delay(200);
      digitalWrite(yesilLed, LOW);
        
      Serial.println(esik);
      
      
      if (Serial.available() > 0){
        isOpen = true;
      }
      
      sure = sure + 1;
      
      if (digitalRead(nemPin) == HIGH && sure < esik){
        digitalWrite(kirmiziLed, HIGH);
        digitalWrite(yesilLed, LOW);
        digitalWrite(buzzerPin,HIGH);
        Serial.println("SEL");
        sel = true;
      }
      
      else{
        digitalWrite(buzzerPin,LOW);
        digitalWrite(kirmiziLed, LOW);
        sel = false;
        
      }

      
      
    }
      
  }

    if (digitalRead(nemPin) == HIGH && sure < esik){
      digitalWrite(kirmiziLed, HIGH);
      digitalWrite(yesilLed, LOW);
      digitalWrite(buzzerPin,HIGH);
      Serial.println("SEL");
      sel = true;
    }
      
    else{
      digitalWrite(buzzerPin,LOW);
      digitalWrite(kirmiziLed, LOW);
      sel = false;

    }

}