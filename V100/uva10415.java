import static java.lang.System.out;
import java.util.*;
public class uva10415 {

    public static void main(String[] args){

        Scanner input = new Scanner(System.in);
        Map<Character, boolean[]> map = new HashMap<>();

        Character[] c = {'c', 'd', 'e', 'f', 'g', 'a', 'b',
                         'C', 'D', 'E', 'F', 'G', 'A', 'B'};
        int last_size = 11;
        for(int i = 0 ; i < c.length ; i ++ ){

            boolean[] finger = new boolean[11];
            Arrays.fill(finger,false);
            if( i < 5 ) {

                for (int j = 2; j < (last_size - i); j++) {

                    if( (j != 5) && (j != 6) )
                        finger[j] = true;
                }
            }
            else if( i <= 7 ){

                if(i ==5 ) {

                    finger[2] = true;
                    finger[3] = true;
                }
                else if( i == 6 )
                    finger[2] = true;
                else
                    finger[3] = true;
            }
            else if(i <= 10){

                for(int j = 1 ; j <= (c.length - i + 3) ; j ++){

                    if( (j != 5) && (j != 6) )
                        finger[j] = true;
                }
            }
            else{

                for(int j = 1 ; j < (c.length - i + 2); j ++){

                    finger[j] = true;
                }
            }
            map.put(c[i],finger);
        }

        int test = Integer.parseInt(input.nextLine());
        while(test -- > 0){

            String s = input.nextLine();

            boolean[] pre = new boolean[11];
            int[] ans = new int[11];
            Arrays.fill(pre, false);
            Arrays.fill(ans,0);
            for(int i = 0 ; i < s.length() ; i ++ ){

                boolean[] now = map.get(s.charAt(i));
                for(int j = 0 ; j < now.length ; j ++ ){

                    if( (!pre[j]) &&(now[j]) ){

                        ans[j] ++;
                    }
                    if(pre[j] != now[j])
                        pre[j] = !pre[j];
                }
            }
            for(int i= 1 ; i < ans.length ; i ++ ){

                if(i != (ans.length -1) )
                    out.print(ans[i]+ " ");
                else
                    out.print(ans[i]);
            }
            out.println();
        }
    }
}
