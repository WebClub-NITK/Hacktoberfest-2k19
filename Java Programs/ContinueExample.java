public class ContinueExample {
    public static void main(String[] args) {

        for (int i = 0; i < 10; i++) {
            if (i == 4) {
                continue;
            }
            System.out.println(i);
        }

    }
}
