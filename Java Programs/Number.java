import java.util.Scanner;

public class Number {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();
        sc.close();

        if(number > 0)
            System.out.println("The number is positive");
        else if(number < 0)
            System.out.println("The number is negative");
        else
            System.out.println("The number is zero");
    }
}
