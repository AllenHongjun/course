import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.List;
import java.io.*; 
import java.util.ArrayList;
 
public class Mianban extends JFrame implements ActionListener{
 JLabel lblWord = new JLabel("word"); 
 JLabel lblMeaning = new JLabel("meaning");
 List<String> words = new ArrayList<>();
 List<String> meanings = new ArrayList<>();
 int current = 0;
 public void start() {
  new Thread(()->{
   try{
    readAll();
   }catch(IOException ex){}
   new javax.swing.Timer(3000,(e)->{
    lblWord.setText( words.get(current) );
    lblMeaning.setText( meanings.get(current) );
    current++;
   }).start();
  }).start();
 }
 public void readAll( ) throws IOException{
  String fileName = "College_Grade4.txt";
  String charset = "GB2312";
  BufferedReader reader = new BufferedReader(
   new InputStreamReader(
    new FileInputStream(fileName), charset)); 
  String line; 
  while ((line = reader.readLine()) != null) { 
   line = line.trim();
   if( line.length() == 0 ) continue;
   int idx = line.indexOf("\t");
   words.add( line.substring(0, idx ));
   meanings.add( line.substring(idx+1));
    
  } 
  reader.close();
 }
  
  
  
 JFrame jf=new JFrame("单词助手");
 Panel p1,p2,p3,p4;
 JPanel card=new JPanel();
 Font ft=new Font("楷体",Font.BOLD,18);
 CardLayout cl=new CardLayout();
 public Mianban() {  
  p4=new Panel();
  p4.setLayout(new GridLayout(2,1));
  p3=new Panel();
  p2=new Panel();
  card.setLayout(cl);  
   
  p2.setLayout(new GridLayout(3,1));
  jf.add(p2);
  Label L1=new Label("欢迎来到单词助手！");
  L1.setFont(ft);
  p2.add(L1,"CENTER");
  L1.setAlignment(1);
   
  Button b3,b4,b5;
   
  p3.setLayout(new GridLayout(1,2));
  p4.add(p3);
  p3.add(lblWord);
  p3.add(lblMeaning);
   
   
  p1=new Panel();
  p1.setLayout(new GridLayout(1,3));
  p4.add(p1);
   
  b3=new Button("返回");
  b4=new Button("加入生词本");
  b5=new Button("生词本");
   
  p1.add(b3);
  b3.addActionListener(new ActionListener() {
   public void actionPerformed(ActionEvent e) {
    cl.first(card);
   }
  });;
  p1.add(b4);
  b4.addActionListener(new ActionListener() {
   public void actionPerformed(ActionEvent e) {
   }
  });
  p1.add(b5);
  b5.addActionListener(new ActionListener() {
   public void actionPerformed(ActionEvent e) {
   }
  });
   
  Button b1=new Button("开始");
  b1.setFont(ft);
  p2.add(b1);
  b1.addActionListener(new ActionListener() {
   public void actionPerformed(ActionEvent e) {
    cl.next(card);
    start();
     
   }
  });
   
  Button b2=new Button("退出");
  b2.setFont(ft);
  p2.add(b2);
  b2.addActionListener(new ActionListener() {//关闭程序
   public void actionPerformed(ActionEvent e) {
    System.exit(0);
   }
  });
  jf.add(card);
  card.add("1",p2);
  card.add("2",p4);  
   
   
   
  jf.addWindowListener(new WinClose());
  jf.setSize(500, 300);
  jf.setVisible(true);
   
   
 }
 public void actionPerformed(ActionEvent e) {
   
 }
 class WinClose extends WindowAdapter{
  public void windowClosing(WindowEvent e){
   System.exit(0);
  }
 }
 public static void main(String[] args) { 
  Mianban m=new Mianban();
   
 }
  
}