import java.util.Scanner;

public class ParaConstructor {

    int l, b;   // instance variable

    // Parameterised constructor
    public ParaConstructor(int Length, int Breadth)
    {
        l = Length;
        b = Breadth;
    }

    public void area(){
        System.out.println("Area of Rectangle : "+ (l*b));
    }

    // Driver Code
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Length and Breadth of Rectangle : ");
        int ll = sc.nextInt();
        int bb = sc.nextInt();
        sc.close();

        ParaConstructor ob = new ParaConstructor(ll, bb);
        ob.area();
    }
}
