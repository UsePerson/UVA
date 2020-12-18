import java.io.*;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class uva12820 {

    public static void main(String[] args)throws IOException{

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int Case = 1;
        while(true){

            String input = in.readLine();
            if(input == null)
                break;
            int test = Integer.parseInt(input);

            int ans = 0;
            while(test -- > 0){

                String word = in.readLine();
                char[] c = word.toCharArray();
                Arrays.sort(c);
                Set<Integer> set = new HashSet<>();
                char state =  c[0];
                int count = 1;
                boolean check = true;
                for(int i = 1 ; i < word.length() ; i ++ ){

                    if(state != c[i]){

                        if( (!set.isEmpty()) && set.contains(count)){

                            check = false;
                            break;
                        }
                        state = c[i];
                        set.add(count);
                        count = 1;
                    }
                    else{
                        count++;
                    }
                }
                if(set.contains(count))
                    check = false;
                if(check && (!set.isEmpty()) )
                    ans ++;
            }
            System.out.println("Case " + Case++ + ": " + ans);
        }
    }
}
