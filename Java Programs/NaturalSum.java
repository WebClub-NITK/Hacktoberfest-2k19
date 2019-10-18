import java.util.Scanner;

public class NaturalSum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number : ");
        int N = sc.nextInt();
        sc.close();
        int sum = 0;
        for (int i = 1 ; i <= N; i++){
            sum += i; //sum = sum + i
        }
        System.out.println("Sum = "+sum);
    }
}
