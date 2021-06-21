import java.util.Date;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Account {
	private String id;
	private int password;
	private String name;
	private double balence;
	public Account() {
		this.id = "1111111111111111";
		this.password = 666666;
		this.name = "钱三多";
		this.balence = 888888.88;
	}
	
	public Account(String id, int password, String name, double balence) {
		Pattern pattern = Pattern.compile("\\D");
		Matcher matcher = pattern.matcher(id);
		boolean create = true;
		if(matcher.find()){
			System.out.println("id必须为10-16位数字");
			create = false;
		}else{
			if(id.length()<10 || id.length()>16){
			System.out.println("id必须为10-16位数字");
			create = false;
			}
		}
		if((password+"").length()!=6){
			System.out.println("密码必须为6位数字");
			create = false;
		}
		if(create){
			this.id = id;
			this.password = password;
			this.name = name;
			this.balence = balence;
		}
	}
	//存钱（moneyIn）
	public void moneyIn(double money){
		if(checkUserExist()){
			this.balence += money;
			System.out.println("您尾号为"+(this.id+"").substring((this.id+"").length()-4)+"存入"+money+"人民币,账户余额为"+this.balence);
		}
	}
	//取钱（moneyOut）
	public void moneyOut(double money){
		if(checkUserExist()){
			if(this.balence<money){
				System.out.println("对不起，您的账户余额不足,余额为"+this.balence);
			}else{
				this.balence = this.balence-money;
				System.out.println("您尾号为"+(this.id+"").substring((this.id+"").length()-4)+"的账户取出"+money+"人民币,账户余额为"+this.balence);
			}
		}
	}
	//查看余额（view）。
	public void view(){
		if(checkUserExist()){
			System.out.println("您的账户余额为"+this.balence);
		}
	}
	
	private boolean checkUserExist(){
		if(this.id==null){
			System.out.println("该用户不存在");
			return false;
		}
		return true;
	}
	
}
