import java.io.*;

public class uva1594 {

    public static  void main(String[] args) throws IOException {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int test = Integer.parseInt(in.readLine());
        while(test -- > 0){

            int size = Integer.parseInt(in.readLine());
            int[] original = new int[size];
            int[] cal = new int[size];
            String seq = in.readLine();
            String[] spl = seq.split( " ");
            for(int i = 0 ; i < size ; i ++ ){

                original[i] = Integer.parseInt(spl[i]);
                cal[i] = original[i];
            }
            int max_loop = 1000;
            boolean check = true;
            while( max_loop -- > 0){

                int sum = size;
                for(int i = 0 ; i < size ; i ++ ){

                    if(cal[i] == 0)
                        sum --;
                    if(i == (size -1))
                        cal[i] = Math.abs(original[0] - original[i]);
                    else
                        cal[i] = Math.abs(original[i] - original[i+1]);
                }
                for(int i = 0 ; i < size ; i ++){
                    original[i] = cal[i];
                }
                if( sum == 0 ){

                    check = false;
                    break;
                }

            }

            if(check)
                System.out.println("LOOP");
            else
                System.out.println("ZERO");

        }
    }
}
