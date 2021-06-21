using System;
using System.Collections;

public interface IAccount
{
	long Number
	{
		get;
	}
	decimal Balance
	{
		get;
	}
	void Deposit( decimal amount );
	void Withdraw( decimal amount );
}

public class Bank
{
	public IAccount OpenAccount()
	{
		IAccount acc = new Account();
		accounts[ acc.Number ] = acc;
		return acc;
	}

	private readonly Hashtable accounts 
		= new Hashtable();

	private sealed class Account : IAccount
	{
		public long Number
		{
			get
			{
				return number;
			}
		}
		public decimal Balance
		{
			get
			{
				return balance;
			}
		}
		public void Deposit( decimal amount )
		{
			balance += amount;
		}
		public void Withdraw( decimal amount)
		{
			balance -= amount;
		}
		private decimal balance = 0;
		private readonly long number = nextNumber ++;
		
		private static long nextNumber = 123;
	}
}

class Test
{
	static void Main()
	{
		Bank bank = new Bank();
		IAccount account = bank.OpenAccount();
		account = bank.OpenAccount();
		account.Deposit( 100.00M );
		account.Withdraw( 40.00M );
		Console.WriteLine( "Account {0} has $ {1}",
			account.Number , account.Balance);
	}
}

