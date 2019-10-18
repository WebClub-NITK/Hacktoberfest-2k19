import java.util.Scanner;

public class LargestNumber2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Double n1 = sc.nextDouble();
        Double n2 = sc.nextDouble();
        Double n3 = sc.nextDouble();
        sc.close();

        Double largestNumber;
        if (n1 >= n2)
        {
            if (n1 >= n3) {
                largestNumber = n1;
            } else {
                largestNumber = n3;
            }
        }
        else
        {
            if (n2 >= n3) {
                largestNumber = n2;
            } else {
                largestNumber = n3;
            }
        }
        System.out.println("Largest number is " + largestNumber);
    }
}
