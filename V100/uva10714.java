import java.util.Scanner;

public class uva10714 {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int test = input.nextInt();
		while( test -- > 0 ) {
			
			int distance = input.nextInt();
			int ant = input.nextInt();
			int min = 0;
			int max = 0;
			for( int i = 0 ; i < ant ; i ++ ) {
				
				int a = input.nextInt(); 
				if( a > distance / 2 ) {
					
					min = Math.max( min, distance - a); 
					max = Math.max( max, a );
				}
				else {
					
					min = Math.max( min, a );
					max = Math.max( max, distance - a );
				}
			}
			System.out.println( min + " " + max );
			
		}
	}

}
