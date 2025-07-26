// ABC391C

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] NQ = sc.nextLine().split(" ");
        int N = Integer.parseInt(NQ[0]);
        int Q = Integer.parseInt(NQ[1]);
        int[] nest = new int[N];
        int[] pigeon = new int[N];
        for (int i = 0; i < N; ++i) {
            nest[i] = 1;
            pigeon[i] = i;
        }
        int result=0;
        for (int i = 0; i < Q; ++i) {
            String query = sc.nextLine();
            if (query.equals("2")) {
                System.out.println(result);
            } else {
                String[] query_1 = query.split(" ");
                int p = Integer.parseInt(query_1[1]);
                int h = Integer.parseInt(query_1[2]);
                --nest[pigeon[p-1]];
                if (nest[pigeon[p-1]]==1){
                    --result;
                }
                pigeon[p-1]=h-1;
                ++nest[pigeon[p-1]];
                if (nest[pigeon[p-1]]==2){
                    ++result;
                }

            }
        }
        sc.close();
    }
}
