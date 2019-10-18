public class MethodOverloading{

    public static void area(int s){
        System.out.println("Area = "+(s*s));
    }

    public static void area(int l, int b){
        System.out.println("Area = "+(l*b));
    }

    public static void area(double r){
        System.out.println("Area = "+(Math.PI*r*r));
    }
}

class Result{
    public static void main(String[] args){
        MethodOverloading ob = new MethodOverloading();
        ob.area(7.5);
        ob.area(15, 85);
        ob.area(12);
    }
}

