#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int[], int, int, int);
void MergeSort(int[], int, int);
int main(void) {
	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };
	int i;

	MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (i = 0; i < 7; i++) printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
void MergeTwoArea(int arr[], int left, int mid, int right) {
	int fIdx = left;
	int rIdx = mid + 1;
	int i;

	int *sortArr = (int*)malloc(sizeof(int) * (right + 1));
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right ) {
		if (arr[fIdx] <= arr[rIdx]) sortArr[sIdx++] = arr[fIdx++];
		else sortArr[sIdx++] = arr[rIdx++];
	}
	if (fIdx > mid) for (i = rIdx; i <= right; i++) sortArr[sIdx++] = arr[i];
	else for (i = fIdx; i <= mid; i++) sortArr[sIdx++] = arr[i];
	for (i = left; i <= right; i++) arr[i] = sortArr[i];
	free(sortArr);
}
void MergeSort(int arr[], int left, int right) {
	int mid = (left + right) / 2;
	if (left < right) {
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		printf("left : %d\tmid: %d\tright: %d\t\n", left, mid, right);
		MergeTwoArea(arr, left, mid, right);
		printf("return\n");
		return;
	}
}