import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String N = sc.nextLine();
        String[] A = sc.nextLine().split(" ");
        String[] B = sc.nextLine().split(" ");
        int max_a = Integer.MIN_VALUE;
        int max_b = Integer.MIN_VALUE;
        for (int i=0;i<Integer.parseInt(N);++i){
            max_a=Math.max(Integer.parseInt(A[i]),max_a);
            max_b=Math.max(Integer.parseInt(B[i]),max_b);
        }
        System.out.println(max_a+max_b);
    }
}
