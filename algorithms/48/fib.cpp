#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void mult(long long A[2][2], long long B[2][2]){
	long long q,w,e,r;
	q=A[0][0]*B[0][0]+A[0][1]*B[1][0];
	w=A[0][0]*B[0][1]+A[0][1]*B[1][1];
	e=A[1][0]*B[0][0]+A[1][1]*B[1][0];
	r=A[1][0]*B[0][1]+A[1][1]*B[1][1];
	A[0][0]=q;
	A[0][1]=w;
	A[1][0]=e;
	A[1][1]=r;
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
