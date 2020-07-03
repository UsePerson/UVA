import java.util.Scanner;

public class uva10718 {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		while( input.hasNext() ) {
			
			long n = input.nextLong();
			long lower = input.nextLong();
			long upper = input.nextLong();
			
			long m = 0 ;
			for( int i = 31 ; i >= 0 ; i -- ) {
				
				long sll = ( long ) 1 << i;
				long tmp = ( m | sll );
				
				if( (  n & sll ) == 0  ) {
					if( tmp <= upper )
						m = tmp;
				}
				else {
					
					if( tmp - 1 < lower ) m = tmp;
				}
			}
			System.out.println( m );
		}
	}

}
