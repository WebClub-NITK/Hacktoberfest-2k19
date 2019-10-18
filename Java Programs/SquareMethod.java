import java.util.Scanner;

public class SquareMethod {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter any number : ");
        int n = sc.nextInt();
        sc.close();

        int result;
        result = square(n);
        System.out.println("Squared value of "+n+" is: " + result);
    }

    public static int square(int x) {
        // return statement
        return x * x;
    }
}
