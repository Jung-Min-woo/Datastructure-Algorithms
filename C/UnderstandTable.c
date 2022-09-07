#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct _empInfo {
	int empNum;
	int age;
}EmpInfo;

int main(void) {
	EmpInfo empInfoArr[100];
	EmpInfo ei;
	int eNum;

	printf("Insert Employee NUM / AGE: ");
	scanf("%d %d", &ei.empNum, &ei.age);
	empInfoArr[ei.empNum] = ei;

	printf("Find Emp Num : ");
	scanf("%d", &eNum);

	ei = empInfoArr[eNum];
	printf(" Num : %d \t Age : %d\n", ei.empNum, ei.age);
	return 0;
}