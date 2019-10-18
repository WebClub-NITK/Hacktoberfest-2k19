import java.util.Scanner;

public class SquareMethod2 {
    // method defined
    private static int getSquare(int x){
        return x * x;
    }

    //Driver method main()
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter any number : ");
        int N = sc.nextInt();
        sc.close();
        int result;
        for (int i = 1; i <= N; i++) {
            // method call
            result = getSquare(i);
            System.out.println("Square of " + i + " is : " + result); }
    }
}
