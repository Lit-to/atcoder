// ABC391 b

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] NM = sc.nextLine().split(" ");
        int N = Integer.parseInt(NM[0]);
        int M = Integer.parseInt(NM[1]);
        String[][] BOARD_S = new String[N][N];
        String[][] BOARD_T = new String[M][M];
        for (int i = 0; i < N; ++i) {
            BOARD_S[i] = sc.nextLine().split("");
        }
        for (int i = 0; i < M; ++i) {
            BOARD_T[i] = sc.nextLine().split("");
        }
        for (int i = 0; i + M <= N; ++i) {
            for (int j = 0; j + M <= N; ++j) {
                boolean flag = true;
                for (int k = 0; k < M; ++k) {
                    for (int l = 0; l < M; ++l) {
                        if (!BOARD_S[i+k][i+l].equals(BOARD_T[k][l])) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag == false) {
                        break;
                    }
                }
                if (flag) {
                    System.out.println((i + 1) + " " + (j + 1));
                    sc.close();
                    return;
                }
            }
        }

        sc.close();

    }
}
