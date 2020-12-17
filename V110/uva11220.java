import  java.io.*;

public class uva11220 {

    public static void main(String[] args) throws IOException {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String s = in.readLine();
        int test = 0;
        if(s.length() == 2)
            test += (s.charAt(0)-'0') * 10 + (s.charAt(1)-'0');
        else
            test += (s.charAt(0)-'0');

        int Case = 1;
        in.readLine();
        while(test -- > 0){

            System.out.println("Case #"+ Case++ + ":");
            while(true){

                s = in.readLine();
                if(s.equals(""))break;
                String[] spl = s.split(" ");
                int count = 0;
                for(String sub : spl ){

                    if( (sub.length() - 1) >= count){
                        System.out.print(sub.charAt(count++));
                    }
                }
                System.out.println();
            }
            if(test!=0)
                System.out.println();
        }
    }
}
