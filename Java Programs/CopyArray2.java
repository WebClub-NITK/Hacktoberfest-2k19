public class CopyArray2 {
    public static void main(String[] args) {

        int [] numbers = {1, 2, 3, 4, 5, 6};
        int [] positiveNumbers = numbers;    // copying arrays

        numbers[0] = -1;
        for (int number: positiveNumbers) {
            System.out.print(number + ", ");
        }
    }
}
