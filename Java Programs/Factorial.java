public class Factorial {

    // static function
    static int factorial( int n ) {
        if (n != 0)
            return n * factorial(n-1); // recursive call
        else
            return 1;
    }

    // Driver code
    public static void main(String[] args) {
        int number = 4, result;
        result = factorial(number);
        System.out.println(number + " factorial = " + result);
    }
}
