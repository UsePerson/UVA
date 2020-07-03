mport java.util.Scanner;
public class Practice {
	
	static int ans;
	static boolean check[] = new boolean[25];
	static boolean arr[][] = new boolean[25][25];
	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in );
		
		while(true) {
			
			int a = input.nextInt();
			int b = input.nextInt();
			
			if( ( a == 0 ) && ( b == 0 ) )break;
			
			initial( a );
			
			for( int i = 0 ; i < b ; i ++ ) {
				
				int x = input.nextInt();
				int y = input.nextInt();
				build( x , y );
			}
			for( int i = 0 ; i < a ; i++ ) {
				
				check[ i ] = false;
				dfs( i , 0 );
			}
			System.out.println( ans );
		}		
	}
	
	public static void initial( int a ) {
		
		ans = 0;
		for( int i = 0 ; i < a ; i ++ ) {
			
			for( int j = 0 ; j < a ; j ++ ){
			
				arr[ i ][ j ] = false;	
			}
			check[ i ] = true; 
		}
	}
	public static void build( int x , int y ) {
		
		arr[ x ][ y ] = true;
		arr[ y ][ x ] = true;
	}
	public static void dfs( int i , int leng ) {
		
		if( ans < leng ) {
			
			ans = leng ;
		}
		for( int k = 0 ; k < arr[i].length ; k ++ ) {
			
			if( ( arr[ i ][ k ] == true ) && ( check[ k ] == true ) ) {
				
				arr[ i ][ k ] = false;
				arr[ k ][ i ] = false;
				dfs( k , leng+1 );
				arr[ i ][ k ] = true;
				arr[ k ][ i ] = true;
			}
		}
		
	}
}