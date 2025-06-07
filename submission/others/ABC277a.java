import java.util.Scanner;

public class Main {
    //ABC277A
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] NX=sc.nextLine().split(" ");
        int N = Integer.parseInt(NX[0]);
        int X = Integer.parseInt(NX[1]);
        String[] P =sc.nextLine().split(" ");

        for (int i=0;i<N;++i){
            if (Integer.parseInt(P[i])==X){
                System.out.println(i+1);
                return;
            }
        }


    }
}
