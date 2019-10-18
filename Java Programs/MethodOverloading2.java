import java.util.Scanner;

public class MethodOverloading2 {
    public void vol(double r){
        System.out.println("Volume = "+(4/3.0 * r*r*r*Math.PI));
    }

    public void vol(int l, int b, int h){
        System.out.println("Volume = "+(l*b*h));
    }
    public void vol(int s){
        System.out.println("Volume = "+(s*s*s));
    }
}

class Result2{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the l, b,h for cuboid :" );
        int l = sc.nextInt();
        int b = sc.nextInt();
        int h = sc.nextInt();
        sc.close();

        MethodOverloading2 ob = new MethodOverloading2();
        ob.vol(l,b,h);
        ob.vol(56.3);
        ob.vol(55);
    }
}
