import java.util.*;

public class Main {
    //ABC383C
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] HWD = sc.nextLine().split(" ");
        int H = Integer.parseInt(HWD[0]);
        int W = Integer.parseInt(HWD[1]);
        int D = Integer.parseInt(HWD[2]);
        char[] BOARD = new char[H * W];
        String[] input = sc.nextLine().split(" ");
        final int[][] RLUD_CHECK = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };
        final int[] RLUD = { 1, -1, -W, W };

        Deque<int[]> queue = new ArrayDeque<int[]>();
        Set<Integer> done = new HashSet<Integer>();
        for (int i = 0; i < H * W; ++i) {
            if (W <= i && i % W == 0) {
                input = sc.nextLine().split(" ");
            }
            char item = input[0].charAt(i % W);
            BOARD[i] = item;
            if (item == 'H') {
                int[] floor = { i, 0 };
                queue.push(floor);
                done.add(i);
            }
        }
        int result = 0;
        while (0 < queue.size()) {
            int[] item = queue.removeFirst();
            int pos = item[0];
            int count = item[1];
            ++result;
            for (int i = 0; i < 4; ++i) {
                if (check(pos, H, W, RLUD_CHECK[i])) {
                    int next = pos + RLUD[i];
                    int[] pack = { next, count + 1 };
                    if (BOARD[next] != '#' && !done.contains(next) && pack[1] <= D) {
                        done.add(next);
                        queue.add(pack);
                    }
                }
            }

        }
        System.out.println(done.size());
        // System.out.println(result);

    }

    public static boolean check(int pos, int H, int W, int[] diff) {
        int y = pos / W + diff[0];
        int x = pos % W + diff[1];
        return (0 <= y && y < H) && (0 <= x && x < W);

    }
}
//0 1 16 23 25 26 27 28 29