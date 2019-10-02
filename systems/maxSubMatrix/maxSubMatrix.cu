#include<bits/stdc++.h>
using namespace std;

__global__
void MaxSizeSubMat(int* d_Matrix, int* d_Soln, int* d_clmns, int* d_rows, int* N) {
	int threadId = threadIdx.x, i , j;
	if(*N >= (*d_clmns + *d_rows)/2) {
		i = *d_rows - (threadId + 1);
		j = *N + threadId + 2 - *d_rows;
	} else {
		i = *N - threadId;
		j = threadId + 1;
	}
	if(j >= *d_clmns || j <= 0 || i <= 0 || i >= *d_rows) {
		return;
	}
	if(d_Matrix[ (*d_clmns * i) + j ] == 1) {

		int a = d_Soln[ (*d_clmns * i) + j-1];
		int b = d_Soln[ (*d_clmns * (i-1)) + j ];
		int c = d_Soln[ (*d_clmns * (i-1)) + j -1 ];

		if(a <= b && a <= c) {
			d_Soln[ (*d_clmns * i) + j ] = a + 1;
		} else if(b <= c && b <= a) {
			d_Soln[ (*d_clmns * i) + j ] = b + 1;
		}else {
			d_Soln[ (*d_clmns * i) + j ] = c + 1;
		}

	} else {
		d_Soln[ (*d_clmns * i) + j ] = 0;
	}
	
	__syncthreads();
	if(threadId == 0) {
		*N += 1;
	}
}
int main() {
	int intsize = sizeof(int) ;
	int h_rows, h_clmns;

	cout << "Enter the Number of rows in the matrix." << endl;
	cin >> h_rows;
	cout << "Enter the Number of columns in the matrix." << endl;
	cin >> h_clmns;

	int h_Matrx[h_rows][h_clmns];

	int  h_Soln[h_rows][h_clmns];
	cout << "Enter the elements of the matrix.\n";
	for(int i = 0; i < h_rows; i++) {
		for(int j = 0; j < h_clmns; j++) {
			cin >> h_Matrx[i][j];
			if(i == 0 || j == 0) {
				h_Soln[i][j] = h_Matrx[i][j];
			} else {
				h_Soln[i][j] = 0;
			}
		}
	}

	int *d_Matrix, *d_clmns, *d_Soln, *d_rows;

	cudaMalloc((void**)&d_Matrix, h_rows * h_clmns * intsize);
	cudaMalloc((void**)&d_Soln, h_rows * h_clmns * intsize);
	cudaMalloc((void**)&d_clmns, intsize);
	cudaMalloc((void**)&d_rows, intsize);

	cudaMemcpy( d_Matrix, h_Matrx, h_rows * h_clmns * intsize, cudaMemcpyHostToDevice);
	cudaMemcpy( d_Soln, h_Soln, h_rows * h_clmns * intsize, cudaMemcpyHostToDevice);
	cudaMemcpy(d_clmns, &h_clmns, intsize, cudaMemcpyHostToDevice);
	cudaMemcpy(d_rows, &h_rows, intsize, cudaMemcpyHostToDevice);

	int n = (h_rows + h_clmns - 3), *N;

	cudaMalloc((void**)&N, intsize);

	int i = 1;

	cudaMemcpy( N, &i, intsize, cudaMemcpyHostToDevice);

	for(int i = 1; i <= (n + 1)/2; i++) {
		MaxSizeSubMat<<<1,i>>> (d_Matrix, d_Soln, d_clmns, d_rows, N);
	}

	for(int i = (n + 3)/2; i <= n ; i++ ) {
		MaxSizeSubMat<<<1, (n - i + 1)>>> (d_Matrix, d_Soln, d_clmns, d_rows, N);
	}
	
	cudaMemcpy( h_Soln, d_Soln, h_rows * h_clmns * intsize, cudaMemcpyDeviceToHost);

	int max = h_Soln[0][0];

	for(int i = 0; i < h_rows; i++) {
		for(int j = 0; j < h_clmns; j++) {
			if(max < h_Soln[i][j]) {
				max = h_Soln[i][j];
			}
	}
	cout << "Max area is " << max * max << ".\n";

	cudaFree(d_Matrix); cudaFree(d_Soln);
}

