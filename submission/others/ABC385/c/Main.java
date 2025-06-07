import java.io.*;
import java.util.*;

public class Main {
    // ABC385B RE
    public static void main(String[] args) throws Exception {
        FastScanner sc = new FastScanner(); // 標準入力受け取り用おまじない
        int[] HWXY = sc.nextIntLn(4);
        int H = HWXY[0];
        int W = HWXY[1];
        int X = HWXY[2];
        int Y = HWXY[3];

        String[][] BOARD = new String[H][W];
        for (int i = 0; i < H; i++) {
            BOARD[i] = sc.nextStrings();
        }

        String[] T = sc.nextStrings();
        int Q = T.length;
        // 処理
        int[] pos = { X, Y };
        HashSet<Integer> result = new HashSet<>();
        for (int i = 0; i < Q; i++) {
            // System.out.println(Integer.toString(pos[0])+" "+Integer.toString(pos[1]));
            int[] previous=new int[2];
            previous[0]=pos[0];
            previous[1]=pos[1];
            if (T[i].equals("R")) {
                pos[1] = Math.min(W - 1, pos[1] + 1);
            } else if (T[i].equals("L")) {
                pos[1] = Math.max(0, pos[1] - 1);
            } else if (T[i].equals("D")) {
                pos[0] = Math.min(H - 1, pos[0] + 1);
            } else if (T[i].equals("U")) {
                pos[0] = Math.max(0, pos[0] - 1);
            }
            if (BOARD[pos[0]-1][pos[1]-1].equals("@")) {
                result.add(H * pos[0] + pos[1]);
            }
            else if (BOARD[pos[0]-1][pos[1]-1].equals("#")){
                pos[0]=previous[0];
                pos[1]=previous[1];
            }
        }
        int[] ans ={pos[0],pos[1],result.size()};
        System.out.println(Integer.toString(ans[0])+" "+Integer.toString(ans[1])+" "+Integer.toString(ans[2]));

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

    public String[] nextStrings() {
        String s = next();
        int n = s.length();
        String[] result = new String[n];
        for (int i = 0; i < n; i++) {
            result[i] = s.substring(i, i + 1);
        }
        return result;
    }
}
