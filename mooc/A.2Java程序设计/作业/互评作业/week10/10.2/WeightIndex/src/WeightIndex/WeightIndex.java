package WeightIndex;

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
	private JRadioButton ChinaRadio;
	private JRadioButton AsiaRadio;
	private JRadioButton WHORadio;
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
		setTitle("�������ָ��������v1.0");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		//������
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);
		//���⣬��������
		titleLabel = new JLabel("�������ָ��������");
		titleLabel.setHorizontalAlignment(SwingConstants.CENTER);
		contentPane.add(titleLabel, BorderLayout.NORTH);
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
		ChinaRadio = new JRadioButton("�й���׼");
		ChinaRadio.setSelected(true);
		AsiaRadio = new JRadioButton("���ޱ�׼");
		WHORadio = new JRadioButton("WHO������������֯����׼");
		bg.add(ChinaRadio);
		bg.add(AsiaRadio);
		bg.add(WHORadio);
		sexPanel.add(ChinaRadio);
		sexPanel.add(AsiaRadio);
		sexPanel.add(WHORadio);
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
				Pattern pattern = Pattern.compile("^[0-9]+(.[0-9]+)?$"); 
				Matcher hisNum = pattern.matcher(hstr);
				Matcher wisNum = pattern.matcher(wstr);
				boolean acc = true;
				if( !hisNum.matches()|| !wisNum.matches()){
				       acc = false; 
				} 
				if(acc)
				{
					height = Double.parseDouble(hstr);
					weight = Double.parseDouble(wstr);
					BMI = weight / (height*height);
					DecimalFormat df = new DecimalFormat("#.0");
					String out = "";
					if(ChinaRadio.isSelected())
					{
						if(BMI<18.5)
							out = "ƫ�ݣ��ݹ���᾵ģ���Ե�ɣ�";
						else if(BMI<23.9)
							out = "�����������գ�";
						else if(BMI<28)
							out = "ƫ�֣���������˶����ʣ�";
						else if(BMI>=28)
							out = "���֣����ڼ������ļ���";
						else
							out ="��������������Ŷ�����������룡";
					}
					else if(AsiaRadio.isSelected())
					{
						if(BMI<18.5)
							out = "ƫ�ݣ��ݹ���᾵ģ���Ե�ɣ�";
						else if(BMI<22.9)
							out = "�����������գ�";
						else if(BMI<24.9)
							out = "ƫ�֣���������˶����ʣ�";
						else if(BMI<30)
							out = "���֣����ڼ������ļ���";
						else if(BMI>=30)
							out = "�ضȷ��֣�����һ���ˣ��Ͻ����ʰɣ�";
						else
							out ="��������������Ŷ�����������룡";
					}
					else
					{
						if(BMI<18.5)
							out = "ƫ�ݣ��ݹ���᾵ģ���Ե�ɣ�";
						else if(BMI<24.9)
							out = "�����������գ�";
						else if(BMI<29.9)
							out = "ƫ�֣���������˶����ʣ�";
						else if(BMI<34.9)
							out = "���֣����ڼ������ļ���";
						else if(BMI<39.9)
							out = "�ضȷ��֣�����һ���ˣ��Ͻ����ʰɣ�";
						else if(BMI>=40)
							out = "���ضȷ���,�ǿ��ܵ�ȥҽԺ��������";
						else
							out ="��������������Ŷ�����������룡";
					}
					
					consoleText.setText("���ָ��Ϊ��"+df.format(BMI)+"����Ľ���״��Ϊ��"+out);
				}
				
			}
		});
	}

}
