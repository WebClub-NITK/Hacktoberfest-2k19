import java.util.Scanner;
class Calculator {
    public static void main(String[] args) {
        char operator;
        double number1, number2, result;

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter operator (either +, -, * or /): ");
        operator = scanner.next().charAt(0);
        System.out.print("Enter number1 and number2 respectively: ");
        number1 = scanner.nextDouble();
        number2 = scanner.nextDouble();
        scanner.close();
        
        switch (operator) {
            case '+':
                result = number1 + number2;
                System.out.print(number1 + "+" + number2 + " = " + result);
                break;
            case '-':
                result = number1 - number2;
                System.out.print(number1 + "-" + number2 + " = " + result);
                break;
            case '*':
                result = number1 * number2;
                System.out.print(number1 + "*" + number2 + " = " + result);
                break;
            case '/':
                result = number1 / number2;
                System.out.print(number1 + "/" + number2 + " = " + result);
                break;
            default:
                System.out.println("Invalid operator!");
                break;
        }
    }
}