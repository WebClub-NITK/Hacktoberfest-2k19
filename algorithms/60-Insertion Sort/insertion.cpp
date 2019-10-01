// C++ program for insertion sort  
#include <bits/stdc++.h> 
using namespace std; 
void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  
  
void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
}  

int main()  
{  
    cout<<"Enter the no. of elements in array:";
    int n=0;
    cin >> n;
    int arr[n];
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<n;i++)
        cin >> arr[i]; 
  
    insertionSort(arr, n);  
    printArray(arr, n);  
    return 0;  
} 