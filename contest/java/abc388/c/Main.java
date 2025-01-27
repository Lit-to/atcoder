import java.util.*;
// import java.util.function.Function;

// import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.nextLine());
        String[] A = sc.nextLine().split(" "); 
    }
    public static int search(int ok,int ng){
        while (1<Math.abs(ok-ng)){
            int mid = (ok+ng)/2;
            if (check(mid)){
                ng=mid;
            }
            else{
                ok=mid;
            }
        }
        return ok;
    }
    public static boolean check(int mid){
        return true;

    }
}