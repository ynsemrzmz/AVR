using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace AVRUart
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        string[] ports;
        string[] baudRates = { "1200", "2400", "4800", "9600", "19200", "38400", "57600", "115200" };

        private void init_ports()
        {
            ports = SerialPort.GetPortNames();
            foreach(string port in ports)
            {
                comboBox1.Items.Add(port);
            }

            foreach(string baudRate in baudRates)
            {
                comboBoxBaudRates.Items.Add(baudRate);
            }

            comboBoxBaudRates.SelectedIndex = 3;

        }

        private void connect()
        {
            if(comboBox1.SelectedItem != null && comboBoxBaudRates.SelectedItem != null)
            {
                serialPort1.PortName = comboBox1.SelectedItem.ToString();
                serialPort1.BaudRate = Convert.ToInt32(comboBoxBaudRates.SelectedItem);
                serialPort1.Open();
                label2.ForeColor = Color.Green;
                label2.Text = "Connected";
            }
            else
            {
                MessageBox.Show("Lütfen port ve baud rate seçimini yapınız");
            }
        }


        private void Form1_Load(object sender, EventArgs e)
        {
            init_ports();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            connect();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                serialPort1.Write("a");
            }
            catch(Exception ex)
            {
                MessageBox.Show("Bağlantı açık değil");
            }
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                serialPort1.Write("b");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Bağlantı açık değil");
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            try
            {
                serialPort1.Write("c");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Bağlantı açık değil");
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            try
            {
                serialPort1.Write("d");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Bağlantı açık değil");
            }
        }
    }
}
