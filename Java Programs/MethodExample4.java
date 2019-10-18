public class MethodExample4 {
    public static void main(String[] args) {
        int result, n;

        n = 3;
        result = square(n);
        System.out.println("Square of 3 is: " + result);

        n = 4;
        result = square(n);
        System.out.println("Square of 4 is: " + result);
    }
    static int square(int i) {
        return i * i;
    }
}
