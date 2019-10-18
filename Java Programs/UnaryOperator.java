public class UnaryOperator {
    public static void main(String[] args) {

        double number = 5.2, resultNumber;
        boolean flag = false;

        System.out.println("+number = " + +number);
        // number is equal to 5.2 here.

        System.out.println("-number = " + -number);
        // number is equal to 5.2 here.

        // ++number is equivalent to number = number + 1
        System.out.println("number = " + ++number);
        // number is equal to 6.2 here.
        // -- number is equivalent to number = number - 1
        System.out.println("number = " + number-- );
        // number is equal to 5.2 here.
        System.out.println("!flag = " + !flag);
        // flag is still false.
    }
}
