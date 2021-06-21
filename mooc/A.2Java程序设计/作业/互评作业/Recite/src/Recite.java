import java.awt.EventQueue;
import java.awt.FlowLayout;
import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.UIManager;
import javax.swing.JTextPane;
import javax.swing.JTextArea;
import java.awt.Color;
import javax.swing.JButton;
import javax.swing.SwingConstants;
import javax.swing.JPanel;
import javax.swing.JSpinner;
import javax.swing.JSeparator;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Choice;
import javax.swing.JToolBar;
import javax.swing.SpinnerModel;
import javax.swing.SpinnerNumberModel;
import javax.swing.JSplitPane;
import javax.swing.JLayeredPane;
import javax.swing.JRadioButton;
import javax.swing.event.ChangeListener;
import javax.swing.event.ChangeEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class Recite {

	private JFrame frame;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Recite window = new Recite();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public Recite() {
		initialize();
	}
	private final JLabel lblWord = new JLabel();
	private final JRadioButton radioButton0 = new JRadioButton("背");
	private final JRadioButton radioButton1 = new JRadioButton("练");
	private final JLabel label = new JLabel("间隔（秒）");
	private final JButton btnHard = new JButton("记住了");
	private final JButton btnOk = new JButton("会了");
	private final JSpinner spinner = new JSpinner();
	private final JLabel lblResult = new JLabel("");
	private JLabel[] Answers = new JLabel[4];
	private boolean testing =false;

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.getContentPane().setBackground(new Color(135, 206, 250));
		frame.setTitle("背单词加强版");
		frame.setResizable(false);
		frame.addWindowListener(new WindowAdapter() {
			@Override
			public void windowOpened(WindowEvent e) {
				start();
			}
			@Override
			public void windowClosing(WindowEvent e) {
				String statusFileName = this.getClass().getClassLoader().getResource("").getPath() + "word_status.txt";
				String charset = "GB2312";
				BufferedWriter writer = null;
				try {
					writer = new BufferedWriter(
							new OutputStreamWriter(
								new FileOutputStream(statusFileName),charset));
					for (int w:wordStatus) {
						writer.write(w + "\n");
					}
					writer.close();
				} catch (UnsupportedEncodingException | FileNotFoundException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
		});
		frame.setSize( 512, 256 );
		frame.getContentPane().setLayout(null);
		lblWord.setFont(new Font("Lucida Grande", Font.PLAIN, 20));
		lblWord.setHorizontalAlignment(SwingConstants.CENTER);
		lblWord.setText("单词");
		lblWord.setBounds(0, 0, 512, 60);
		frame.getContentPane().add(lblWord);

		spinner.setModel(new SpinnerNumberModel(1, 1, 60, 1));
		spinner.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent e) {
				t.setInitialDelay((int) spinner.getValue() * 1000);
				t.setDelay((int) spinner.getValue() * 1000);
			}
		});
		spinner.setValue(1);
		spinner.setBounds(206, 69, 63, 26);
		frame.getContentPane().add(spinner);
		
		JSeparator separator = new JSeparator();
		separator.setBounds(0, 56, 512, 6);
		frame.getContentPane().add(separator);
		
		label.setBounds(140, 74, 75, 16);
		frame.getContentPane().add(label);

		btnHard.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (testing) {
					generateQuestion();
					return;
				}
				t.stop();
				wordStatus.set(current, 2);
				while (newIdx < maxWords && wordStatus.get(newIdx) != 0) {
					newIdx++;
				}
				if (current < hardIdx) {
					hardIdx = current;
				}
				next();
				t.start();
			}
		});
		btnHard.setBounds(298, 69, 99, 29);
		frame.getContentPane().add(btnHard);
		radioButton0.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				if (testing == radioButton0.isSelected())
				{
					testing = !radioButton0.isSelected();
					if (radioButton0.isSelected()) {
						if (newIdx == maxWords) {
							javax.swing.JOptionPane.showMessageDialog(null, "没有新单词了，请继续练习吧。", "恭喜你！", javax.swing.JOptionPane.DEFAULT_OPTION);
							radioButton0.setSelected(false);
							radioButton1.setSelected(true);
							generateQuestion();
						}
						else {
							btnHard.setText("记住了");
							btnHard.setEnabled(true);
							radioButton1.setSelected(false);
							next();
							t.start();
						}
					}
				}
			}
		});
		radioButton0.setSelected(true);
		radioButton0.setBounds(10, 70, 48, 24);
		frame.getContentPane().add(radioButton0);
		
		radioButton1.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				if (testing != radioButton1.isSelected())
				{
					testing = radioButton1.isSelected();
					if (radioButton1.isSelected()) {
						if (hardIdx == maxWords) {
							if (newIdx == maxWords) {
								allDone();
								return;
							}
							javax.swing.JOptionPane.showMessageDialog(null, "没有需要练习的单词了，先背单词吧。", "恭喜你！", javax.swing.JOptionPane.DEFAULT_OPTION);
							btnHard.setText("记住了");
							btnHard.setEnabled(true);
							radioButton1.setSelected(false);
							radioButton0.setSelected(true);
							testing = false;
							next();
							t.start();
						}
						else {
							radioButton0.setSelected(false);
							generateQuestion();
						}
					}
				}
			}
		});
		radioButton1.setBounds(59, 70, 48, 24);
		frame.getContentPane().add(radioButton1);
		
		JLabel lblA = new JLabel("");
		lblA.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				Answer (answer == 0);
			}
		});
		lblA.setBounds(20, 114, 314, 16);
		frame.getContentPane().add(lblA);
		
		JLabel lblB = new JLabel("");
		lblB.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				Answer (answer == 1);
			}
		});
		lblB.setBounds(20, 142, 314, 16);
		frame.getContentPane().add(lblB);
		
		JLabel lblC = new JLabel("");
		lblC.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				Answer (answer == 2);
			}
		});
		lblC.setBounds(20, 170, 314, 16);
		frame.getContentPane().add(lblC);
		
		JLabel lblD = new JLabel("");
		lblD.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				Answer (answer == 3);
			}
		});
		lblD.setBounds(20, 198, 314, 16);
		frame.getContentPane().add(lblD);
		
		Answers[0] = lblA;
		Answers[1] = lblB;
		Answers[2] = lblC;
		Answers[3] = lblD;
		
		JSeparator separator_1 = new JSeparator();
		separator_1.setBounds(0, 96, 512, 6);
		frame.getContentPane().add(separator_1);

		lblResult.setForeground(new Color(0, 255, 127));
		lblResult.setFont(new Font("Lucida Grande", Font.BOLD, 13));
		lblResult.setHorizontalAlignment(SwingConstants.CENTER);
		lblResult.setBounds(350, 110, 156, 118);
		frame.getContentPane().add(lblResult);
		btnOk.setEnabled(false);
		
		btnOk.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				wordStatus.set(current, 1);
				while (hardIdx < maxWords && wordStatus.get(hardIdx) != 2) {
					hardIdx++;
				}
				btnOk.setEnabled(false);
				generateQuestion();
			}
		});
		btnOk.setBounds(410, 70,100, 30);
		frame.getContentPane().add(btnOk);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
	
	List<String> words = new ArrayList<>();
	List<String> meanings = new ArrayList<>();
	List<Integer> wordStatus = new ArrayList<>();
	//现在背的，所有词个数，没背过的，掌握的，难背的（生词本）
	int current, currentNew = 0, currentHard = 0, maxWords, newIdx, okIdx, hardIdx;
	void next() {
		if (testing) return;
		if (currentNew >= maxWords || newIdx >= maxWords) {
			javax.swing.JOptionPane.showMessageDialog(null, "没有新单词了，请直接练习吧。", "恭喜你！", javax.swing.JOptionPane.DEFAULT_OPTION);
			radioButton0.setSelected(false);
			radioButton1.setSelected(true);
			testing = true;
			generateQuestion();
			return;
		}
		if (currentNew < newIdx) currentNew = newIdx;
		current = currentNew;
		lblWord.setText( words.get(currentNew) + "    " + meanings.get(currentNew));
		if (newIdx != maxWords) {
			do {
				currentNew = (currentNew + 1) % maxWords;
				if (currentNew < newIdx) currentNew = newIdx;
			} while (currentNew != maxWords && wordStatus.get(currentNew) != 0);
		}
	}
	javax.swing.Timer t;
	public void start() {
		new Thread(()->{
			try{
				readAll();
			}catch(IOException ex){
				lblWord.setText(ex.toString());
				return;
			}
			t = new javax.swing.Timer(1000,(e)->{
				next();
			});
			t.start();
		}).start();
	}
	
	public void readAll( ) throws IOException{
		String fileName = this.getClass().getClassLoader().getResource("").getPath() + "College_Grade4.txt";
		String statusFileName = this.getClass().getClassLoader().getResource("").getPath() + "word_status.txt";
		String charset = "GB2312";
		try {
			newIdx = okIdx = hardIdx = -1;
			BufferedReader reader = new BufferedReader(
					new InputStreamReader(
						new FileInputStream(statusFileName),charset));
			String line; 
			while ((line = reader.readLine()) != null) { 
				line = line.trim();
				if( line.length() == 0 ) continue;
				int n = Integer.parseInt(line);
				wordStatus.add(n);
				if (newIdx < 0 && n == 0) {
					newIdx = wordStatus.size() - 1;
				}
				else if (okIdx < 0 && n == 1) {
					okIdx = wordStatus.size() - 1;
				}
				else if (hardIdx < 0 && n == 2) {
					hardIdx = wordStatus.size() - 1;
				}
			} 
			reader.close();
		}
		catch(IOException ex){}
		BufferedReader reader = new BufferedReader(
			new InputStreamReader(
				new FileInputStream(fileName), charset));
		String line; 
		while ((line = reader.readLine()) != null) { 
			line = line.trim();
			if( line.length() == 0 ) continue;
			int idx = line.indexOf("\t");
			words.add( line.substring(0, idx ));
			line = line.substring(idx + 1);
			idx = line.indexOf("\t");
			meanings.add( line.substring(0, idx));
		}
		reader.close();
		int diff = words.size() - wordStatus.size();
		while (diff-- > 0) {
			wordStatus.add(0);
			if (newIdx < 0) {
				newIdx = wordStatus.size() - 1;
			}
		}
		maxWords = words.size();
		if (newIdx == -1) {
			newIdx = maxWords;
			javax.swing.JOptionPane.showMessageDialog(null, "没有新单词了，请直接练习吧。", "恭喜你！", javax.swing.JOptionPane.DEFAULT_OPTION);
			radioButton0.setSelected(false);
			radioButton1.setSelected(true);
			testing = true;
		}
		if (hardIdx == -1) {
			hardIdx = maxWords;
			if (newIdx == maxWords) {
				allDone();
				return;
			}
		}
		else if (newIdx == maxWords) {
			generateQuestion();
		}
	}

	int answer = -1;
	void generateQuestion() {
		btnHard.setText("继续");
		btnHard.setEnabled(false);
		btnOk.setEnabled(false);
		lblResult.setText("");
		for (int i = 0; i < 4; ++i) {
			Answers[i].setText("");
		}
		if (currentHard < hardIdx || currentHard == maxWords) currentHard = hardIdx;
		if (currentHard == maxWords) {
			if (newIdx == maxWords) {
				allDone();
				return;
			}
			else {
				javax.swing.JOptionPane.showMessageDialog(null, "没有需要练习的单词了，先背单词吧。", "恭喜你！", javax.swing.JOptionPane.DEFAULT_OPTION);
				btnHard.setText("记住了");
				btnHard.setEnabled(true);
				radioButton1.setSelected(false);
				radioButton0.setSelected(true);
				testing = false;
				next();
				t.start();
				return;
			}
		}
		while (currentHard < maxWords && wordStatus.get(currentHard) != 2) {
			currentHard = (currentHard + 1) % maxWords;
			if (currentHard < hardIdx) currentHard = hardIdx;
		}
		lblWord.setText(words.get(currentHard));
		current = currentHard;
		int dummyResultCount = 0;
		int[] dummyResult = new int[4];
		for (int i = hardIdx; i < maxWords && dummyResultCount < 3; ++i) {
			if (i != currentHard && wordStatus.get(i) == 2) {
				dummyResult[dummyResultCount++] = i;
			}
		}
		if (dummyResultCount > 0) {
			while (dummyResultCount < 3) {
				dummyResult[dummyResultCount] = dummyResult[dummyResultCount - 1];
				dummyResultCount++;
			}
		}
		dummyResult[dummyResultCount] = currentHard;
		int questions = dummyResultCount + 1;
		int first = new Random().nextInt(questions);
		char[] c = new char[] {'A','B','C','D'};
		for (int i = 0; i < questions; ++i) {
			Answers[(i + first) % questions].setText(c[(i + first) % questions] + ".\t" + meanings.get(dummyResult[i]));
			Answers[(i + first) % questions].setEnabled(true);
		}
		for (int i = questions; i < 4; ++i) {
			Answers[i].setText("");
		}
		answer = (first + questions - 1) % questions;
	}
	
	void Answer(boolean right) {
		if (right) {
			lblResult.setText("Right");
			lblResult.setForeground(new Color(0,255,0));
			btnOk.setEnabled(true);
			btnHard.setEnabled(true);
		}
		else {
			lblResult.setText("Wrong");
			lblResult.setForeground(new Color(255,0,0));
			wordStatus.set(currentHard, 0);
			if (newIdx > currentHard) {
				newIdx = currentHard;
			}
			btnHard.setEnabled(true);
		}
		currentHard++;
	}
	
	void allDone() {
		javax.swing.JOptionPane.showMessageDialog(null, "你全学完了，你牛X了。你这么厉害，你猜猜怎么重置吧。", "恭喜你！", javax.swing.JOptionPane.DEFAULT_OPTION);
		radioButton0.setEnabled(false);
		radioButton1.setEnabled(false);
		spinner.setEnabled(false);
		btnOk.setEnabled(false);
		btnHard.setEnabled(false);
		testing = true;
	}
}
