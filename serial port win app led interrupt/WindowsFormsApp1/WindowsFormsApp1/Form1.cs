using System;
using System.IO.Ports;
using System.Windows.Forms;
using System.Threading;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        SerialPort _serialPort;
        private string ReceivedData;

        public Form1()
        {
            InitializeComponent();

            if (_serialPort == null)
            {
                _serialPort = new SerialPort("COM4", 9600);
                _serialPort.Open();
            }

            _serialPort.DataReceived += new SerialDataReceivedEventHandler(_serialPort_DataReceived);
            
        }


        private void _serialPort_DataReceived(object sender, SerialDataReceivedEventArgs e) {
            //Thread.Sleep(200);
            
            ReceivedData = _serialPort.ReadLine();  // bufferdan veri okuma
            if (richTextBox1.InvokeRequired)
            {
                richTextBox1.Invoke(new MethodInvoker(delegate {

                    richTextBox1.Text += ReceivedData.ToString() + "\n";
                    
                    
                    
                }));
                
                
                
            }            
        }


        // led 1 on
        private void button1_Click(object sender, EventArgs e)
        {
            SerialWrite("1");
        }

        // led 1 off
        private void button2_Click(object sender, EventArgs e)
        {
            SerialWrite("2");
        }

        // led 2 on
        private void button3_Click(object sender, EventArgs e)
        {
            SerialWrite("3");
        }

        // led 2 off
        private void button4_Click(object sender, EventArgs e)
        {
            SerialWrite("4");
        }

        // blink leds on
        private void button6_Click(object sender, EventArgs e)
        {
            SerialWrite("5");
        }

        // blink leds off
        private void button5_Click(object sender, EventArgs e)
        {
            SerialWrite("6");
        }


        private void SerialWrite(string value)
        {
            if (_serialPort != null && _serialPort.IsOpen)
            {
                _serialPort.WriteLine(value);
            }
            
        }

        

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
