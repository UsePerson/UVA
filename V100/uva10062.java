import java.util.*;


public class uva10062 {

    public static void main(String[] args){

        Scanner input = new Scanner(System.in);
        int end = 0;
        while(input.hasNext()){

            if(end++ != 0 )System.out.println();
            ArrayList<K> arr = new ArrayList<>();
            String s = input.nextLine();

            for(int l = 0 ; l < s.length() ; l ++ ) {

                boolean check = true;
                if(!arr.isEmpty()) {

                    for (int i = 0; i < arr.size(); i++) {

                        if (arr.get(i).s.equals(s.charAt(l))) {

                            arr.get(i).count++;
                            check = false;
                            break;
                        }
                    }

                }
                if(arr.isEmpty() || check)  {
                    arr.add(new K(s.charAt(l), 1));
                }
            }
            Collections.sort(arr);
            for(K p : arr)
                System.out.println(p.toString());


        }


    }
    public static class K implements Comparable<K>{
        Character s;
        int  count;
        K(Character s, int count){
            this.s = s;
            this.count = count;
        }
        @Override
        public int compareTo(K o) {
            int check = this.count - o.count;
            if(check == 0)
                return o.s-this.s;
            return check;
        }

        @Override
        public String toString() {
            return (int)this.s + " " + this.count;
        }
    }

}
