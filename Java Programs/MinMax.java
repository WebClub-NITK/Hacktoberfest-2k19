import java.util.Scanner;

public class MinMax {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of array elements : ");
        int n = sc.nextInt();
        int[] a = new int[n];

        System.out.println("Enter the Array elements :");
        for (int i =0;i<n;i++){
            a[i] = sc.nextInt();
        }
        int min = a[0],max=a[0];

        for(int i =1; i<n ; i++){
            if(min > a[i])
                min = a[i];
            if(max < a[i])
                max = a[i];
        }
        System.out.println("\nMinimum = "+min+"\nMaximum = "+max);
    }
}
