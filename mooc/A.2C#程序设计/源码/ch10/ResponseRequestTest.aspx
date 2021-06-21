<%@ Page language="c#"%>
<html>
<body>
这里是一个简单的ASP.NET文件。

<form method=post>
<p>请输入你要显示的数字的个数 
<input type=text name=num>
<input type=submit>
</form>
<p>
<%
string sn = Request["num"];
int n = 0;
try
{
	n = int.Parse( sn );
}catch{}

for( int i=0; i<n; i++ )
	Response.Write( i + " " );
%>

</body>
</html>
