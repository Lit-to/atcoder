import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        sc.nextLine();
        // int K = 1;
        String S = sc.nextLine();
        String T = sc.nextLine();
        boolean is_ok;
        if (1 < Math.abs(S.length() - T.length())) {
            System.out.println("No");
            sc.close();
            return;
        }
        if (S.length() == T.length()) {
            is_ok = check(S, T);
        } else if (S.length() < T.length()) {
            is_ok = check(T, S, S.length());
        } else {
            is_ok = check(S, T, T.length());
        }
        if (is_ok){
            System.out.println("Yes");
            sc.close();
            return;
        }
        else{
            System.out.println("No");
            sc.close();
            return;
        }

    }

    public static boolean check(String S, String T, int length) {
        // Tが長いという前提,lengthは短いほうの長さ
        int i = 0;
        int j = 0;
        while (i < length && j < length + 1) {
            if (1 < (j - i)) {
                return false;
            }
            if (S.charAt(i) == T.charAt(j)) {
                ++i;
                ++j;
                continue;
            } else {
                ++i;
            }
        }
        return true;
    }

    public static boolean check(String S, String T) {
        int count = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (S.charAt(i) == T.charAt(i)) {
                continue;
            } else {
                ++count;
            }
        }
        return count < 2;
    }
}
