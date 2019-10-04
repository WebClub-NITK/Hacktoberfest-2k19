#include<bits/stdc++.h>
using namespace std;

int get_max(int arr[],int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

void count_sort(int A[],int n,int pos){
    
    int count[10]={0};
    int b[n];
    
    for(int i=0;i<n;i++){
        
        ++count[(A[i]/pos)%10];
    }
    
    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    
    for(int i=n-1;i>=0;i--){
        
        b[--count[(A[i]/pos)%10]]=A[i];
    }
    
    for(int i=0;i<n;i++){
        A[i]=b[i];
    }
    
}


void radix_sort(int arr[],int n){
    
    int max=get_max(arr,n);
    int pos;
    for(pos=1;max/pos>0;pos*=10){
        count_sort(arr,n,pos);
    }
}


int main(){
    cout<<"Enter no. of elements";
    int n;
    cin>>n;
    cout<<"Enter array elements:"<<endl;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    radix_sort(a,n);
    
    
    cout<<"Sorted elements:"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
