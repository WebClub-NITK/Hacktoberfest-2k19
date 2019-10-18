import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Sequence1 {
    public static void main(String[] args) throws IOException {

        //Input_from_Keyword is the name of the object of InputStreamReader
        InputStreamReader Input_from_Keyword = new InputStreamReader(System.in);

        //br is the name of the object of BufferedReader
        BufferedReader br = new BufferedReader(Input_from_Keyword);

        //Taking the number of terms
        System.out.print("Enter any Number :");
        int n = Integer.parseInt(br.readLine());
        br.close();

        int d;

        //Printing the Sequence
        System.out.println("The Sequence :");
        for (int i=1; i<=n ; i++){
            d = (int) (Math.pow(i,2) - 1);
            if(i != n)
                System.out.print(d+", ");
            else
                System.out.print(d+".");
        }
    }
}
