import java.util.Scanner;

public class NestedConditionalOperator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        sc.close();

        int x = a>=b ? (a>=c ? a : c)  : (b>=c ? b : c);
        System.out.println("The Largest Number is "+ x);
    }
}
