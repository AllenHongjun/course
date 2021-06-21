using System;
using System.Collections;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Windows.Forms;

namespace TestCtrl
{
	/// <summary>
	/// UserControl1 的摘要说明。
	/// </summary>
	public class TrafficLight : System.Windows.Forms.UserControl
	{
		private System.Windows.Forms.Timer timer1;
		private System.ComponentModel.IContainer components;

		public TrafficLight()
		{
			// 该调用是 Windows.Forms 窗体设计器所必需的。
			InitializeComponent();

			// TODO: 在 InitializeComponent 调用后添加任何初始化

		}

		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			if( disposing )
			{
				if( components != null )
					components.Dispose();
			}
			base.Dispose( disposing );
		}

		#region Component Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要使用代码编辑器 
		/// 修改此方法的内容。
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			this.timer1 = new System.Windows.Forms.Timer(this.components);
			// 
			// timer1
			// 
			this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
			// 
			// TrafficLight
			// 
			this.Name = "TrafficLight";
			this.Size = new System.Drawing.Size(224, 80);
			this.Load += new System.EventHandler(this.TrafficLight_Load);

		}
		#endregion

	
		protected override void OnPaint( PaintEventArgs e )
		{
			Graphics g = e.Graphics;
			UserControl_Resize();
			this.RedLight.Paint( g );
			this.GreenLight.Paint( g );
			this.YellowLight.Paint( g);
		}

		int curLightIndex ;          //当前所亮的灯

		//public event LightChanged()  ;//事件


	
		private void UserControl_Resize()
		{
			// 变换灯的大小
			int w, h, d;
			w = this.Width;
			h = this.Height;
			d = w / 4;
			if( d > h ) d = h;
			RedLight.Move (d / 4, (h - d) / 2, d, d);
			YellowLight.Move (d + d / 2, (h - d) / 2, d, d);
			GreenLight.Move (2 * d + 3 * d / 4, (h - d) / 2, d, d);
		}
		

		private Color RGB( int r, int g, int b)
		{
			return Color.FromArgb( r, g, b );
		}

		public void TurnOn( int nLight )
		{
			if( nLight == 1 )
			{
				RedLight.FillColor = RGB(255, 0, 0);
			}
			else
			{
				RedLight.FillColor = RGB(127, 0, 0);
			}
			if( nLight == 2 )
			{
				YellowLight.FillColor = RGB(255, 255, 0);
			}
			else
			{
				YellowLight.FillColor = RGB(127, 127, 0);
			}
			if( nLight == 3 )
			{
				GreenLight.FillColor = RGB(0, 255, 0);
			}
			else
			{
				GreenLight.FillColor = RGB(0, 127, 0);
			}
			if( nLight != curLightIndex )
			{
				nLight = curLightIndex  ;//置当前值
				//RaiseEvent( LightChanged  );//发出事件
			}
   
		}

		struct Light
		{
			int left, top, width, height;
			public Color FillColor;
			public void Move( int left, int top, int width, int height )
			{
				this.left = left;
				this.top = top;
				this.width = width;
				this.height = height;
			}
			public void Paint( Graphics g )
			{
				g.FillEllipse( new SolidBrush( this.FillColor ), 
					left, top, width, height );
				g.DrawEllipse( Pens.Black , 
					left, top, width, height );
			}
		}

		Light RedLight, YellowLight, GreenLight;

		public int CurLightIndex 
		{
			get
			{
				return curLightIndex;
			}
			set
			{
				curLightIndex = value;
			}
		}

		private int interval;
		public int Interval
		{
			set
			{
				this.interval = value;
			}
			get
			{
				return this.interval;
			}
		}

		public void StartLight()
		{
			if( this.curLightIndex < 0 ) 
				this.curLightIndex =0;
			this.timer1.Start();
		}

		private void InitLight()
		{
			this.timer1.Interval = 500;
			this.curLightIndex = 0;
			StartLight();
		}

		private void TrafficLight_Load(object sender, System.EventArgs e)
		{
			InitLight();
		}

		private void timer1_Tick(object sender, System.EventArgs e)
		{
			int nLight = curLightIndex + 1;
			if( nLight >= 4 ) nLight = 1;
			TurnOn( nLight );
			curLightIndex = nLight;
			this.Invalidate();
		}

	}
}
