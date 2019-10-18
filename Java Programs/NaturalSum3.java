import java.util.Scanner;

public class NaturalSum3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.close();

        int i=0,sum = 0;
        do{
            ++i;
            sum += i;
        }while (i<=N);

        System.out.println("Sum = "+sum);
    }
}

