#include <stdio.h>

int BSearchRecur(int arr[],int first, int last, int target) {
	int mid = (first + last) / 2;
	if (first > last) return -1;
	if (arr[mid] == target) return target;
	else if (arr[mid] < target) BSearchRecur(arr, mid, last, target);
	else BSearchRecur(arr, first, mid, target);
}