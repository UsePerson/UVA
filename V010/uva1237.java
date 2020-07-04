import java.io.*;

public class uva1237 {

    public static void main(String[] args) throws IOException {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int test = Integer.parseInt(in.readLine());
        while(test -- > 0){

            int car = Integer.parseInt(in.readLine());
            Triple[] t = new Triple[car];
            for(int i = 0 ; i < car ; i ++){
                String[] s = in.readLine().split(" ");
                t[i] = new Triple(s[0], Integer.parseInt(s[1]),Integer.parseInt(s[2]));
            }
            int q = Integer.parseInt(in.readLine());

            for(int i = 0 ; i < q ; i ++){

                int price = Integer.parseInt(in.readLine());
                int count = 0;
                int pos = -1;
                for(int j = 0 ; j < car ; j ++){

                    if( (price >= t[j].low) && (price <= t[j].high) ){
                        pos = j;
                        count++;
                    }
                }
                if(  count == 1 ){

                    System.out.println(t[pos].name);
                }
                else{
                    System.out.println("UNDETERMINED");
                }
            }
            if(test !=0)
            System.out.println();
        }
    }
    static class Triple{

        String name;
        int low ;
        int high;
        Triple(String n, int l , int h ){
            this.name = n;
            this.low = l;
            this.high = h;
        }
    }
}
