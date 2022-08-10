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

        private void button1_Click(object sender, EventArgs e)
        {
            SerialWrite("1");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            SerialWrite("2");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            SerialWrite("3");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            SerialWrite("4");
        }

        private void SerialWrite(string value)
        {
            if (_serialPort != null && _serialPort.IsOpen)
            {
                _serialPort.Write(value);
            }
        }
    }
}
