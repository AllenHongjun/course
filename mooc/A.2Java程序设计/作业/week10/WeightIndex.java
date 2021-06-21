 
  
import javax.swing.*;  
import javax.swing.border.EmptyBorder;  
  
import java.awt.*;  
import java.awt.event.*;  
import java.text.DecimalFormat;  
import java.util.regex.*;  
  
  
public class WeightIndex extends JFrame {  
  
    /** 
     *  
     */  
    private static final long serialVersionUID = 1L;  
    private JPanel contentPane;  
    private JLabel titleLabel;  
    private JPanel contentPanel;  
    private JButton submitButton;  
    private ButtonGroup bg;  
    private JPanel sexPanel;  

    private JPanel whPanel;  
    private JLabel heightLabel;  
    private JLabel weightLabel;  
    private JTextField heightText;  
    private JTextField weightText;  
    private JPanel consolePanel;  
    private JLabel consoleLabel;  
    private JTextField consoleText;  
      
    private double weight;  
    private double height;  
    private double BMI;  
      
    /** 
     * Launch the application. 
     */  
    public static void main(String[] args) {  
        EventQueue.invokeLater(new Runnable() {  
            public void run() {  
                try {  
                    WeightIndex frame = new WeightIndex();  
                    frame.pack();  
                    frame.setVisible(true);  
                } catch (Exception e) {  
                    e.printStackTrace();  
                }  
            }  
        });  
    }  
  
    /** 
     * Create the frame. 
     */  
    public WeightIndex() {  
        setTitle("�������ָ��������");  
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
        setBounds(100, 100, 450, 300);  
        //������  
        contentPane = new JPanel();  
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));  
        contentPane.setLayout(new BorderLayout(0, 0));  
        setContentPane(contentPane);  
        
        //���ѡ���panel����������  
        contentPanel = new JPanel();  
        contentPanel.setLayout(new BorderLayout());  
        contentPane.add(contentPanel,BorderLayout.CENTER);  
        //�ύ��ť����������  
        submitButton = new JButton("����");  
        contentPane.add(submitButton, BorderLayout.SOUTH);  
          
        //����Ա�ѡ���panel��ѡ�  
        bg = new ButtonGroup();  
        sexPanel = new JPanel();  
        sexPanel.setLayout(new FlowLayout());  
        contentPanel.add(sexPanel,BorderLayout.NORTH);  
      
        //���������ص�panel��ѡ����  
        whPanel = new JPanel();  
        whPanel.setLayout(new FlowLayout());  
        contentPanel.add(whPanel,BorderLayout.CENTER);  
        heightLabel = new JLabel("��ߣ���/m����");  
        weightLabel = new JLabel("���أ�ǧ��/kg����");  
        heightText = new JTextField(10);  
        heightText.setToolTipText("���������");  
        weightText = new JTextField(10);  
        weightText.setToolTipText("����������");  
        whPanel.add(heightLabel);  
        whPanel.add(heightText);  
        whPanel.add(weightLabel);  
        whPanel.add(weightText);  
        //���  
        consolePanel = new JPanel();  
        consolePanel.setLayout(new FlowLayout());  
        consoleLabel = new JLabel("�����������ָ��Ϊ��");  
        consoleText = new JTextField(28);  
        consoleText.setEditable(false);  
        consolePanel.add(consoleLabel);  
        consolePanel.add(consoleText);  
        contentPanel.add(consolePanel,BorderLayout.SOUTH);  
          
        submitButton.addActionListener(new ActionListener(){  
            public void actionPerformed(ActionEvent e) {
				String hstr = heightText.getText();  
                String wstr = weightText.getText();
				height = Double.parseDouble(hstr);  
				weight = Double.parseDouble(wstr);  
				BMI = weight / (height*height);  
				DecimalFormat df = new DecimalFormat("#.0");  
				String out = "";
				if(BMI<18.5)  
					out = "ƫ�ݣ�";  
				else if(BMI<23.9)  
					out = "�����������գ�";  
				else if(BMI<28)  
					out = "ƫ�֣�";  
				else if(BMI>=28)  
					out = "���֣�";  
				else  
					out ="���������룡"; 

				consoleText.setText("���ָ��Ϊ��"+df.format(BMI)+"����Ľ���״��Ϊ��"+out);  

				

				
            }  
        });  
    }  
  
}  