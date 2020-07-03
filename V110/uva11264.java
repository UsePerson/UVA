import java.util.Scanner;

public class uva11264 {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		int test = input.nextInt();
		while( test -- > 0 ) {
			
			int n = input.nextInt();
			int[] arr= new int[ n ];
			for(int i = 0 ; i < n ; i ++ ) {
				
				arr[ i ] = input.nextInt();
			}
			int sum = arr[ 0 ] ; 
			int count = 2 ;
			for(int i = 1 ; i < n-1 ; i ++ ) {
				
				if( sum + arr[i] < arr[i+1] ) {
					sum += arr[i];
					count++;
				}
			}
			System.out.println(count);
		}

	}

}
