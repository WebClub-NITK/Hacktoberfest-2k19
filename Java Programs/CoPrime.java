import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class CoPrime {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter Two Numbers");
        int x = Integer.parseInt(br.readLine());
        int y = Integer.parseInt(br.readLine());
        br.close();

        int min = Math.min(x, y);
        int h = 1;
        for (int i = 1; i <= min; i++) {
            if (x % i == 0 && y % i == 0)
                h = i;
        }
        if (h == 1)
            System.out.println("Numbers are coprime");
        else
            System.out.println("Numbers are not coprime");
    }
}