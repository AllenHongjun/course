
public class AccountTest {

	public static void main(String[] args) {
		Account test = new Account();
		test.view();
		test.moneyOut(888888.99);
		test.moneyIn(0.01);
		Account lisi = new Account("12123123", 123, "lisi", 9343.92);
		lisi.view();
		Account zhangsan = new Account("1234568790", 1234567, "zhangsan", 223452.34);
		zhangsan.view();
		Account wangwu = new Account("1234567890123456", 123456, "wangwu", 93323.52);
		wangwu.view();
		wangwu.moneyIn(10000.11);
		wangwu.moneyOut(2222.22);
	}

}
