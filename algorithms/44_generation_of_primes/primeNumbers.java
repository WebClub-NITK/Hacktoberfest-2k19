// package <PACKAGE NAME HERE>;

public class primeNumbers {
	
	public static int main(int low, int high) {
		try {
			for(int i = low; i <= high; ++i) {
			    boolean prime = true;
			    for(int j = 2; j < i; ++j) {
			        if(i % j == 0) {
			            prime = false;
			        }
			    }
			    if(prime) {
			        return i;
			    }
			}  
		} catch (Exception e) {
			System.out.println(e);
		}
		
	}

}
