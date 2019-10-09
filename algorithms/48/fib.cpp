#include <iostream>
using namespace std;

//to perform matrix multiplication of 2 2*2 matrices
void mult(long long A[2][2], long long B[2][2]){
	//make variables for the terms in the answer matrix
	long long ans00, ans01, ans10, ans11;
	ans00=A[0][0]*B[0][0]+A[0][1]*B[1][0];
	ans01=A[0][0]*B[0][1]+A[0][1]*B[1][1];
	ans10=A[1][0]*B[0][0]+A[1][1]*B[1][0];
	ans11=A[1][0]*B[0][1]+A[1][1]*B[1][1];
	A[0][0]=ans00;
	A[0][1]=ans01;
	A[1][0]=ans10;
	A[1][1]=ans11;
}

void matrix_pow(long long A[2][2], int n){
	long long M[2][2]={{1,1},{1,0}};
	for(int i=2;i<n;i++){
		mult(A, M);
	}
	return;
}


// returns the nth fibonacci number
long long fib(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    long long A[2][2]={{1,1},{1,0}};
    matrix_pow(A, n);
    return A[0][0];
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "The " << n << "th fibonacci number is " << fib(n) << endl;
    return 0;
}
