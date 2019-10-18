class Output1{
    public void myMethod() {
        System.out.println("Printing from inside myMethod().");
    }
}

public class MethodExample3 {
    public static void main(String[] args) {
        Output1 obj = new Output1();
        System.out.println("About to encounter a method.");
        // calling myMethod() of Output class
        obj.myMethod();
        System.out.println("Method was executed successfully!");
    }
}