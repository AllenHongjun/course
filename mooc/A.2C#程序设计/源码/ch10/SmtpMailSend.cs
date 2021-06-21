using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;
using System.Web.Mail;

namespace MyMail
{
	/// <summary>
	/// Summary description for Form1.
	/// </summary>
	public class Form1 : System.Windows.Forms.Form
	{
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.TextBox txtSender;
		private System.Windows.Forms.TextBox txtRecipient;
		private System.Windows.Forms.TextBox txtSubject;
		private System.Windows.Forms.TextBox txtText;
		private System.Windows.Forms.TextBox txtAttachments;
		private System.Windows.Forms.Button btnAttachments;
		private System.Windows.Forms.Button btnSend;
		private System.Windows.Forms.OpenFileDialog openFileDialog1;
		private System.Windows.Forms.Button btnExit;

		MailMessage message = new MailMessage();
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;

		public Form1()
		{
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();

			//
			// TODO: Add any constructor code after InitializeComponent call
			//
		}

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			if( disposing )
			{
				if (components != null) 
				{
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}

		#region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.label1 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.label3 = new System.Windows.Forms.Label();
			this.label4 = new System.Windows.Forms.Label();
			this.txtSender = new System.Windows.Forms.TextBox();
			this.txtRecipient = new System.Windows.Forms.TextBox();
			this.txtSubject = new System.Windows.Forms.TextBox();
			this.txtText = new System.Windows.Forms.TextBox();
			this.txtAttachments = new System.Windows.Forms.TextBox();
			this.btnAttachments = new System.Windows.Forms.Button();
			this.btnSend = new System.Windows.Forms.Button();
			this.btnExit = new System.Windows.Forms.Button();
			this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
			this.SuspendLayout();
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(24, 16);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(104, 16);
			this.label1.TabIndex = 0;
			this.label1.Text = "发件人：";
			// 
			// label2
			// 
			this.label2.Location = new System.Drawing.Point(24, 48);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(104, 16);
			this.label2.TabIndex = 1;
			this.label2.Text = "收件人：";
			// 
			// label3
			// 
			this.label3.Location = new System.Drawing.Point(24, 80);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(104, 16);
			this.label3.TabIndex = 2;
			this.label3.Text = "主题：";
			// 
			// label4
			// 
			this.label4.Location = new System.Drawing.Point(24, 112);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(104, 24);
			this.label4.TabIndex = 3;
			this.label4.Text = "附件：";
			// 
			// txtSender
			// 
			this.txtSender.Location = new System.Drawing.Point(144, 16);
			this.txtSender.Name = "txtSender";
			this.txtSender.Size = new System.Drawing.Size(208, 21);
			this.txtSender.TabIndex = 5;
			this.txtSender.Text = "";
			// 
			// txtRecipient
			// 
			this.txtRecipient.Location = new System.Drawing.Point(144, 48);
			this.txtRecipient.Name = "txtRecipient";
			this.txtRecipient.Size = new System.Drawing.Size(208, 21);
			this.txtRecipient.TabIndex = 6;
			this.txtRecipient.Text = "";
			// 
			// txtSubject
			// 
			this.txtSubject.Location = new System.Drawing.Point(144, 80);
			this.txtSubject.Name = "txtSubject";
			this.txtSubject.Size = new System.Drawing.Size(208, 21);
			this.txtSubject.TabIndex = 7;
			this.txtSubject.Text = "";
			// 
			// txtText
			// 
			this.txtText.Location = new System.Drawing.Point(24, 184);
			this.txtText.Multiline = true;
			this.txtText.Name = "txtText";
			this.txtText.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
			this.txtText.Size = new System.Drawing.Size(328, 104);
			this.txtText.TabIndex = 9;
			this.txtText.Text = "";
			// 
			// txtAttachments
			// 
			this.txtAttachments.Location = new System.Drawing.Point(144, 112);
			this.txtAttachments.Multiline = true;
			this.txtAttachments.Name = "txtAttachments";
			this.txtAttachments.ReadOnly = true;
			this.txtAttachments.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
			this.txtAttachments.Size = new System.Drawing.Size(208, 48);
			this.txtAttachments.TabIndex = 8;
			this.txtAttachments.Text = "";
			// 
			// btnAttachments
			// 
			this.btnAttachments.Location = new System.Drawing.Point(24, 304);
			this.btnAttachments.Name = "btnAttachments";
			this.btnAttachments.TabIndex = 10;
			this.btnAttachments.Text = "附件";
			this.btnAttachments.Click += new System.EventHandler(this.btnAttachments_Click);
			// 
			// btnSend
			// 
			this.btnSend.Location = new System.Drawing.Point(152, 304);
			this.btnSend.Name = "btnSend";
			this.btnSend.TabIndex = 11;
			this.btnSend.Text = "发送";
			this.btnSend.Click += new System.EventHandler(this.btnSend_Click);
			// 
			// btnExit
			// 
			this.btnExit.Location = new System.Drawing.Point(280, 304);
			this.btnExit.Name = "btnExit";
			this.btnExit.TabIndex = 12;
			this.btnExit.Text = "退出";
			this.btnExit.Click += new System.EventHandler(this.btnCancel_Click);
			// 
			// Form1
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(6, 14);
			this.ClientSize = new System.Drawing.Size(368, 341);
			this.Controls.AddRange(new System.Windows.Forms.Control[] {
																		  this.btnExit,
																		  this.btnSend,
																		  this.btnAttachments,
																		  this.txtText,
																		  this.txtAttachments,
																		  this.txtSubject,
																		  this.txtRecipient,
																		  this.txtSender,
																		  this.label4,
																		  this.label3,
																		  this.label2,
																		  this.label1});
			this.Name = "Form1";
			this.Text = "E-Mailer";
			this.ResumeLayout(false);

		}
		#endregion

		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main() 
		{
			Application.Run(new Form1());
		}

		private void btnCancel_Click(object sender, System.EventArgs e)
		{
			Application.Exit();
		}

		private void btnAttachments_Click(object sender, System.EventArgs e)
		{
			openFileDialog1.ShowDialog();
			MailAttachment attachment  = new MailAttachment(openFileDialog1.FileName);
			txtAttachments.Text = txtAttachments.Text + openFileDialog1.FileName;
			message.Attachments.Add(attachment);
		}

		private void btnSend_Click(object sender, System.EventArgs e)
		{
			message.From = txtSender.Text;
			message.To = txtRecipient.Text;
			message.Subject = txtSubject.Text;
			message.Body = txtText.Text;
			SmtpMail.Send(message);
			MessageBox.Show("邮件成功发送!");
		}
	}
}
