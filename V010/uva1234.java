import java.util.Arrays;
import java.util.Scanner;

public class uva1234 {

    static int[] arr = new int[10000 + 5];
    static int dot ;
    public static void main(String[] args){

        Scanner in = new Scanner(System.in);
        int test = in.nextInt();
        while(test -- >0){

            int vertex = in.nextInt();
            int e = in.nextInt();

            Kruskal[] k = new Kruskal[e];
            int sum = 0;
            for(int i = 0 ; i < e ; i ++){

                int x = in.nextInt();
                int y = in.nextInt();
                int cost = in.nextInt();
                if(x < y)
                    k[i] = new Kruskal(x,y,cost);
                else
                    k[i] = new Kruskal(y,x,cost);
                sum += cost;
            }
            Arrays.sort(k);

            int pos = 0;
            init(vertex);
            while(e -- > 0){

                if( find( k[pos].x , k[pos].y ) ){

                    sum -= k[pos].cost;

                }
                pos++;
            }
            System.out.println(sum);
        }
        in.nextInt();
    }
    public static void init(int vertex){
        for(int i = 1  ;i <= vertex ; i ++){
            arr[i] = -1;
        }
    }
    public static boolean find(int x, int y){

        int a = findParent(x);
        int b = findParent(y);

        if( a == b ){
            return false;
        }
        else if( arr[a] > arr[b] ){

            arr[b] += arr[a];
            arr[a] = b;
        }
        else{
            arr[a] += arr[b];
            arr[b] = a;
        }
        return true;
    }
    public static int findParent(int x){
        if( arr[x] > 0 )
            return findParent( arr[x] );
        return x ;
    }
    static class Kruskal implements Comparable<Kruskal>{

        int x;
        int y;
        int cost;
        Kruskal(int x,int y,int cost){
            this.x = x;
            this.y = y;
            this.cost = cost;

        }
        @Override
        public int compareTo(Kruskal o) {
            return o.cost - this.cost;
        }
    }
}
