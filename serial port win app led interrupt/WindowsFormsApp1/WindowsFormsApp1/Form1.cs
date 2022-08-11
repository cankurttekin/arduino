using System;

using System.IO.Ports;

using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        SerialPort _serialPort;
        
        public Form1()
        {
            InitializeComponent();

            if (_serialPort == null)
            {
                _serialPort = new SerialPort("COM4", 9600);
                _serialPort.Open();
            }
        }

        // LED 1 ON
        private void button1_Click(object sender, EventArgs e)
        {
            SerialWrite("1");
        }

        // LED 1 OFF
        private void button2_Click(object sender, EventArgs e)
        {
            SerialWrite("2");
        }

        // LED 2 ON
        private void button3_Click(object sender, EventArgs e)
        {
            SerialWrite("3");
        }

        // LED 2 OFF
        private void button4_Click(object sender, EventArgs e)
        {
            SerialWrite("4");
        }

        // Blink 2 leds ON
        private void button6_Click(object sender, EventArgs e)
        {
            SerialWrite("5");
        }

        // Blink 2 leds OFF
        private void button5_Click(object sender, EventArgs e)
        {
            SerialWrite("6");
        }


        private void SerialWrite(string value)
        {
            if (_serialPort != null && _serialPort.IsOpen)
            {
                _serialPort.Write(value);
            }
        }
        

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        
    }
}
