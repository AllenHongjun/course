using System;
using System.Web;
using System.Web.Services;
namespace WebService1
{
	[ WebService(Description="Simple Web Services",Namespace="http://www.xxxx.com/")]
	public class Service1 : System.Web.Services.WebService
	{
		[WebMethod]
		public string HelloWorld(string name)
		{
			return "Hello "+name;
		}
	}
}
