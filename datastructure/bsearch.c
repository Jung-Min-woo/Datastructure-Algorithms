#include <stdio.h>
int BSearch(int ar[], int len, int target) {
	int idx = 0;
	int start = 0;
	int end = len - 1;
	while (1) {
		idx = (start + end) / 2;
		
		if (ar[idx] == target)
			return idx;
		else if (ar[idx] < target)
			start = idx + 1;
		else if(ar[idx] >target)
			end = idx - 1;
	}
}
int main(void) {
	int arr[] = { 1,3,5,7,9 };
	int idx;

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("Failed to search target\n");
	else
		printf("Target Index : %d\n", idx);

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("Failed to search target\n");
	else
		printf("Target Index  : %d\n", idx);
	return 0;
}