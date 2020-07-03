import java.util.Scanner;
import java.math.BigInteger;

class uva10814{

	public static void main(String[] args){

		Scanner input = new Scanner( System.in );
		
		int test = input.nextInt();
		for( int i = 1 ; i <= test ; i ++ ){
		
			BigInteger a = input.nextBigInteger();
			String division = input.next();
			BigInteger b = input.nextBigInteger();
			
			BigInteger gcd_ab = a.gcd( b );
			System.out.println( a.divide( gcd_ab ) + " / " + b.divide( gcd_ab ) );
		}
	}	
}