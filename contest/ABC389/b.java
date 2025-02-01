
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        long X = sc.nextLong();
        for (int i=1;i<21;++i){
            if (factrial(i)==X){
                System.out.println(i);
            }
        }
        sc.close();
        return;
    }

    public static long factrial(long n) {
        if (n<1) {
            return 1;
        } else {
            return factrial(n - 1) * n;
        }
    }
}
