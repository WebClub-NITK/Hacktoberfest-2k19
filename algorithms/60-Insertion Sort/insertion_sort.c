#include <stdio.h>

void insertionSort(int a[], int l) {
	int i, j, k;

	// Sort elements one by one
	// starting from element at index 1
	for (i = 1; i < l; i++) {
		k = a[i];
		j = i - 1;

		// Shift greater elements to right
		while (j >= 0 && a[j] > k) {
			a[j + 1] = a[j];
			j--;
		}

		// Put element at correct location
		// which is at (j + 1)
		a[j + 1] = k;
	}
}

// driver code to check the program
int main(int argc, char *argv[]) {
	int a[] = {5, 4, 2, 1, 3};
	int l = sizeof(a) / sizeof(int);

	insertionSort(a, l);

	for (int i = 0; i < l; i++) printf("%d, ", a[i]);
	puts("End");

	return 0;
}