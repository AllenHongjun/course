public delegate void EventHandler(object sender, EventArgs e);  //声明指代

public class EventArgs
{
	//object data;
}

public class Control
{
	//....
}

public class Button: Control
{
	public event EventHandler Click;  // 声明事件
	protected virtual void OnClick(EventArgs e) 
	{
		if (Click != null) Click(this, e); //调用事件
	}
	public void Reset() 
	{
		Click = null;
	}
	public Button( string s )
	{
		//....
	}
}

public class Form
{
	//......
}
public class LoginDialog: Form
{
	Button OkButton;
	Button CancelButton;
	public LoginDialog() 
	{
		OkButton = new Button( "ok" );
		OkButton.Click += new EventHandler(OkButton_Click);//注册事件
		CancelButton = new Button( "cancel" );
		CancelButton.Click += new EventHandler(CancelButton_Click);
	}
	void OkButton_Click(object sender, EventArgs e) 
	{
		// Handle OkButton.Click event  ......
	}
	void CancelButton_Click(object sender, EventArgs e) 
	{
		// Handle CancelButton.Click event  ......
	}
}

class Test
{
	static void Main()
	{
	}
}
