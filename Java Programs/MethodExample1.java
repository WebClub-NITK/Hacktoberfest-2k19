public class MethodExample1 {
    public static void main(String[] args) {
        System.out.println("About to encounter a method.");
        // method call
        myMethod();
        System.out.println("Method was executed successfully!");
    }
    // method definition
    private static void myMethod(){
        System.out.println("Printing from inside myMethod()!");
    }
}
