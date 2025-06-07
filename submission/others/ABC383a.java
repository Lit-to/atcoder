import java.io.*;
import java.util.*;

public class Main {
    // ABC383A
    public static void main(String[] args) throws Exception {
        FastScanner sc = new FastScanner();
        int N = sc.nextInt();
        int[][] TV = new int[N][2];
        for (int i=0;i<N;++i){
            TV[i] = sc.nextIntLn(2);
        }
        int water =0;
        int previousTime=0;
        for (int i=0;i<N;++i){
            water -= TV[i][0]-previousTime;
            previousTime=TV[i][0];
            water = Math.max(0,water);
            water += TV[i][1];
        }
        print(water);
        return;
    }

    // 以下、便利関数
    public static void print(Object obj) {
        PrintWriter out = new PrintWriter(System.out);
        out.println(obj);
        out.close();
    }

    public static void print(Object[] obj, String sep) {
        PrintWriter out = new PrintWriter(System.out);
        for (int i = 0; i < obj.length; ++i) {
            out.print(obj[i]);
            out.print(sep);
        }
        out.print("\n");
        out.close();
    }

    public static void print(Object[] obj) {
        print(obj, "\n");
    }

    public static void yes() {
        System.out.println("Yes");
        System.exit(0);
    }

    public static void yes(boolean condition) {
        if (condition) {
            yes();
        }
    }

    public static void no() {
        System.out.println("No");
        System.exit(0);
    }

    public static void no(boolean condition) {
        if (condition) {
            no();
        }
    }

    public static void yn(boolean condition) {
        if (condition) {
            yes();
        } else {
            no();
        }
    }

    public static void printAndEnd(Object obj) {
        System.out.println(obj.toString());
        System.exit(0);
    }
}

class FastScanner {

    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        } else {
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }

    private int readByte() {
        if (hasNextByte()) {
            return buffer[ptr++];
        } else {
            return -1;

        }
    }

    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    private void skipUnprintable() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) {
            ptr++;

        }
    }

    public boolean hasNext() {
        skipUnprintable();
        return hasNextByte();
    }

    public String next() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    public long nextLong() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }

    public int nextInt() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        int n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }

    public String[] nextStrLn(int n) {
        String[] str = new String[n];
        for (int i = 0; i < n; i++) {
            str[i] = next();
        }
        return str;
    }

    public long[] nextLongLn(int n) {
        long[] longs = new long[n];
        for (int i = 0; i < n; i++) {
            longs[i] = nextLong();
        }
        return longs;
    }

    public int[] nextIntLn(int n) {
        int[] ints = new int[n];
        for (int i = 0; i < n; i++) {
            ints[i] = nextInt();
        }
        return ints;
    }
}
