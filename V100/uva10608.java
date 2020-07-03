package aaa;
// UVA 10608 Friends
import java.util.*;
public class Union 
{
	public static int set[] = new int [30001];	// town¡¦s citizens ( 1 <= N <= 30000 )
	public static void main( String[] args ){ 
	
		Scanner input = new Scanner( System.in );
		int test = input.nextInt();	// get test case
		for( int i = 1 ; i <= test ; i ++ ){
		
			int N = input.nextInt();	// get town¡¦s citizens ( 1 <= N <= 30000 )
			int M = input.nextInt();	// get pairs of people ( 0 <= M <= 500000)
			init( N );
			for( int j = 1 ; j <= M ; j ++ ){
			
				int a = input.nextInt();	// get A 
				int b = input.nextInt();	// get B 
				union( a , b );				
			}
			find(N);
		}
	}
	
	public static void init( int N ){	// from 1 to N , initial set[]
	
		for ( int i = 1 ; i <= N ; i ++ ){
		
			set[i] = -1 ;
		}
	}
//-------------------------------------------------------------------------------------------------------
	public static  void union( int a , int b ){
	
		a = findparent( a );
		b = findparent( b );
		if( a == b ){  // same set
			// not do
		}
		else if( set[ a ] < set[ b ] ){ // set[a] element > set[b] element
		
			set[ a ] += set[ b ];
			set[ b ] = a;		
		}
		else{	// set[a] element <= set[b] element
		
			set[ b ] += set[ a ];
			set[ a ] = b;
		}
	}
	public static int findparent( int a ){
	
		if( set[ a ] > 0 ){ // find set[a] parent 
		
			return findparent( set[ a ] );
		}
		return a; // if set[a] is parent, return a
	}
//-------------------------------------------------------------------------------------------------------
	public static void find( int N ){	// find biggest set
	
		int max = 1;
		for( int i = 1; i <= N ; i ++ ){	
		
			if( ( set[ i ] < 0 ) && ( set[ i ] < max ) ){
			
				max = set[ i ];
			}
		}
		System.out.println( Math.abs( max ) );
	}
}
