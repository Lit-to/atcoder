
import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int Q=Integer.parseInt(sc.nextLine());
        int[][] QUERY = new int[Q][2];
        List<Integer> queue = new ArrayList<Integer>();
        for (int i=0;i<Q;++i){
            String query=sc.nextLine();
            if (query.charAt(0)!='2'){
                QUERY[i][0]=(int)query.charAt(0)-'0';
                QUERY[i][1]=(int)query.charAt(2)-'0';
            }
            else{
                QUERY[i][0]=2;
                QUERY[i][1]=-1;
            }
        }
        int last=0;
        int first=0;
        int cut=0;
        for (int i=0;i<Q;++i){
            if (QUERY[i][0]==1){
                queue.add(last);
                last+=QUERY[i][1];
            }else if (QUERY[i][0]==2){
                cut+=queue.get(first+1);
                ++first;
            }else{
                System.out.println(queue.get(QUERY[i][1]-1+first)-cut);
            }

        }
        sc.close();


    }
}
