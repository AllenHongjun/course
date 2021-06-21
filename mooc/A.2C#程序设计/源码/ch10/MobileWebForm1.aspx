<%@ Page language="c#" Codebehind="MobileWebForm1.aspx.cs" Inherits="MobileWebApplication1.MobileWebForm1" AutoEventWireup="false" %>
<%@ Register TagPrefix="mobile" Namespace="System.Web.UI.MobileControls" Assembly="System.Web.Mobile, Version=1.0.3300.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a" %>
<meta content="Microsoft Visual Studio 7.0" name="GENERATOR">
<meta content="C#" name="CODE_LANGUAGE">
<meta content="http://schemas.microsoft.com/Mobile/Page" name="vs_targetSchema">
<body Xmlns:mobile="http://schemas.microsoft.com/Mobile/WebForm">
	<mobile:form id="Form1" runat="server">
		<FONT face="宋体">
			<mobile:Label id="Label1" runat="server">金额</mobile:Label>
			<mobile:TextBox id="TextBox1" runat="server" Numeric="True"></mobile:TextBox>
			<mobile:Command id="Command1" runat="server">继续</mobile:Command>
		</FONT>
	</mobile:form>
	<FONT face="宋体">
		<mobile:form id="Form2" runat="server">
			<mobile:Label id="Label2" runat="server">种类</mobile:Label>
			<mobile:SelectionList id="SelectionList1" runat="server"></mobile:SelectionList>
			<mobile:Command id="Command2" runat="server">进行换算</mobile:Command>
		</mobile:form>
		<mobile:form id="Form3" runat="server">
			<mobile:Label id="label3" runat="server">结果</mobile:Label>
			<mobile:Link id="Link1" runat="server" NavigateUrl="#Form1">重新开始</mobile:Link>
		</mobile:form>
	</FONT>
</body>
