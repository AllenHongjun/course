import java.net.URL;
import java.io.*;
import java.util.*;
import java.text.*;
  
class Downloader 
{
    public static void main(String[] args)
        throws Exception
    {   
 
        Counter c1 = new Counter(1);
        Thread t1 = new Thread(c1);
        Thread t2 = new Thread(c1);
        Thread t3 = new Thread(c1);
         
        t1.start();
        t2.start();
        t3.start();
        TimeDisplay timer = new TimeDisplay();
        Thread t7 = new Thread(timer);
        t7.start();
 
    }
     
}
 
 
 
//¼ÆÊýÆ÷
class Counter implements Runnable {
    int id;
    Counter(int id){
        this.id = id;
    }
    public void run() {
        try{
            test();
        }catch(Exception ex){
                ex.printStackTrace();
        }
         
    }
     
 
    public void test() throws Exception{
     
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
                download( urls[idx], files[idx]);
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
 
  
class TimeDisplay implements Runnable {
    public void run(){
        System.out.println( 
                new Date().getTime());
            try{ Thread.sleep(40); } catch( InterruptedException e ){}
    }
}