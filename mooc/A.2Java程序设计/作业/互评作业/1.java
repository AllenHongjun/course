import java.io.*; 

import java.awt.*;

import javax.swing.*;

import java.util.List;

import java.util.ArrayList;



public class Recite extends JFrame{ 

 private JPanel imagePanel;

 private ImageIcon background;

 JLabel lblWord = new JLabel("word"); 

 JLabel lblMeaning = new JLabel("meaning"); 

 public void init()

       { 

 background = new ImageIcon("R.jpg");/*背景图片*/

 JLabel label = new JLabel(background);

 label.setBounds(0,0,background.getIconWidth(),background.getIconHeight());

    imagePanel = (JPanel)this.getContentPane();

 imagePanel.setOpaque(false);

 imagePanel.setLayout(new FlowLayout());

 imagePanel.add(new JButton("选择"));

 this.getLayeredPane().setLayout(null);

 this.getLayeredPane().add(label,new Integer(Integer.MIN_VALUE));

 this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

 this.setSize(background.getIconWidth(),background.getIconHeight());

 this.setVisible(true);

     setSize( 400,400 );

 setLayout(new FlowLayout());

 getContentPane().add(lblWord);

 getContentPane().add(lblMeaning);

 setDefaultCloseOperation(EXIT_ON_CLOSE);

 setVisible(true);

 } 

 List<String> words = new ArrayList<>();

 List<String> meanings = new ArrayList<>();

 int current = 0;

 public void start() {

 new Thread(()->{

 try{

 readAll();

 }catch(IOException ex){}

 new javax.swing.Timer(1500,(e)->{/*改变单词的显示速度*/

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

 String path= "College_Grade4.txt";

 File file= new  File(path);

    String str;

    public ArrayList<String>  getfile() throws IOException {

        BufferedReader in=new BufferedReader(new InputStreamReader(new FileInputStream(file),"gbk")) ; 

        ArrayList<String> arr=new ArrayList<>();

        while((str=in.readLine())!=null){  

            arr.add(str.trim());       

        }

        in.close();

        return arr;

}


 public static void main( String[] args) throws IOException{

 Recite f = new Recite();

 f.init();

 f.start();

 Recite w=new Recite();

 ArrayList<String> arrayList=w.getfile();

        for(int i=0;i<arrayList.size();i++){

            System.out.println(arrayList.get(i));

        }

        

 }





} 