// ABC391 a

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String D = sc.nextLine();
        switch (D) {
            case "N":
                System.out.println("S");
                break;
            case "S":
                System.out.println("N");
                break;
            case "E":
                System.out.println("W");
                break;
            case "W":
                System.out.println("E");
                break;
            case "NE":
                System.out.println("SW");
                break;
            case "SW":
                System.out.println("NE");
                break;
            case "NW":
                System.out.println("SE");
                break;
            case "SE":
                System.out.println("NW");
                break;
            }
        sc.close();
        

    }
}
