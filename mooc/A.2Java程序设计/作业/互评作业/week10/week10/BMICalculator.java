import javax.swing.*;
import javax.swing.plaf.FontUIResource;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Enumeration;

public class BMICalculator extends JFrame implements ActionListener {
  // 成人的BMI数值参考表
  String bmiStr =
      "成人的BMI数值参考表：\n"
          + "Adults\t\tWomen\tMen\n"
          + "underweight\t\t<19.1\t<20.7\n"
          + "in normal range\t19.1-25.8\t20.7-26.4\n"
          + "marginally overweight\t25.8-27.3\t26.4-27.8\n"
          + "overweight\t\t27.3-32.3\t27.8-31.1\n"
          + "very overweight or obese\t>32.3\t>31.1\n";
  JPanel pnl = new JPanel();
  JTextArea textArea = new JTextArea(bmiStr);
  JTextField lbl1 = new JTextField("结果显示"); // 显示身体状况
  JTextField text1 = new JTextField();
  JTextField text2 = new JTextField();
  JButton btn = new JButton("计算");
  Font font = new Font("Consolas", Font.BOLD, 15);
  int flag = 0; // 0/1 判断是男是女
  double height; // 身高
  double weight; // 体重

  public BMICalculator() {
    super("体重指数计算器");
    // 初始化全局字体
    initGlobalFont(font);
    setSize(800, 400);
    setLocationRelativeTo(null);
    add(pnl, BorderLayout.CENTER);
    add(textArea, BorderLayout.EAST);
    pnl.setFont(font);
    textArea.setFont(font);
    pnl.setLayout(new GridLayout(5, 2));
    // 男女单选框互斥
    ButtonGroup sexGroup = new ButtonGroup();
    JRadioButton manRbtn = new JRadioButton("男");
    JRadioButton womanRbtn = new JRadioButton("女", true);
    sexGroup.add(manRbtn);
    sexGroup.add(womanRbtn);
    JPanel pnl1 = new JPanel();
    pnl1.add(manRbtn);
    pnl1.add(womanRbtn);
    manRbtn.setFont(font);
    womanRbtn.setFont(font);
    JLabel lbl2 = new JLabel();
    pnl.add(new JLabel("性别", JLabel.RIGHT));
    pnl.add(pnl1);
    pnl.add(new JLabel("身高（m）", JLabel.RIGHT));
    pnl.add(text1);
    pnl.add(new JLabel("体重（kg）", JLabel.RIGHT));
    pnl.add(text2);
    pnl.add(lbl2);
    pnl.add(btn);
    pnl.add(new JLabel("体质指数（BMI）", JLabel.RIGHT));
    pnl.add(lbl1);

    manRbtn.addActionListener(this);
    womanRbtn.addActionListener(this);
    btn.addActionListener(this);

    setVisible(true);
    setDefaultCloseOperation(EXIT_ON_CLOSE);
  }

  // 事件响应
  @Override
  public void actionPerformed(ActionEvent e) {
    String str = e.getActionCommand();
    if ("男".equals(str) || "女".equals(str)) flag = isMan(str);
    else calculate();
  }

  // 全局字体
  public void initGlobalFont(Font font) {
    FontUIResource glocalFont = new FontUIResource(font);
    for (Enumeration<Object> keys = UIManager.getDefaults().keys(); keys.hasMoreElements(); ) {
      Object key = keys.nextElement();
      Object value = UIManager.get(key);
      if (value instanceof FontUIResource) UIManager.put(key, glocalFont);
    }
  }

  // 把身高、体重带入公式计算
  public void calculate() {
    String ts1 = text1.getText();
    String ts2 = text2.getText();
    if ("".equals(ts1) || "".equals(ts2)) JOptionPane.showMessageDialog(this, "请输入身高和体重！");
    height = Double.valueOf(ts1);
    weight = Double.valueOf(ts2);
    // BMI数值数组
    double[][] bmiNum = {{19.1, 25.8, 27.3, 32.3}, {20.7, 26.4, 27.8, 31.1}};
    double bmi = weight / (height * height);
    String s;
    if (bmi < bmiNum[flag][0]) s = "underweight";
    else if (bmi < bmiNum[flag][1]) s = "in normal range";
    else if (bmi < bmiNum[flag][2]) s = "marginally overweight";
    else if (bmi < bmiNum[flag][3]) s = "overweight";
    else s = "very overweight or obese";
    lbl1.setText(String.format("%.1f", bmi) + "  " + s);
  }

  // 判断性别
  public int isMan(String sexStr) {
    if ("男".equals(sexStr)) return 1;
    return 0;
  }

  public static void main(String[] args) {
    SwingUtilities.invokeLater(() -> new BMICalculator());
  }
}
