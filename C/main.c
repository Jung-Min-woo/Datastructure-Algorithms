#define _CRT_SECURE_NO_WARNINGS
#include "stack_linkedlist.h"
#include "Point.h"
#include "calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int i = 0;
	Stack *s= (Stack*)malloc(sizeof(Stack));
	StackInit(s);
	SPush(s, 1);
	SPush(s, 2);
	SPush(s, 3);
	SPush(s, 4);
	SPush(s, 5);
	while(SIsEmpty(s) == FALSE) printf("%d\n", SPop(s));
	return 0;
}