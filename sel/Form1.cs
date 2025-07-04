using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace sel
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            serialPort1 = new SerialPort();
            serialPort1.PortName = "COM28";
            serialPort1.BaudRate = 9600;
            serialPort1.DataReceived += serialPort1_DataReceived;
            serialPort1.Open();
            label1.Text = "Durum: Bağlı";
            textBox1.Text = "10";
            try
            {
                serialPort1.Write("OPENED");
            }
            catch { }
        }
        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            try
            {
                string data = serialPort1.ReadLine();

                this.Invoke(new Action(() => {
                    if (data.Trim() == "SEL")
                    {
                        label2.Text = "Sel Durumu: Sel Saptandı!";
                    }
                    if (data.Trim() == "SEL BITTI")
                    {
                        label2.Text = "Sel Durumu: Sel Durdu";
                    }
                }));
            }
            catch { }



        }
        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                String time = textBox1.Text;
                serialPort1.Write(time);
            }
            catch {};       




        }

        private void button2_Click(object sender, EventArgs e)
        {
            serialPort1.Write("5");
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {

            try 
            { 
                serialPort1.Write("STOPED");
            }
            catch {}



        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            
        }


    }
}