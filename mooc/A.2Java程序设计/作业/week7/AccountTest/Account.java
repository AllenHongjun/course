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
		this.name = "Ǯ����";
		this.balence = 888888.88;
	}
	
	public Account(String id, int password, String name, double balence) {
		Pattern pattern = Pattern.compile("\\D");
		Matcher matcher = pattern.matcher(id);
		boolean create = true;
		if(matcher.find()){
			System.out.println("id����Ϊ10-16λ����");
			create = false;
		}else{
			if(id.length()<10 || id.length()>16){
			System.out.println("id����Ϊ10-16λ����");
			create = false;
			}
		}
		if((password+"").length()!=6){
			System.out.println("�������Ϊ6λ����");
			create = false;
		}
		if(create){
			this.id = id;
			this.password = password;
			this.name = name;
			this.balence = balence;
		}
	}
	//��Ǯ��moneyIn��
	public void moneyIn(double money){
		if(checkUserExist()){
			this.balence += money;
			System.out.println("��β��Ϊ"+(this.id+"").substring((this.id+"").length()-4)+"����"+money+"�����,�˻����Ϊ"+this.balence);
		}
	}
	//ȡǮ��moneyOut��
	public void moneyOut(double money){
		if(checkUserExist()){
			if(this.balence<money){
				System.out.println("�Բ��������˻�����,���Ϊ"+this.balence);
			}else{
				this.balence = this.balence-money;
				System.out.println("��β��Ϊ"+(this.id+"").substring((this.id+"").length()-4)+"���˻�ȡ��"+money+"�����,�˻����Ϊ"+this.balence);
			}
		}
	}
	//�鿴��view����
	public void view(){
		if(checkUserExist()){
			System.out.println("�����˻����Ϊ"+this.balence);
		}
	}
	
	private boolean checkUserExist(){
		if(this.id==null){
			System.out.println("���û�������");
			return false;
		}
		return true;
	}
	
}
