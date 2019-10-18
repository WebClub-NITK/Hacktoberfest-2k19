import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SwapNumbers {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Enter two numbers :");
        double x = Double.parseDouble(br.readLine());
        double y = Double.parseDouble(br.readLine());
        br.close();

        System.out.println("Before Swapping");
        System.out.println("x = "+x+"\ny = "+y);

        //Swaping
        x = x + y; // x = 5 + 8
        y = x - y; // y = 5 + 8  -  8
        x = x - y; // x = 5 + 8  -  5

        System.out.println("After Swapping");
        System.out.println("x = "+x+"\ny = "+y);
    }
}
