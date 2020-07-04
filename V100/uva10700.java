import java.io.*;

public class uva10700 {

    public static void main(String[] args) throws IOException{

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int test = Integer.parseInt(in.readLine());
        while(test -- > 0){

            String s = in.readLine();
            long max = 1;
            for(String plus:s.split("[*]")){
                long a = 0;
                for(String mul:plus.split("[+]")){
                    a += Integer.parseInt(mul);
                }
                max *= a;
            }
            long min = 0;
            for(String mul:s.split("[+]")){
                long a = 1;
                for(String plus:mul.split("[*]")){
                    a *= Integer.parseInt(plus);
                }
                min += a;
            }
            System.out.println("The maximum and minimum are " + max + " and " + min +".");
        }
    }
}
