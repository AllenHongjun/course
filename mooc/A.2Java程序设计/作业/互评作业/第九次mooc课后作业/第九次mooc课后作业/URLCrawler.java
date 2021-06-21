package 第九次mooc课后作业;

import javax.swing.*;
import java.awt.*;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.io.*;
import java.util.*;
import java.util.List;
import java.util.concurrent.*;
import java.util.regex.*;
import java.nio.charset.*;

public class URLCrawler extends JFrame {

    static ConcurrentLinkedQueue<String> downloaded =
            new ConcurrentLinkedQueue<>();    //记录已经下载的网页，避免循环下载
    TextArea textArea = new TextArea("downloading:\n");

    public static void main(String[] args) {
        URLCrawler c = new URLCrawler();
        try {
            c.Crawl();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
    
    URLCrawler() {
        super("Download Content");
        setSize(800, 600);
        getContentPane().setLayout(new BorderLayout());
        getContentPane().add(BorderLayout.CENTER, textArea);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void Crawl() throws Exception {

        ConcurrentLinkedQueue<String> urls =
                new ConcurrentLinkedQueue<>();
        urls.add("http://www.baidu.com");
        urls.add("http://pku.edu.cn");
        int cnt = 0;
        while (!urls.isEmpty()) {
            String url = urls.poll();
            System.out.println(url);
            new Thread(() -> {
                try {
                    String charset = getEncodingByHeader(url);
                    if (!downloaded.contains(url)) {  //防止重复下载
                        String content = download(
                                new URL(url), charset);

                        showEmails(content);  // 展示抓取的邮箱

                        // 图形化界面，展示下载得到的东西
                        SwingUtilities.invokeLater(() -> {
                            textArea.append(content);
                        });
                        downloaded.add(url);
                        List<String> moreUrl = parse(content);
                        urls.addAll(moreUrl);
                    }
                    //System.out.println(moreUrl);
                } catch (Exception ex) {
                    ex.printStackTrace();
                }
            }).start();

            if (cnt++ > 5) break;
            try {
                Thread.sleep(4000);
            } catch (InterruptedException ex) {
            }
        }
    }

    // 抓取其中的邮箱地址，并显示
    private static void showEmails(String content) {
        String regex = "[a-zA-Z0-9_-]+@\\w+\\.[a-z]+(\\.[a-z]+)?";
        Pattern p = Pattern.compile(regex);
        Matcher m = p.matcher(content);
        while (m.find()) {
            System.out.println(m.group());
        }
    }

    // 猜测网页的编码（charset）
    private static String getEncodingByHeader(String str) {
        String strencoding = null;
        HttpURLConnection httpConn = null;
        try {
            URL url = new URL(str);
            httpConn = (HttpURLConnection) url.openConnection();
            httpConn.setRequestProperty("User-agent", "Mozilla/4.0");
            Map<String, List<String>> map = httpConn.getHeaderFields();

            Set<String> keys = map.keySet();
            Iterator<String> iterator = keys.iterator();

            // 遍历,查找字符编码
            String key = null;
            String tmp = null;
            while (iterator.hasNext()) {
                key = iterator.next();
                tmp = map.get(key).toString().toLowerCase();
                // 获取content-type charset
                if (key != null && key.equals("Content-Type")) {
                    int m = tmp.indexOf("charset=");
                    if (m != -1) {
                        strencoding = tmp.substring(m + 8).replace("]", "");
                        return strencoding;
                    }
                }
            }
        } catch (IOException e) {
            strencoding = null;
        } finally {
            try {
                if (httpConn != null)
                    httpConn.disconnect();
            } catch (Exception ex) {
                System.out.println(ex);
            } finally {
                if (strencoding == null) {
                    strencoding = "gb2312";  // 程序中默认的编码方式，
                    // 如果无法解码则认为是gb2312
                }
            }
        }
        return strencoding;
    }

    static List<String> parse(String text) {
        String patternString =
                "\\s*href\\s*=\\s*(\"([^\"]*\")|(\'[^\']*\')|([^\'\">\\s]+))\\s*";
        Pattern pattern = Pattern.compile(patternString,
                Pattern.CASE_INSENSITIVE);  //  Pattern.MULTILINE
        Matcher matcher = pattern.matcher(text);
        List<String> list = new ArrayList<>();
        while (matcher.find()) {
            String href = matcher.group(1);
            href = href.replaceAll("\'", "").replaceAll("\"", "");
            if (href.startsWith("http:"))
                list.add(href);
        }
        return list;
    }

    static String download(URL url, String charset)
            throws Exception {
        try (InputStream input
                     = url.openStream();
             ByteArrayOutputStream output
                     = new ByteArrayOutputStream()) {
            byte[] data = new byte[1024];
            int length;
            while ((length = input.read(data)) != -1) {
                output.write(data, 0, length);
            }
            byte[] content = output.toByteArray();
            return new String(content, Charset.forName(charset));
        }
    }

}
