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
                Thread thread=new Thread(s);//�½��̶߳��󣬴���Runnable�����ʼ��
                thread.start();//�����߳�
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
class Download implements Runnable//дһ��Download�����̳�Runnable�ӿ�
{
     private URL url;
     String file;
     public Download (URL url,String file)//���캯���д�һ��Runnable����
     {
          this.url=url;
          this.file=file;
     }
     public void run()//��дrun����
     {
          try {
           Downloader.download(url,file);
          } catch (IOException e) {
           // TODO Auto-generated catch block
           e.printStackTrace();
          }
     }
}