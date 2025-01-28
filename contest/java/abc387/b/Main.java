import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Q = Integer.parseInt(sc.nextLine());
        int[] QUERY = new int[Q];
        long[] CONTENT = new long[Q];
        ArrayList<Long> queue = new ArrayList<Long>();
        for (int i = 0; i < Q; ++i) {
            String[] query = sc.nextLine().split(" ");
            if (!query[0].equals("2")) {
                QUERY[i] = (int) query[0].charAt(0) - '0';
                CONTENT[i] = Long.parseLong(query[1]);
            } else {
                QUERY[i] = 2;
                CONTENT[i] = -1;
            }
        }
        long last = 0;
        int first = 0;
        long cut = 0;
        for (int i = 0; i < Q; ++i) {
            if (QUERY[i] == 1) {
                last += CONTENT[i];
                queue.add(last);
            } else if (QUERY[i] == 2) {
                if (0 < queue.size()) {
                    cut = queue.get(first);
                    ++first;
                }
            } else {
                System.out.println(queue.get(first + (int) CONTENT[i] - 2) - cut);
            }

        }
        sc.close();

    }
}
