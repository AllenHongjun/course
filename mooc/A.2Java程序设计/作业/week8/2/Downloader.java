import java.net.URL;  
import java.io.*;  
    
public class Downloader extends Thread{  
       
    String file;  
    URL url;  
       
    public Downloader(URL url, String file){  
        this.url=url;  
        this.file=file;  
    }  
       
   
    public void run(){  
        java.io.InputStream input = null ;  
        java.io.OutputStream output = null ;  
        try{  
            input =  url.openStream();  
            output = new FileOutputStream(file);  
            byte[] data = new byte[1024];  
            int length;  
            try {  
                while((length=input.read(data))!=-1){  
                        output.write(data,0,length);  
                }   
            }catch (IOException e1) {  
                e1.printStackTrace();  
            }  
        }catch(IOException e1){  
            e1.printStackTrace();  
        }  
   
    }  
   
   
public static void main(String[] args) throws Exception  {  
                   
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
       
            Thread t1=new Thread(new Downloader(urls[0],files[0]));  
            t1.start();  
               
            Thread t2=new Thread(new Downloader(urls[1],files[1]));  
            t2.start();  
               
            Thread t3=new Thread(new Downloader(urls[2],files[2]));  
            t3.start();  
               
            Thread t4=new Thread(new Downloader(urls[3],files[3]));  
            t4.start();  
   
       
    }  
}