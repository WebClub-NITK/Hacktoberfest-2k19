import java.util.Scanner;

public class NaturalSum2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.close();

        int i=1,sum = 0;
        while (i<=N){
            sum += i;
            ++i;
        }
        System.out.println("Sum = "+sum);
    }
}
