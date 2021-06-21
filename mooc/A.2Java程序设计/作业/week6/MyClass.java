/* 
题目要求：
	1）自定义一个异常类，注意其继承自系统的异常类，并要求有构造方法；	
	2）使用自定义的异常：要求在一个函数中抛出异常，在另一段程序中调用这个函数并捕获异常。
*/

public class MyClass  // 主类
{
	public static void main(String[] args)
	{
		Test test = new Test();
		try{
			test.testException();
		} catch(MyException e) {    // 捕获异常
			e.printStackTrace();
			System.out.println("The ExceptionCode: " + e.getCode());
			System.out.println("The ExceptionMessage: " + e.getMessage());
		}			
	}
}


class MyException extends RuntimeException   // 自定义异常类
{
	private String ExceptionCode;    // 异常码
	private String ExceptionMessage;   // 异常信息
	
	// 构造函数
	public MyException()
	{
		super();
	}
	
	public MyException(String message)
	{
		super(message);
		this.ExceptionMessage = message;
	}
	
	public MyException(String code , String message)
	{
		super(message);
		this.ExceptionCode = code;
		this.ExceptionMessage = message;
	}
	
	public String getCode()   
	{
		return ExceptionCode;
	}
	
	public String getMessage()
	{
		return ExceptionMessage;
	}	
}

class Test   // 用于抛出异常的测试类
{
	// 只抛出异常
	public void testException() throws MyException 
	{
		MyException myException = new MyException("1600013034" , "Hello-World!");
		throw myException;
	}
}


