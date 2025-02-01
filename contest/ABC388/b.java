import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] ND = sc.nextLine().split(" ");
        int N = Integer.parseInt(ND[0]);
        int D = Integer.parseInt(ND[1]);
        int[][] TL = new int[N][2];
        for (int i = 0; i < N; ++i) {
            String[] tl = sc.nextLine().split(" ");
            TL[i][0] = Integer.parseInt(tl[0]);
            TL[i][1] = Integer.parseInt(tl[1]);
        }
        // int[] result = new int[0];

        for (int i = 1; i < D + 1; ++i) {
            int result=-1;
            for (int j = 0; j < N; ++j) {
                result=Math.max(TL[j][0]*(TL[j][1]+i),result);
            }
            System.out.print(result+" ");
        }
        System.out.println();
        sc.close();
    }
}