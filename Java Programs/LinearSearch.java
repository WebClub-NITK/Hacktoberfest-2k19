import java.util.Scanner;

public class LinearSearch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of array elements : ");
        int n = sc.nextInt();
        int[] a = new int[n];

        System.out.println("Enter the Array elements :");
        for (int i =0;i<n;i++){
            a[i] = sc.nextInt();
        }

        System.out.println("Enter the element to be search : ");
        int s = sc.nextInt();

        sc.close();

        for(int i=0;i<n;i++){
            if (s==a[i])
                System.out.println("Element found at position "+(i+1));
        }
    }
}
