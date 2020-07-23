#include <stdio.h>

int ISearch(int arr[], int first, int last, int target) {
	int mid;
	if (first>last  || arr[first] > target || arr[last] < target) return -1;
	mid = (double)(last - first) / (double)(arr[last] - arr[first]) * (double)(target - first) + first;
	if (arr[mid] == target) return mid;
	else if (arr[mid] < target) ISearch(arr, mid+1, last, target);
	else ISearch(arr, first, mid-1, target);
}
int main(void) {
	int arr[] = { 1,3,5,7,9 };
	int idx;

	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
	if (idx == -1) printf("Search Failed\n");
	else printf("target index : %d\n", idx);
	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 2);
	if (idx == -1) printf("Search Failed\n");
	else printf("target index : %d\n", idx);
	return 0;
}