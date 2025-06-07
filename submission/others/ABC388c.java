import java.util.*;
// import java.util.function.Function;

// import java.util.Scanner;

public class Main {
    // ABC388Cおもち
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.nextLine().split(" ")[0]);
        String[] A = sc.nextLine().split(" ");
        long result = 0;
        for (int i = 0; i < N; ++i) {
            int ans = search(0, N, A, Integer.parseInt(A[i]) * 2);
            if (ans == N - 1) {
                if (Integer.parseInt(A[i]) * 2 <= Integer.parseInt(A[N - 1])) {
                    result++;
                    continue;
                }
            }
            result += (N - 1) - ans;
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
    public static boolean check(int mid){
        return true;}

    public static boolean check(int target, String[] array, int value) {
        return Integer.parseInt(array[target]) < value;
    }
}