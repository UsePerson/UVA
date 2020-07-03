import java.util.*;
public class uva1193 {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		int Case = 1;
		while( true ) {
			
			int n = input.nextInt();
			int d = input.nextInt();
			if( n == 0 && d == 0 ) break;
			Pair[] a = new Pair[n];
			int i = 0;
			boolean neg = false;
			while( n-- > 0 ) {
				
				int x =  input.nextInt();
				int y = input.nextInt();
				int side = (int)( Math.sqrt( d*d - y*y ) );
				if( y > d  || y < 0) 
					neg = true;
				else
					a[ i++ ] = new Pair( x - side, x + side );
			}
			if(neg) {
				
				System.out.println("Case " + (Case++) +": -1");
			}
			else{
				
				int count = 1;
				int set = 0;
				Arrays.sort(a);
				for( int j = 1 ; j < a.length ; j ++ ) {
					
					if( a[ set ].right >= a[ j ].left ) {
						
						continue;
					}
					else {
						
						count++;
						set = j;
					}
				}
				
				System.out.println("Case "+ (Case++) + ": " + count);
			}	
		}
	}
	static class Pair implements Comparable<Pair>{
		
		int left;
		int right;
		
		public Pair( int left , int right ) {
			
			this.left = left;
			this.right = right;
		}

		@Override
		public int compareTo(Pair p) {
			
			return Integer.compare(this.right, p.right);
		}
	}

}
