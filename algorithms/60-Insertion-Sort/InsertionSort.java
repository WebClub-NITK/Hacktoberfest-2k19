import java.util.Arrays;

/*
 * INSERTION SORT
 * In this algorithm I have sorted a array of 6 element named list 
 * The sorting is done in ascending order. If we want to sort in descending order than
 * just change the condition in line 28 to less than
 * 
 */


class InsertionSort{
    public static void main(String args[]){
    	int temp; //for storing integer temporarily used for swapping
        int list[] = {5,13,6,9,2,8}; // Array of unsorted numbers
        
        //Output the unsorted array in one line String format using Arrays.toString()
        System.out.println("The unsorted list is: " + Arrays.toString(list));
        
        //External loop for looping over elements of whole array
        for(int i = 1; i<list.length;i++){
            int key = list[i];
            
            //Internal Loop for looping from the current element (key)
            inner:
            for(int j=i-1;j>=0;j--){
            	//Checking the condition whether the key is less than previous element
                if(list[j]>key) {
                	//if the condition is true than swap using temp variable
                	temp = list[j]; //store the previous element in temp
                	list[j] = key; //store the key in previous element position
                	list[j+1] = temp; //store temp in current element position
                }
                /* 
                 * break from inner loop in case of the above condition is false 
                 * so as to stop loop that helps us to save computation resoure 
                 */
                else break inner; 
            }
        }
        
        //Output the sorted array in String format after Insertion Sorting
        System.out.println("The unsorted list is: " + Arrays.toString(list));
    }
    
}