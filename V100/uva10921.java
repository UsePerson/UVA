import static java.lang.System.out;
import java.io.*;
public class uva10921 {

    public static void main(String[] args)throws IOException{

        int number[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
        String s ="";
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        while( ((s = input.readLine()) != null) && (s.length() != 0)){

            for(int i = 0 ; i < s.length() ; i ++ ){

                if( (s.charAt(i) >= 'A') &&(s.charAt(i) <= 'Z')){

                    out.print(number[s.charAt(i)-'A']);
                }
                else {
                    out.print(s.charAt(i));
                }
            }
            out.println();
        }
   }
}
