try
{
	net.xml_webservices.www.clock clock1 = 
		new net.xml_webservices.www.clock();
	DateTime nowX = clock1.GetUTC_Time( );
	Console.WriteLine( nowX );
}
catch(Exception e )
{
	Console.WriteLine(e );
}
// 该服务来自于:
//  http://www.xml-webservices.net/services/time_server/clock.asmx