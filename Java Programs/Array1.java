public class Array1 {
    public static void main(String[] args) {
        int[] a = new int[10];
        int[] b = {1,2,4,8,16,32,64,128};

        for(int i = 0;i<10;i++){
            a[i] = i+1;
        }
        System.out.println("The array element of a");
        for (int i=0;i<10;i++){
            System.out.print(a[i]+" ");
        }
        System.out.println("\nThe array element of b");
        for(int i=0;i<b.length;i++){
            System.out.print(b[i]+" ");
        }
    }
}
