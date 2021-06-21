import System;
import System.Text;
package Interop2 {
	public class JSExpressObj {
		public function Eval( str:String ):String
		{
			var a = "";
			eval( "a=(" + str +")" );
			return "" + a;
		}
	}
}
