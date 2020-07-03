
import java.util.*;
public class uva514 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		while(true) {
			
			int test = input.nextInt();
			if(test == 0 ) break;
			int num = test ;
			boolean enD = false;
			while(true) {
				
				boolean check = false;
				test = num;
				Stack<Integer> a = new Stack<Integer>();
				Stack<Integer> station =  new Stack<Integer>();
				for(int i = test ; i >= 1 ; i-- ) 
					a.push(i);
				
				while(test -- > 0) {
				
					int train = input.nextInt();
					if( train == 0 ) {
						enD = true;
						break;	
					}
					boolean turn = true;
					while(turn) {
						
						if(!station.empty() && station.peek() == train ) {
						
							station.pop();
							break;
						}
						else if (  station.empty() || train > station.peek() ) {
						
							while( station.empty() || station.peek() != train )
								station.push( a.pop() );
						}
						else {
							check = true;
							break;
						}
					}
				}
				if(enD) {
					System.out.println();
					break;
				}
				
				if(check) {
					
					System.out.println("No");
				}
				else{
					
					System.out.println("Yes");
				}
			}
			
		}

	}

}
