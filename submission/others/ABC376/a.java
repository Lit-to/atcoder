// ABC376 a

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] NC = sc.nextLine().split(" ");
        int N = Integer.parseInt(NC[0]);
        int C = Integer.parseInt(NC[1]);
        String[] T = sc.nextLine().split(" ");
        int i=0;
        int time = 0;
        int cooltime = 0;
        int candy=0;
        while (i<N){
            if (0<cooltime){
                --cooltime;
            } 
            if (Integer.parseInt(T[i])==time){
                ++i;
                if (cooltime<=0){
                    cooltime=C;
                    ++candy;
                }
            }
            ++time;
        }
        System.out.println(candy);

        sc.close();
    }
}
