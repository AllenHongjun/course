import java.net.URL;
import java.io.*;
  
public class Downloader 
{
 public static long time1;
    public static void main(String[] args)
        throws Exception
    {
        final URL[] urls = {
            new URL("http://www.pku.edu.cn"),
            new URL("http://www.baidu.com"),
            new URL("http://www.sina.com.cn"),
            new URL("http://www.dstang.com")
        };
        final String[] files = {
            "pku.htm", 
            "baidu.htm",
            "sina.htm", 
            "study.htm",
        };
        for(int idx=0; idx<urls.length; idx++){
            try{
                System.out.println( urls[idx] );
                Download s=new Download (urls[idx], files[idx]);
                Thread thread=new Thread(s);//新建线程对象，传递Runnable对象初始化
                thread.start();//启动线程
            }catch(Exception ex){
                ex.printStackTrace();
            }
        }
    }
    static void download( URL url, String file)
        throws IOException
    {
        try(InputStream input = url.openStream();
            OutputStream output = new FileOutputStream(file))
        {
            byte[] data = new byte[1024];
            int length;
            while((length=input.read(data))!=-1){
                output.write(data,0,length);
            }
        }
    }
}
class Download implements Runnable//写一个Download方法继承Runnable接口
{
     private URL url;
     String file;
     public Download (URL url,String file)//向构造函数中传一个Runnable对象
     {
          this.url=url;
          this.file=file;
     }
     public void run()//重写run方法
     {
          try {
           Downloader.download(url,file);
          } catch (IOException e) {
           // TODO Auto-generated catch block
           e.printStackTrace();
          }
     }
}