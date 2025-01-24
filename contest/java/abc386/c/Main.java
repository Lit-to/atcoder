import java.util.*;
import java.io.*;

public class Main {
    //ABC386C
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        sc.nextLine();
        String S = sc.nextLine();
        String T = sc.nextLine();
        int s_length = S.length();
        int t_length = T.length();
        boolean is_ok;
        if (s_length == t_length) {
            is_ok = check(S, T);
        } else if (s_length < t_length) {
            is_ok = check(S, T, s_length);
        } else {
            is_ok = check(T, S, t_length);
        }

        if (is_ok) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
        sc.close();
    }

    public static boolean check(String S, String T, int length) {
        boolean skip = false;
        int i = 0;
        int j = 0;
        while (i < length && j < length) {
            if (S.charAt(i) == T.charAt(j)) {
                ++i;
                ++j;
                continue;
            } else {
                if (skip) {
                    return false;
                } else {
                    ++j;
                    skip = true;
                }
            }
        }
        return true;
    }

    public static boolean check(String S, String T) {
        int diff = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (S.charAt(i) != T.charAt(i)) {
                ++diff;
            }
        }
        return diff <= 1;

    }
}
