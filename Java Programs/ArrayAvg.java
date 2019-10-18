import java.util.Scanner;

public class ArrayAvg {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of array elements : ");
        int n = sc.nextInt();
        int[] a = new int[n];

        int sum = 0;
        double avg = 0.0;

        System.out.println("Enter the array element :");
        for (int i=0;i<n;i++){
            a[i] = sc.nextInt();
            sum += a[i];
        }
        sc.close();

        avg = sum/n;
        System.out.println("Average of all the elements = "+avg);
    }
}
