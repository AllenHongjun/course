class MyException extends Exception {
   	private int idnumber;
 	public MyException(String message, int id) {
		super(message);
		this.idnumber = id;
 	} 
	public int getId() {
		return idnumber;
 	}
}

public class Exce7{
    public void regist(int num) throws MyException {
 	    if(num < -6) {
   			  System.out.println("�ǼǺ���" + num );
 	          throw new MyException("����Ϊ��ֵ��������",50);
 	    }
    }
    
	public void manager() {
 	    try {
	        regist(-7);
 	    } catch (MyException e) {
 	        System.out.println("�Ǽ�ʧ�ܣ���������" + e.getId());
	    }
	    System.out.println("���εǼǲ�������");
    }
    
	public static void main(String args[]){
	    Exce7 t = new Exce7();
	    t.manager();
    }
}
