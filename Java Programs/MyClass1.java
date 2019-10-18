public class MyClass1 {

    // instance Variable
    int instVar;

    // Parameterised Constructor
    public MyClass1(int instVar){
        this.instVar = instVar;
    }
    public static void main(String[] args) {
        MyClass1 ob = new MyClass1(8);
        System.out.println("ob.instVar = " + ob.instVar);
    }
}
