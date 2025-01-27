import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] HW = sc.nextLine().split(" ");
        int H = Integer.parseInt(HW[0]);
        int W = Integer.parseInt(HW[1]);
        String[][] BOARD = new String[H][W];
        for (int i = 0; i < H; ++i) {
            BOARD[i] = sc.nextLine().split("");
        }
        int top = 999999999;
        int bottom = -1;
        int left = 999999999;
        int right = -1;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (BOARD[i][j].equals("#")) {
                    top = Math.min(i, top);
                    bottom = Math.max(i, bottom);
                    left = Math.min(j, left);
                    right = Math.max(j, right);
                }
            }
        }
        for (int i = top; i < bottom+1; ++i) {
            for (int j = left; j < right+1; ++j) {
                if (BOARD[i][j].equals(".")) {
                    System.out.println("No");
                    sc.close();
                    return;
                }
            }
        }
        System.out.println("Yes");
        sc.close();
        return;
    }

}
