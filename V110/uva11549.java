import java.util.*;
public class uva11549 {

	public static void main(String[] args) {
		
		Scanner input= new Scanner (System.in);
		int test = input.nextInt();
		while( test-- > 0 ) {
			
			int n = input.nextInt();
			long k1 = input.nextLong();
			long k2 = k1;		
			long ans = k1;
			do {
				
				k1 = calculate( k1 , n);
				k2 = calculate( k2 , n);
				if( k2 > ans ) 
					ans = k2;
				k2 = calculate( k2 , n);
				if( k2 > ans ) 
					ans = k2;
			}while( k1 != k2 );
			
			System.out.println( ans );
		}
		
	}
	public static long calculate( long k , int n ) {
		
		k = k * k;
		long turn = new Double( k / Math.pow(10 , (int)( Math.log10( k ) + 1  - n ) ) ).longValue();
		return turn;
	}

}
