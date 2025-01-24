import java.io.*;
import java.util.*;

public class Main {
    //ABC388Cおもち
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.nextLine().split(" ")[0]);
        String[] A = sc.nextLine().split(" ");
        int result = 0;
        for (int i = 0; i < N; ++i) {
            int ans = search(0, N, A, Integer.parseInt(A[i]) * 2)+1;
            if (ans == N - 1 && Integer.parseInt(A[N-1])<=Integer.parseInt(A[i])*2) {
                break;
            }
            result += N - ans;
        }
        System.out.println(result);
        sc.close();
    }

    public static int search(int ok, int ng, String[] array, int value) {
        while (1 < Math.abs(ok - ng)) {
            int center = ((ok + ng) / 2);
            if (check(center, array, value)) {
                ok = center;
            } else {
                ng = center;
            }
        }
        return ok;
    }

    public static boolean check(int target, String[] array, int value) {
        return Integer.parseInt(array[target])<value;
    }

}
// 10
// 1 3 5 7 20 32 45 78 82 93
