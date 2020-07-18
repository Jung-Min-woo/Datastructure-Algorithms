#include <stdio.h>
void Swap(int[], int, int);
int Partition(int[], int, int);
void QuickSort(int[], int, int);
int main(void) {
	int arr[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	int len = sizeof(arr) / sizeof(int);
	int i;
	QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	for (i = 0; i < len; i++) printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
int MedianOfThree(int arr[], int left, int right) {
	int samples[3] = { left, (left + right) / 2, right };
	if (arr[samples[0]] > arr[samples[1]]) Swap(samples, 0, 1);
	if (arr[samples[1]] > arr[samples[2]]) Swap(samples, 1, 2);
	if (arr[samples[0]] > arr[samples[1]]) Swap(samples, 0, 1);
	return samples[1];
}
void Swap(int arr[], int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}
int Partition(int arr[], int left, int right) {
	int pIdx = MedianOfThree(arr, left, right);
	int pivot = arr[pIdx];
	int low = left + 1;
	int high = right;
	Swap(arr, left, pIdx);
	printf("pivot : %d\n", pivot);
	while (low <= high) {
		while (pivot > arr[low]) low++;
		while (pivot < arr[high]) high--;
		if (low <= high) Swap(arr, low, high);
	}
	Swap(arr, left, high);
	return high;
}
void QuickSort(int arr[], int left, int right) {
	if (left <= right) {
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot+1, right);
	}
}