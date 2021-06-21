package thread;

import java.net.MalformedURLException;
import java.net.URL;

public class main {
  public static void main(String[] args) throws Exception  {
	  //网页地址
	  final URL[] urls = {
	            new URL("https://www.pku.edu.cn"),
	            new URL("https://www.baidu.com"),
	            new URL("https://www.sina.com.cn"),
	            new URL("https://www.dstang.com")
	        };
	 //文件名
	 final String[] fileNames = {
	            "pku.htm", 
	            "baidu.htm",
	            "sina.htm", 
	            "study.htm",
	        };
	//通过循环启动不同URL下载
	for (int i = 0; i < 1; i++) {
		 DownLoadthread downloadthread=new DownLoadthread(urls[i], fileNames[i]);
		 downloadthread.start();
	}
  }
}
