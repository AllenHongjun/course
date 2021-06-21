package org.icourse163.java;
 
import java.net.URL;
import java.util.Date;
import java.io.*;
  
class Downloader 
{
    public static void main(String[] args) throws Exception
    {
        final URL[] urls = {
            new URL("https://www.pku.edu.cn"),
            new URL("https://www.baidu.com"),
            new URL("https://www.sina.com.cn"),
            new URL("https://www.dstang.com")
        };
        final String[] files = {
            "pku.htm", 
            "baidu.htm",
            "sina.htm", 
            "study.htm",
        };
        Thread[] download= new Thread[urls.length];
        long time = 0;
        for(int idx=0; idx<urls.length; idx++){
            URL urls1=urls[idx];
            String files1=files[idx];
            Thread t= new Thread() {
                public void run() {
                    try{
                        System.out.println(urls1);
                        download( urls1, files1);
                    }catch(Exception ex){
                        ex.printStackTrace();
                    }
                }
            };
            if(idx==0) {
                time=new Date().getTime();
            }
            t.start();
            download[idx]=t;
        }
        while(!download[urls.length-1].isAlive()) {
            time=new Date().getTime()-time;
            double time2=Math.floor(time/1000);
            System.out.println("下载总用时间："+time2);
        }
         
    }
    static void download( URL url, String file) throws IOException
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