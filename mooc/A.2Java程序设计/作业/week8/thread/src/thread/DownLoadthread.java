package thread;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.URL;

/*
 * 执行下载线程
 */
public class DownLoadthread extends Thread{

	private  URL url;
	private String fileName;
	public DownLoadthread(URL url, String fileName) {
		super();
		this.url = url;
		this.fileName = fileName;
	}

	@Override
	public void run() {
		try {
			//建立从网页获取的输入流
			InputStream input=url.openStream();
			//建立向文件中写入数据
			OutputStream output=new FileOutputStream(fileName);
			//定义一个字符数组保存输入的值
			byte[] datas=new byte[1024];
			int length=0;
			while((length=input.read(datas))!=-1) {//读取数据到数组
			//文件中写入数据
			output.write(datas, 0, length);
			}
			input.close();
			output.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
           
}
