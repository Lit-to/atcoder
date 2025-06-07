import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] S = sc.nextLine().split(" ");
        for (int i=0;i<4;++i){
            String[] T = S.clone();
            String temp=T[i];
            T[i]=String.valueOf(T[i+1]);
            T[i+1]=temp;
            if (check(T)){
                System.out.println("Yes");
                sc.close();
                return;
            }
        }
        System.out.println("No");
        sc.close();
        return;

    }
    public static boolean check(String[] target){
        if (!target[0].equals("1")){
            return false;
        }
        if (!target[1].equals("2")){
            return false;
        }
        if (!target[2].equals("3")){
            return false;
        }
        if (!target[3].equals("4")){
            return false;
        }
        if (!target[4].equals("5")){
            return false;
        }
        return true;
    }
}
