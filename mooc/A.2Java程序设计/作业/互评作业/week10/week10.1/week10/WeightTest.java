package week10;

import java.awt.Button;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class WeightTest {
	
	private Frame f;
	private Button but;
	private TextField tf;
	
	
	public WeightTest() {
		init();
	}


	private void init() {
		f=new Frame("����ָ��������");
		f.setBounds(500,200,300,440);
		f.setLayout(new FlowLayout());
		
		tf=new TextField(15);
		but=new Button("��ť");
		f.add(but);
		f.add(tf);
		
		myEvent();
		f.setVisible(true);
	}


	private void myEvent() {
		tf.addKeyListener(new KeyAdapter() {

			@Override
			public void keyPressed(KeyEvent e) {
//				System.out.println("key run"+e.getKeyChar()+KeyEvent.getKeyText(e.getKeyCode()));
//				int code=e.getKeyCode();
//				if(!(code>=KeyEvent.VK_0&&code<=KeyEvent.VK_9))
//					System.out.println("����������");
//					e.consume();//���ı�����ֻ����������
//			}
			
			}});
		
		f.addWindowListener(new WindowAdapter() {

			@Override
			public void windowClosing(WindowEvent arg0) {
				// TODO Auto-generated method stub
				System.exit(0);
			}
			
		});
		//��ť����
		but.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				System.out.println("action run");
			}
		});
		//�ڰ�ť�����һ����������
		but.addMouseListener(new MouseAdapter() {
			private int count=1;
			@Override
			//mouseentered���ֻ���ڰ�ť�Ͼʹ�����
			public void mouseEntered(MouseEvent arg0) {
//				System.out.println("mouse enter"+count++);
//				tf.setText("mouse run"+count++);
				}
			@Override
			//����
			public void mouseClicked(MouseEvent e) {
				if(e.getClickCount()==2)
					tf.setText("click"+count++);
			}
			
			
		});
	}


	public static void main(String[] args) {
		new WeightTest();
	}

}
