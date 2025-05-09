
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int[] A = sc.nextIntLn(4);
        int[] cards = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 };
        for (int i = 0; i < 4; ++i) {
            cards[A[i] - 1]++;
        }
        int count = 0;
        for (int i = 0; i < 13; ++i) {
            if (cards[i] != 0) {
                count++;
            }
        }
        if (count == 2) {
            yes();
        } else {
            no();
        }
        out.close();
    }

    public static void print(Object obj) {
        System.out.println(obj);
    }

    public static void yes() {
        System.out.println("Yes");
        System.exit(0);
    }

    public static void no() {
        System.out.println("No");
        System.exit(0);
    }

    public static void printlne(Object obj) {
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
