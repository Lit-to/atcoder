
import java.io.*;
import java.util.*;

public class Main {
    // ABC385B
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        String S = sc.nextLine();
        System.out.println((Character.getNumericValue(S.charAt(0)) * (Character.getNumericValue(S.charAt(2)))));
        sc.close();
    }
}
