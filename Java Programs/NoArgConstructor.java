public class NoArgConstructor {
    // instance variable
    int i;

    // constructor with no parameter
    public NoArgConstructor(){
        i = 5;
        System.out.println("Object created and i = " + i);
    }

    // Driver Code
    public static void main(String[] args) {
        NoArgConstructor obj = new NoArgConstructor();
    }
}
