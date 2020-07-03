import java.util.*;
public class uva11157 {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int test= Integer.valueOf( input.nextLine() );
		int Case = 1;
		while( test -- > 0 ) {
			
			int n = input.nextInt(); // n rocks
			int d = input.nextInt(); // distance
			Queue<Integer> q1 = new LinkedList<Integer>();
			Queue<Integer> q2 = new LinkedList<Integer>();
			q1.offer(0);
			q2.offer(0);
			boolean turn = true;
			for(int k = 1 ; k <= n ; k ++ ) {
				
				String[] rockCondition = input.next().split("-",-1);
				int p = Integer.valueOf( rockCondition[1] ); // rockCondition[0] is B ||  S
				if(rockCondition[0].equals("B")) {
					
					q1.offer(p);
					q2.offer(p);
				}
				else {
					if( turn ) {
						
						q1.offer(p);
						turn = false;
					}
					else {
						
						q2.offer(p);
						turn = true;
					}
				}
			}
			q1.offer(d);
			q2.offer(d);
			int max = -1 ;
			int preValue = q1.poll();
			while(!q1.isEmpty()) {
				
				max = Math.max(max, q1.peek() - preValue);
				preValue = q1.poll();
			}
			preValue = q2.poll();
			while(!q2.isEmpty()) {
				
				max = Math.max(max, q2.peek() - preValue);
				preValue = q2.poll();
			}
			System.out.println("Case " + Case++ + ": " + max);
		}

	}

}
