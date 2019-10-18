class Output {
    // public: this method can be called from outside the class
    public void myMethod() {
        System.out.println("Printing from inside myMethod().");
    }
}


public class MethodExample2 {
    public static void main(String[] args) {
        Output obj = new Output();

        System.out.println("About to encounter a method.");

        // calling myMethod() of Output class
        obj.myMethod();
        System.out.println("Method was executed successfully!");
    }
}