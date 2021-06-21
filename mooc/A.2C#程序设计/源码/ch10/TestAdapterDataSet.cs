using System;
using System.Data;
using System.Data.OleDb;

class Test 
{
	public static void Main()
	{
		TestAdapter();
	}
	public static void TestAdapter()
	{
		string strSql = "SELECT * FROM [Publishers]";
		

		string strConn =
			@"Provider=Microsoft.Jet.OLEDB.4.0;" +
			@"Data Source=D:\CsExample\ch10\BIBLIO.MDB";

		OleDbConnection conn = new OleDbConnection( strConn );

		OleDbDataAdapter daAdapter = new OleDbDataAdapter(strSql, conn);

		OleDbCommandBuilder cmdbld = new OleDbCommandBuilder( daAdapter );
		
		DataSet dsMyData = new DataSet();

		daAdapter.Fill(dsMyData);

		foreach( DataTable table in dsMyData.Tables )
		{
			foreach( DataRow row in table.Rows )
			{
				foreach( object field in row.ItemArray )
				{
					Console.Write( field );
				}
				Console.WriteLine();
			}
		}

		Console.WriteLine( dsMyData.Tables[0].Rows[0][1] );

		DataRow row1 = dsMyData.Tables[0].Rows[0];
		row1.BeginEdit();
		row1[ 1 ] = "Tang";
		row1.EndEdit();
		row1.AcceptChanges();

		DataRow row2 = dsMyData.Tables[0].NewRow();
		row2[ 1 ] = "He";
		row2[ 2 ] = "Peking Univ.";
		row2[ 3 ] = "Beijing";
		dsMyData.Tables[0].Rows.Add( row2 );

		dsMyData.Tables[0].Rows[1].Delete();

		DataTable myTable = dsMyData.Tables[0];

		string strExpr = "Name Like 'T*'";
		DataRow [] foundRows = myTable.Select(strExpr);
		for(int i = 0; i < foundRows.Length; i ++){
		  Console.WriteLine(foundRows[i][1]);
		}

		myTable.AcceptChanges();

		daAdapter.Update( dsMyData );

	}
}