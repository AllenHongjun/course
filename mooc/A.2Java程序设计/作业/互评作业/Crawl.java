import java.io.*;

import java.net.*;

import java.util.regex.*;

import java.util.*;



public class Crawl

{

 public static String getContentFromUrl( String strUrl )

 {

 try { 

 URL url = new URL(strUrl);  

 InputStream stream = url.openStream();

 String content = readAll( stream,"UTF-8" ); //�����ı������ GB2312, UTF-8

 return content;

 }catch ( MalformedURLException e) { 

 System.out.println("URL��ʽ�д�" ); 

 }catch (IOException ioe) {

 System.out.println("IO�쳣" ); 

 }

 return "";

 }

 public static String readAll( InputStream stream, String charcode ) throws IOException

 {

 BufferedReader reader = new BufferedReader(

 new InputStreamReader(stream, charcode)); 

 StringBuilder sb = new StringBuilder();

 String line; 

 while ((line = reader.readLine()) != null) { 

 sb.append(line+"\n"); 

 } 

 return sb.toString();

 }

  static Set<String> RegexString(String target, String patternString) 

 {

 Set<String> set = new HashSet<String>();

 Pattern pattern = Pattern.compile(patternString);

 Matcher matcher = pattern.matcher(target);

 while (matcher.find()) 

 {

 set.add(matcher.group());

 }

 return set;  

 	}

 // 主函数测�?

 	public static void main(String[] args) 

 {

 // 测试网址

 String[] urls = {

 "http://www.pku.edu.cn",

 "http://www.sina.com.cn",

 "http://www.dstang.com",

 "http://www.baidu.com"

 };

 String[] urlContent = new String[urls.length];  

 List webNet = new Vector< Set<String> >();  


 for(int i = 0 ; i < urls.length; i++){

 final int idx = i;

 new Thread( ()-> {

 try{

 System.out.println( urls[idx] );

 urlContent[idx] = getContentFromUrl(urls[idx]);

 //Set<String> set = RegexString(urlContent[idx], "[a-zA-Z0-9_-]+@[a-z0-9]+(\\.[a-z0-9]+)+");

 Set<String> set = RegexString(urlContent[idx], "\\s*(href|src)\\s*=\\s*(\"([^\"]*\")|(\'[^\']*\')|([^\'\">\\s]+))");

 System.out.println(urls[idx] + "����������վ:");

 if(!set.isEmpty())

 {

 for( Iterator it = set.iterator();  it.hasNext(); )

 {

 System.out.println(it.next());

 }

 }

 else 

 {

 System.out.println("��");

 }

 System.out.println();

 webNet.add(set);   //��ӽ�����

 }catch(Exception ex){

 ex.printStackTrace();

 }

 }).start();

 }

 	}

}

