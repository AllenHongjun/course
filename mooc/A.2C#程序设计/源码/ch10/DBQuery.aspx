<%@ Page language="c#" Codebehind="WebFormDBQuery.aspx.cs" AutoEventWireup="false" Inherits="WebApplication1.WebFormDBQuery" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>WebFormDBQuery</title>
		<meta name="GENERATOR" Content="Microsoft Visual Studio 7.0">
		<meta name="CODE_LANGUAGE" Content="C#">
		<meta name="vs_defaultClientScript" content="JavaScript">
		<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form id="WebFormDBQuery" method="post" runat="server">
			<FONT face="宋体">
				<asp:DataGrid id="DataGrid1" style="Z-INDEX: 101; LEFT: 80px; POSITION: absolute; TOP: 87px" runat="server" Width="499px" Height="290px" Font-Size="9pt" BorderColor="#999999" BorderStyle="None" BorderWidth="1px" BackColor="White" CellPadding="3" GridLines="Vertical">
					<SelectedItemStyle Font-Bold="True" ForeColor="White" BackColor="#008A8C"></SelectedItemStyle>
					<AlternatingItemStyle BackColor="#DCDCDC"></AlternatingItemStyle>
					<ItemStyle ForeColor="Black" BackColor="#EEEEEE"></ItemStyle>
					<HeaderStyle Font-Bold="True" ForeColor="White" BackColor="#000084"></HeaderStyle>
					<FooterStyle ForeColor="Black" BackColor="#CCCCCC"></FooterStyle>
					<PagerStyle HorizontalAlign="Center" ForeColor="Black" BackColor="#999999" Mode="NumericPages"></PagerStyle>
				</asp:DataGrid>
				<asp:TextBox id="TextBox1" style="Z-INDEX: 102; LEFT: 221px; POSITION: absolute; TOP: 42px" runat="server"></asp:TextBox>
				<asp:Button id="Button1" style="Z-INDEX: 103; LEFT: 444px; POSITION: absolute; TOP: 41px" runat="server" Text="查询"></asp:Button>
				<asp:Label id="Label1" style="Z-INDEX: 104; LEFT: 81px; POSITION: absolute; TOP: 45px" runat="server" Width="117px" Height="23px">出版社名</asp:Label></FONT>
		</form>
	</body>
</HTML>
