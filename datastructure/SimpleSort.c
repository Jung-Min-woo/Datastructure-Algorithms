#include <stdio.h>
void BubbleSort(int arr[], int n);
void SelSort(int arr[], int n);
void InserSort(int arr[], int n);
int main(void) {
	int arr[5] = { 5,3,2,4,1 };
	int i;
	InserSort(arr, sizeof(arr) / sizeof(int));
	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
void InserSort(int arr[], int n) {
	int i, j, idx, temp;
	for (i = 1; i < n; i++) {
		temp = arr[i];
		idx = i;
		for (j = 0; j < i; j++) {
			if (arr[j] > arr[i]) {
				idx = j;
				break;
			}
		}
		printf("idx : %d, temp: %d\n", idx, temp);
		for (j = i; j >=idx; j--) {
			arr[j] = arr[j-1];
		}
		arr[idx] = temp;
		printf("arr: %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);
	}
}
void SelSort(int arr[], int n) {
	int temp= arr[0], target=0, idx = 0;
	int i;
	for (i = 1; i < n;) {
		if (temp  > arr[i]) temp = arr[idx=i];
		if (i == n - 1) {
			arr[idx] = arr[target];
			arr[target] = temp;
			i = (idx = ++target) + 1;
			temp = arr[target];
			if (target == n - 1) return;
			continue;
		}
		i++;
	}
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