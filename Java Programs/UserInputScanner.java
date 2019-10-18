import java.util.Scanner;
public class UserInputScanner {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        System.out.println("Enter any number : ");
        int i = scan.nextInt();
        System.out.println("Enter any floating number : ");
        double d = scan.nextDouble();

        //Clearing BufferMemory
        scan.nextLine();
        System.out.println("Enter any string : ");
        String s = scan.nextLine();

        scan.close();

        System.out.println("String: " + s);
        System.out.println("Double: " + d);
        System.out.println("Int: " + i);

    }
}
