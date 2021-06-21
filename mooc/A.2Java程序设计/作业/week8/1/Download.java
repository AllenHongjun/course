package homework;
 
import java.net.URL;
import java.security.KeyStore.TrustedCertificateEntry;
import java.io.*;
 
/*
 * Ҫ���ĸ��߳����������أ����ؿ�ʼǰ����date���������ؽ��������date��������������ε������õ�ʱ���
 * ��run������ʵ�����ء����߳�ͬʱ�����Ļ���Ҫ�½��ĸ�ʵ����,ÿ��run��������Ĳ�������һ�������е���ַ
 */
 
/**
 * @author PureWine
 * @version ����ʱ�䣺2018��5��12�� ����7:44:58
 */
 
public class Download {
 
    public static void main(String[] args) throws Exception {
        // TODO Auto-generated method stub
        final URL[] urls = { new URL("http://www.pku.edu.cn"), new URL("http://www.baidu.com"),
                new URL("http://www.sina.com.cn"), new URL("http://www.dstang.com") };
        final String[] files = { "pku.htm", "baidu.htm", "sina.htm", "study.htm", };
         
        //�����ĸ��̣߳�ÿ���߳����洫��һ����ַ�����֣�Ȼ������������
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
//����һ���̳�Runnable�ӿڵķ���
class download1 implements Runnable {
 
    private URL download1;
 
    private String fileName;
 
    // �вι�����
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