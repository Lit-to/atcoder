import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] HWXY = sc.nextLine().split(" ");
        int H = Integer.parseInt(HWXY[0]);
        int W = Integer.parseInt(HWXY[1]);
        int X = Integer.parseInt(HWXY[2]);
        int Y = Integer.parseInt(HWXY[3]);
        int[][] LRUD = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };
        int[] pos = { X - 1, Y - 1 };
        char[][] BOARD = new char[H][W];
        for (int i = 0; i < H; ++i) {
            String line = sc.nextLine();
            for (int j = 0; j < W; ++j) {
                BOARD[i][j] = line.charAt(j);
            }
        }
        boolean[][] done = new boolean[H][W];
        String T = sc.nextLine();
        int N = T.length();
        int result = 0;
        if (BOARD[pos[0]][pos[1]] == '@'){
            ++result;
        }
        for (int i = 0; i < N; ++i) {
            // System.err.println(pos[0]+" "+pos[1]);
            done[pos[0]][pos[1]] = true;
            char op = T.charAt(i);
            int[] diff = new int[2];
            if (op == 'L') {
                diff = LRUD[0];
            } else if (op == 'R') {
                diff = LRUD[1];
            } else if (op == 'U') {
                diff = LRUD[2];
            } else {
                diff = LRUD[3];
            }
            if (BOARD[pos[0] + diff[0]][pos[1] + diff[1]] != '#') {
                pos[0] += diff[0];
                pos[1] += diff[1];
            }
            if (BOARD[pos[0]][pos[1]] == '@' && !done[pos[0]][pos[1]]) {
                ++result;
            }

        }
        ++pos[0];
        ++pos[1];
        System.out.println(pos[0] + " " + pos[1] + " " + result);
        sc.close();
        return;
    }
}
