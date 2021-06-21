using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;

namespace MDIWordPad
{
	/// <summary>
	/// Form1 的摘要说明。
	/// </summary>
	public class Form1 : System.Windows.Forms.Form
	{
		private System.Windows.Forms.MainMenu mainMenu1;
		private System.Windows.Forms.MenuItem fileMenu;
		private System.Windows.Forms.MenuItem fileOpen;
		private System.Windows.Forms.MenuItem fileSave;
		private System.Windows.Forms.MenuItem fileSaveAs;
		private System.Windows.Forms.MenuItem fileSep;
		private System.Windows.Forms.MenuItem fileExit;
		private System.Windows.Forms.MenuItem editMenu;
		private System.Windows.Forms.MenuItem editCut;
		private System.Windows.Forms.MenuItem editCopy;
		private System.Windows.Forms.MenuItem editPaste;
		private System.Windows.Forms.MenuItem editSep;
		private System.Windows.Forms.MenuItem editSelectAll;
		private System.Windows.Forms.MenuItem formatMenu;
		private System.Windows.Forms.MenuItem formatColor;
		private System.Windows.Forms.MenuItem formatFont;
		private System.Windows.Forms.MenuItem helpMenu;
		private System.Windows.Forms.MenuItem helpAbout;
		private System.Windows.Forms.FontDialog fontDialog1;
		private System.Windows.Forms.RichTextBox richTextBox1;
		private System.Windows.Forms.ColorDialog colorDialog1;
		private System.Windows.Forms.OpenFileDialog openFileDialog1;
		private System.Windows.Forms.SaveFileDialog saveFileDialog1;
		private System.Windows.Forms.MenuItem fileNew;
		private System.Windows.Forms.ToolBar toolBar1;
		private System.Windows.Forms.ToolBarButton copyButton;
		private System.Windows.Forms.ToolBarButton cutButton;
		private System.Windows.Forms.ToolBarButton pasteButton;
		private System.Windows.Forms.ImageList imageList1;
		private System.Windows.Forms.StatusBar statusBar1;
		private System.Windows.Forms.StatusBarPanel curPosPanel;
		private System.ComponentModel.IContainer components;

		public Form1()
		{
			//
			// Windows 窗体设计器支持所必需的
			//
			InitializeComponent();

			//
			// TODO: 在 InitializeComponent 调用后添加任何构造函数代码
			//
		}

		/// <summary>
		/// 清理所有正在使用的资源。
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
		/// 设计器支持所需的方法 - 不要使用代码编辑器修改
		/// 此方法的内容。
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			System.Resources.ResourceManager resources = new System.Resources.ResourceManager(typeof(Form1));
			this.mainMenu1 = new System.Windows.Forms.MainMenu();
			this.fileMenu = new System.Windows.Forms.MenuItem();
			this.fileNew = new System.Windows.Forms.MenuItem();
			this.fileOpen = new System.Windows.Forms.MenuItem();
			this.fileSave = new System.Windows.Forms.MenuItem();
			this.fileSaveAs = new System.Windows.Forms.MenuItem();
			this.fileSep = new System.Windows.Forms.MenuItem();
			this.fileExit = new System.Windows.Forms.MenuItem();
			this.editMenu = new System.Windows.Forms.MenuItem();
			this.editCut = new System.Windows.Forms.MenuItem();
			this.editCopy = new System.Windows.Forms.MenuItem();
			this.editPaste = new System.Windows.Forms.MenuItem();
			this.editSep = new System.Windows.Forms.MenuItem();
			this.editSelectAll = new System.Windows.Forms.MenuItem();
			this.formatMenu = new System.Windows.Forms.MenuItem();
			this.formatColor = new System.Windows.Forms.MenuItem();
			this.formatFont = new System.Windows.Forms.MenuItem();
			this.helpMenu = new System.Windows.Forms.MenuItem();
			this.helpAbout = new System.Windows.Forms.MenuItem();
			this.fontDialog1 = new System.Windows.Forms.FontDialog();
			this.richTextBox1 = new System.Windows.Forms.RichTextBox();
			this.colorDialog1 = new System.Windows.Forms.ColorDialog();
			this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
			this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
			this.toolBar1 = new System.Windows.Forms.ToolBar();
			this.cutButton = new System.Windows.Forms.ToolBarButton();
			this.copyButton = new System.Windows.Forms.ToolBarButton();
			this.pasteButton = new System.Windows.Forms.ToolBarButton();
			this.imageList1 = new System.Windows.Forms.ImageList(this.components);
			this.statusBar1 = new System.Windows.Forms.StatusBar();
			this.curPosPanel = new System.Windows.Forms.StatusBarPanel();
			((System.ComponentModel.ISupportInitialize)(this.curPosPanel)).BeginInit();
			this.SuspendLayout();
			// 
			// mainMenu1
			// 
			this.mainMenu1.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
																					  this.fileMenu,
																					  this.editMenu,
																					  this.formatMenu,
																					  this.helpMenu});
			// 
			// fileMenu
			// 
			this.fileMenu.Index = 0;
			this.fileMenu.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
																					 this.fileNew,
																					 this.fileOpen,
																					 this.fileSave,
																					 this.fileSaveAs,
																					 this.fileSep,
																					 this.fileExit});
			this.fileMenu.Text = "&File";
			// 
			// fileNew
			// 
			this.fileNew.Index = 0;
			this.fileNew.Shortcut = System.Windows.Forms.Shortcut.CtrlN;
			this.fileNew.Text = "&New";
			this.fileNew.Click += new System.EventHandler(this.fileNew_Click);
			// 
			// fileOpen
			// 
			this.fileOpen.Index = 1;
			this.fileOpen.Shortcut = System.Windows.Forms.Shortcut.CtrlO;
			this.fileOpen.Text = "&Open...";
			this.fileOpen.Click += new System.EventHandler(this.fileOpen_Click);
			// 
			// fileSave
			// 
			this.fileSave.Index = 2;
			this.fileSave.Shortcut = System.Windows.Forms.Shortcut.CtrlS;
			this.fileSave.Text = "Save";
			this.fileSave.Click += new System.EventHandler(this.fileSave_Click);
			// 
			// fileSaveAs
			// 
			this.fileSaveAs.Index = 3;
			this.fileSaveAs.Text = "Save &As...";
			this.fileSaveAs.Click += new System.EventHandler(this.fileSaveAs_Click);
			// 
			// fileSep
			// 
			this.fileSep.Index = 4;
			this.fileSep.Text = "-";
			// 
			// fileExit
			// 
			this.fileExit.Index = 5;
			this.fileExit.Text = "E&xit";
			this.fileExit.Click += new System.EventHandler(this.fileExit_Click);
			// 
			// editMenu
			// 
			this.editMenu.Index = 1;
			this.editMenu.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
																					 this.editCut,
																					 this.editCopy,
																					 this.editPaste,
																					 this.editSep,
																					 this.editSelectAll});
			this.editMenu.Text = "&Edit";
			// 
			// editCut
			// 
			this.editCut.Index = 0;
			this.editCut.Shortcut = System.Windows.Forms.Shortcut.CtrlX;
			this.editCut.Text = "C&ut";
			this.editCut.Click += new System.EventHandler(this.editCut_Click);
			// 
			// editCopy
			// 
			this.editCopy.Index = 1;
			this.editCopy.Shortcut = System.Windows.Forms.Shortcut.CtrlC;
			this.editCopy.Text = "&Copy";
			this.editCopy.Click += new System.EventHandler(this.editCopy_Click);
			// 
			// editPaste
			// 
			this.editPaste.Index = 2;
			this.editPaste.Shortcut = System.Windows.Forms.Shortcut.CtrlV;
			this.editPaste.Text = "&Paste";
			this.editPaste.Click += new System.EventHandler(this.editPaste_Click);
			// 
			// editSep
			// 
			this.editSep.Index = 3;
			this.editSep.Text = "-";
			// 
			// editSelectAll
			// 
			this.editSelectAll.Index = 4;
			this.editSelectAll.Shortcut = System.Windows.Forms.Shortcut.CtrlA;
			this.editSelectAll.Text = "Select &All";
			this.editSelectAll.Click += new System.EventHandler(this.editSelectAll_Click);
			// 
			// formatMenu
			// 
			this.formatMenu.Index = 2;
			this.formatMenu.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
																					   this.formatColor,
																					   this.formatFont});
			this.formatMenu.Text = "For&mat";
			// 
			// formatColor
			// 
			this.formatColor.Index = 0;
			this.formatColor.Text = "&Color...";
			this.formatColor.Click += new System.EventHandler(this.formatColor_Click);
			// 
			// formatFont
			// 
			this.formatFont.Index = 1;
			this.formatFont.Text = "&Font...";
			this.formatFont.Click += new System.EventHandler(this.formatFont_Click);
			// 
			// helpMenu
			// 
			this.helpMenu.Index = 3;
			this.helpMenu.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
																					 this.helpAbout});
			this.helpMenu.Text = "&Help";
			// 
			// helpAbout
			// 
			this.helpAbout.Index = 0;
			this.helpAbout.Text = "&About";
			this.helpAbout.Click += new System.EventHandler(this.helpAbout_Click);
			// 
			// richTextBox1
			// 
			this.richTextBox1.Dock = System.Windows.Forms.DockStyle.Fill;
			this.richTextBox1.Location = new System.Drawing.Point(0, 25);
			this.richTextBox1.Name = "richTextBox1";
			this.richTextBox1.Size = new System.Drawing.Size(336, 162);
			this.richTextBox1.TabIndex = 0;
			this.richTextBox1.Text = "";
			this.richTextBox1.SelectionChanged += new System.EventHandler(this.richTextBox1_SelectionChanged);
			// 
			// saveFileDialog1
			// 
			this.saveFileDialog1.FileName = "doc1";
			// 
			// toolBar1
			// 
			this.toolBar1.Buttons.AddRange(new System.Windows.Forms.ToolBarButton[] {
																						this.cutButton,
																						this.copyButton,
																						this.pasteButton});
			this.toolBar1.DropDownArrows = true;
			this.toolBar1.ImageList = this.imageList1;
			this.toolBar1.Name = "toolBar1";
			this.toolBar1.ShowToolTips = true;
			this.toolBar1.Size = new System.Drawing.Size(336, 25);
			this.toolBar1.TabIndex = 1;
			this.toolBar1.ButtonClick += new System.Windows.Forms.ToolBarButtonClickEventHandler(this.toolBar1_ButtonClick);
			// 
			// cutButton
			// 
			this.cutButton.ImageIndex = 0;
			this.cutButton.ToolTipText = "剪切";
			// 
			// copyButton
			// 
			this.copyButton.ImageIndex = 1;
			this.copyButton.ToolTipText = "复制";
			// 
			// pasteButton
			// 
			this.pasteButton.ImageIndex = 2;
			this.pasteButton.ToolTipText = "粘贴";
			// 
			// imageList1
			// 
			this.imageList1.ColorDepth = System.Windows.Forms.ColorDepth.Depth8Bit;
			this.imageList1.ImageSize = new System.Drawing.Size(16, 16);
			this.imageList1.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList1.ImageStream")));
			this.imageList1.TransparentColor = System.Drawing.Color.Transparent;
			// 
			// statusBar1
			// 
			this.statusBar1.Location = new System.Drawing.Point(0, 187);
			this.statusBar1.Name = "statusBar1";
			this.statusBar1.Panels.AddRange(new System.Windows.Forms.StatusBarPanel[] {
																						  this.curPosPanel});
			this.statusBar1.Size = new System.Drawing.Size(336, 22);
			this.statusBar1.TabIndex = 2;
			// 
			// Form1
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(6, 14);
			this.ClientSize = new System.Drawing.Size(336, 209);
			this.Controls.AddRange(new System.Windows.Forms.Control[] {
																		  this.richTextBox1,
																		  this.statusBar1,
																		  this.toolBar1});
			this.Menu = this.mainMenu1;
			this.Name = "Form1";
			this.Text = "Form1";
			((System.ComponentModel.ISupportInitialize)(this.curPosPanel)).EndInit();
			this.ResumeLayout(false);

		}
		#endregion


		private string fileName = null;

		private void fileNew_Click(object sender, System.EventArgs e)
		{
			if( ! this.IsMdiChild )
			{
				fileName = null;
				this.richTextBox1.Text = "";
			}
			else
			{
				MainForm parent = this.MdiParent as MainForm;
				if( parent != null ) parent.NewChildWindow();
			}
		}

		private void fileOpen_Click(object sender, System.EventArgs e)
		{
			this.openFileDialog1.Filter = 
				"Rtf files(*.rtf)|" +
				"*.rtf|text files(*.txt,*.cs)|*.txt;*.cs|" +
				"All files(*.*)|*.*";
			DialogResult result = this.openFileDialog1.ShowDialog();
			if( result != DialogResult.OK ) return;
			fileName = this.openFileDialog1.FileName;
			try
			{
				this.richTextBox1.LoadFile( fileName, RichTextBoxStreamType.RichText );	
			}
			catch
			{
				this.richTextBox1.LoadFile( fileName, RichTextBoxStreamType.PlainText );
			}
			this.Text = "MyWordPad - " + fileName;
		}

		private void fileSave_Click(object sender, System.EventArgs e)
		{
			if( fileName == null) fileSaveAs_Click( sender, e );
		}

		private void fileSaveAs_Click(object sender, System.EventArgs e)
		{
			if( fileName != null )
				this.saveFileDialog1.FileName = fileName;
			DialogResult result = this.saveFileDialog1.ShowDialog();
			if( result != DialogResult.OK ) return;
			fileName = this.saveFileDialog1.FileName;
			this.richTextBox1.SaveFile( fileName );		
			this.Text = "MyWordPad - " + fileName;
		}

		private void fileExit_Click(object sender, System.EventArgs e)
		{
			this.Close();
		}

		private void editCut_Click(object sender, System.EventArgs e)
		{
			this.richTextBox1.Cut();
		}

		private void editCopy_Click(object sender, System.EventArgs e)
		{
			this.richTextBox1.Copy();
		}

		private void editPaste_Click(object sender, System.EventArgs e)
		{
			this.richTextBox1.Paste();
		}

		private void editSelectAll_Click(object sender, System.EventArgs e)
		{
			this.richTextBox1.SelectAll();
		}

		private void formatColor_Click(object sender, System.EventArgs e)
		{
			this.colorDialog1.Color = this.richTextBox1.SelectionColor;
			DialogResult result = this.colorDialog1.ShowDialog();
			if( result != DialogResult.OK ) return;
			this.richTextBox1.SelectionColor = this.colorDialog1.Color;
		}

		private void formatFont_Click(object sender, System.EventArgs e)
		{
			this.fontDialog1.Font = this.richTextBox1.SelectionFont;
			DialogResult result = this.fontDialog1.ShowDialog();
			if( result != DialogResult.OK ) return;
			this.richTextBox1.SelectionFont = this.fontDialog1.Font;
		}

		private void helpAbout_Click(object sender, System.EventArgs e)
		{
			MessageBox.Show( "A Simple Rich Text Editor","About...",
				MessageBoxButtons.OK,
				MessageBoxIcon.Information
				);
		}

		private void toolBar1_ButtonClick(object sender, System.Windows.Forms.ToolBarButtonClickEventArgs e)
		{
			if( e.Button == this.copyButton)
				this.editCopy_Click( null, null );
			else if( e.Button == this.cutButton )
				this.editCut_Click( null, null );
			else if( e.Button == this.pasteButton )
				this.editPaste_Click( null, null );
		}

		private void richTextBox1_SelectionChanged(object sender, System.EventArgs e)
		{
			int pos = this.richTextBox1.SelectionStart;
			string text = this.richTextBox1.Text;
			int col = 0, row = 0;
			for( int p = 0; p<pos; p ++ )
			{
				if( text[p]=='\n' ) 
				{
					row ++;
					col = 0;
					if(p+1<text.Length && text[p+1]=='\r') p++; //skip '\r'
				}
				else
				{
					col++;
				}
			}
			row ++;
			col ++;
			
			this.statusBar1.ShowPanels = true;
			this.curPosPanel.Text = "  行 " + row + "    列 " + col;
			this.statusBar1.Text = fileName;
		}

	}
}
