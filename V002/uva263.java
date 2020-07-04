import java.io.*;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class uva263 {

    public static void main(String[] args) throws IOException {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        while(true){

            String input = in.readLine();

            if( input.equals("0") )break;
            System.out.println("Original number was " + input);
            int count = 0;
            Set<String> set = new HashSet<String>();
            while(true){

                String[] s = input.split("");
                set.add(input);
                Arrays.sort(s);
                StringBuilder sb = new StringBuilder();
                for(String i :s) sb.append(i);
                long first = Long.parseLong(String.valueOf(sb));
                long second = Long.parseLong(String.valueOf(sb.reverse()));
                System.out.println(second + " - " + first + " = " + (second - first));
                count++;

                if(set.contains(String.valueOf(second - first)))break;
                input = String.valueOf(second - first);

            }
            System.out.println("Chain length " + count );
            System.out.println();
        }
    }
}
