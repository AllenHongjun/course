import java.io.*;
import java.net.URL;
import java.time.*;
 
public class Downloader
{
    public static void main( String[] args) throws Exception
    {
        final URL[] urls =
        {
            new URL( "http://www.pku.edu.cn"),
            new URL( "http://www.baidu.com"),
            new URL( "http://www.sina.com.cn"),
            new URL( "http://www.dstang.com")
        };
        final String[] files =
        {
            "pku.htm",
            "baidu.htm", 
            "sina.htm", 
            "study.htm"
        };
        final int len = urls.length;
         
        Thread[] threads = new Thread[ len ];
         
        for( int i = 0; i < len; ++i)
        {
            final int fi = i;
            threads[i] = new Thread( () ->
            {
                try
                {
                    System.out.println( urls[fi]);
                    download( urls[fi], files[fi]);
                }
                catch( IOException e)
                {
                    e.printStackTrace();
                }
            });
        }
         
        LocalTime beg = LocalTime.now();
 
        for( int i = 0; i < len; ++i)
            threads[i].run();
        for( int i = 0; i < len; ++i)
            while( threads[i].isAlive())
            {
                try
                {
                    threads[i].join();
                }
                catch( InterruptedException e) {}
            }
         
        LocalTime end = LocalTime.now();
        System.out.printf( "\nUsing %f ms\n", Duration.between( beg, end).getNano() / 1e6);
    }
 
    static void download( URL url, String file) throws IOException
    {
        try( InputStream input = url.openStream();
                OutputStream output = new FileOutputStream( file))
        {
            byte[] data = new byte[5*1024];
            int length;
            while( (length = input.read( data)) != -1)
            {
                output.write( data, 0, length);
            }
        }
    }
}