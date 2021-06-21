import java.net.URL;
import java.io.*;
import java.util.Date; 
class Downloader extends Thread
{
    private URL url;
    private String file;
    public Downloader(URL url, String file) {
        this.url = url;
        this.file = file;
    }
    public void run() {
        System.out.println( "Downloading " + url + "/" + file );
        try(InputStream input = url.openStream();
            OutputStream output = new FileOutputStream(file))
        {
            byte[] data = new byte[1024];
            int length;
            while((length=input.read(data))!=-1){
                output.write(data,0,length);
            }
        } catch(Exception ex) {
            ex.printStackTrace();
        } finally {
            System.out.println("Downloading thread " + this.getName() + " has quit");
        }
    }
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
  
        long beginTime = new Date().getTime();
        Downloader[] downloaders = new Downloader[urls.length];
        for(int i = 0; i < urls.length; i++){
            try{
                downloaders[i] = new Downloader(urls[i], files[i]);
                downloaders[i].start();
            }catch(Exception ex){
                ex.printStackTrace();
            }
        }
         
        // 在这里同步线程，主线程只有在所有下载线程都结束后才会计算下载所用时间
        for (int i = 0; i < urls.length; ++i) {
            downloaders[i].join();
        }
        long endTime = new Date().getTime();
        System.out.println("Total time elapsed: " + (endTime - beginTime) + "ms");
    }
}