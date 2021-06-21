import java.util.ArrayList;  
import java.util.List;

class test03 
{
	public static void main(String[] args) 
	{
		List<Integer> number = new ArrayList<Integer>();  
  
        
          
        for (int i = 0, y = 2; i < 98; i++, y++) {  
            number.add(i, y);  
        }  
       
	   //把所有的数取出来按顺序除去，如果能整出的就不是素数 要去掉
        for (int i = 0, y = 2; i < number.size(); i++, y++) {  
            for (int j = 0; j < number.size(); j++) {  
                if (number.get(j) % y == 0) {  
                    if (number.get(j) == y) {  
                        continue;  
                    } else {  
                        number.remove(j);  
                       
                    }  
                }  
  
            }  
            System.out.print(number.get(i) + " ");  
        }  
	}
}
