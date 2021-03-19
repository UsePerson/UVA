import java.util.*;

public class uva11286 {

    public static void main(String[] args){

        Scanner input = new Scanner(System.in);

        while(true){

            int n = input.nextInt();
            if( n == 0 ) break;
            Map<ArrayList<Integer>, Integer> map = new HashMap();
            for(int i = 0 ; i < n ; i ++ ) {

                ArrayList<Integer> arr = new ArrayList<>();
                for (int j = 0; j < 5; j++) {

                    int course = input.nextInt();
                    arr.add(course);
                }
                Collections.sort(arr);
                if( map.isEmpty() || !map.containsKey(arr) ){

                    map.put(arr,1);
                }
                else{

                    map.replace(arr, map.get(arr)+1);
                }
            }

            int max = 0 ;
            int same = 0;
            for(Map.Entry<ArrayList<Integer>, Integer> m : map.entrySet()){

                if(max < m.getValue()){

                    max = m.getValue();
                    same = max;
                }
                else if(max == m.getValue()){

                    same += m.getValue();
                }
            }

            if(same != max){

                System.out.println(same);
            }
            else{

                System.out.println(max);
            }
        }
    }

}
