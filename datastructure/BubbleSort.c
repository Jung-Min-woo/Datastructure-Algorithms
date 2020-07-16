#include <stdio.h>


void BubbleSort(int arr[], int n);

int main(void) {
	int arr[4] = { 3,2,4,1 };
	int i;
	BubbleSort(arr, sizeof(arr) / sizeof(int));
	for (int i = 0; i < 4; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}

void BubbleSort(int arr[], int n) {
	int temp;
	int i;
	for (i = 0; i < n-1; ) {
		if (arr[i] > arr[i + 1]) {
			temp = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = temp;
		}
		if (i == n - 2) {
			i = 0, n--;
			continue;
		}
		i++;
	}
}