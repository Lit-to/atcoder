import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.nextLine());
        String[] A = sc.nextLine().split(" ");
        for (int i = 1; i < N - 1; ++i) {
            long left = Long.parseLong(A[i])*Long.parseLong(A[i]);
            long right = Long.parseLong(A[i - 1]) * Long.parseLong(A[i + 1]);
            if (left != right) {
                System.out.println("No");
                sc.close();
                return;
            }
        }
        System.out.println("Yes");
        sc.close();
        return;
    }
}
