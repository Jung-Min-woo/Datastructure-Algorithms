#include <stdio.h>
int BSearch(int ar[], int len, int target) {
	int start = 0;
	int end = len - 1;
	int idx = (start + end) / 2;
	while (start <=end ) {
		if (ar[idx] == target)
			return idx;
		else if (ar[idx] < target)
			start = idx + 1;
		else if(ar[idx] > target)
			end = idx - 1;
	}
	return -1;
}
int BSearchRecur(int ar[], int start, int end, int target) {
	int idx = (start + end) / 2;
	if (start > end)
		return -1;
	if (ar[idx] == target)
		return idx;
	else if (ar[idx] < target)
		BSearchRecur(ar, idx + 1, end, target);
	else if (ar[idx] > target)
		BSearchRecur(ar, start, idx - 1, target);
}
int main(void) {
	int arr[] = { 1,3,5,7,9 };
	int idx;

	idx = BSearchRecur(arr,0, sizeof(arr) / sizeof(int)-1, 7);
	if (idx == -1)
		printf("Failed to search target\n");
	else
		printf("Target Index : %d\n", idx);

	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int)-1, 4);
	if (idx == -1)
		printf("Failed to search target\n");
	else
		printf("Target Index  : %d\n", idx);
	return 0;
}