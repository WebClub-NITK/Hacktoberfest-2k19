#include <stdio.h>

// the input array to be sorted
int arr[100];
// the array used to store the temporary results in the function
int temp[100];

void merge_sort(int start_index, int end_index)
{
	int mid = (start_index + end_index) / 2;

	// sort the left half and the right half of the array
	merge_sort(start_index, mid);
	merge_sort(mid + 1, end_index);

	// compare the two sorted arrays using first element and merge them into temp
	int curr_left_index = start_index;
	int curr_right_index = mid + 1;
	int curr_index = start_index;
	while (curr_left_index <= mid && curr_right_index <= end_index)
	{
		if (arr[curr_left_index] <= arr[curr_right_index])
		{
			temp[curr_index] = arr[curr_left_index];
			curr_left_index++;
		}
		else
		{
			temp[curr_index] = arr[curr_right_index];
			curr_right_index++;
		}
		curr_index++;
	}

	// if all the elements from left array are not used, add them to temp
	while (curr_left_index <= mid)
	{
		temp[curr_index] = arr[curr_left_index];
		curr_left_index++;
		curr_index++;
	}

	// if all the elements from right array are not used, add them to temp
	while (curr_right_index <= end_index)
	{
		temp[curr_index] = arr[curr_right_index];
		curr_right_index++;
		curr_index++;
	}

	// copy all the elements from temp to the main array
	for (int i = start_index; i <= end_index; i++)
	{
		arr[i] = temp[i];
	}
}

int main()
{
	int n;
	printf("Enter the number of elements in the array:\n");
	scanf("%d", &n);
	printf("Enter the array elements:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	merge_sort(0, n - 1);
	printf("The array after sorting is:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}