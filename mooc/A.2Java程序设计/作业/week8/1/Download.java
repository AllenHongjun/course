package homework;
 
import java.net.URL;
import java.security.KeyStore.TrustedCertificateEntry;
import java.io.*;
 
/*
 * 要做四个线程来进行下载，下载开始前调用date方法，下载结束后调用date方法，并输出两次调用所得的时间差
 * 在run方法里实现下载。多线程同时启动的话就要新建四个实现类,每个run方法传入的参数中有一个数组中的网址
 */
 
/**
 * @author PureWine
 * @version 创建时间：2018年5月12日 下午7:44:58
 */
 
public class Download {
 
    public static void main(String[] args) throws Exception {
        // TODO Auto-generated method stub
        final URL[] urls = { new URL("http://www.pku.edu.cn"), new URL("http://www.baidu.com"),
                new URL("http://www.sina.com.cn"), new URL("http://www.dstang.com") };
        final String[] files = { "pku.htm", "baidu.htm", "sina.htm", "study.htm", };
         
        //构造四个线程，每个线程里面传入一个网址和名字，然后启动以下载
        Thread t1 = new Thread(new download1(urls[0], files[0]));
        Thread t2 = new Thread(new download1(urls[1], files[1]));
        Thread t3 = new Thread(new download1(urls[2], files[2]));
        Thread t4 = new Thread(new download1(urls[3], files[3]));
         
        t1.start();
        t2.start();
        t3.start();
        t4.start();
 
    }
 
}
//定义一个继承Runnable接口的方法
class download1 implements Runnable {
 
    private URL download1;
 
    private String fileName;
 
    // 有参构造器
    public download1(URL download1, String fileName) {
        this.download1 = download1;
        this.fileName = fileName;
    }
 
    public void run() {
         
        try {
            if((download1!=null)&&(fileName!=null)) {
                download(download1, fileName);
            }
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
 
    static void download(URL url, String file) throws IOException {
        try (InputStream input = url.openStream(); OutputStream output = new FileOutputStream(file)) {
            byte[] data = new byte[1024];
            int length;
            while ((length = input.read(data)) != -1) {
                output.write(data, 0, length);
            }
        }
    }
}