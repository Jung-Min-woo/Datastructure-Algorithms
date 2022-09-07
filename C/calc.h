#define _CRT_SECURE_NO_WARNINGS
#ifndef __CALC_H__
#define __CALC_H__
// s1 : num 기록
// s2 : operator 기록
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "stack_linkedlist.h"
#define TRUE 1
#define FALSE 0
int isOperator(char* exp) {
	if (exp[0] == '+' || exp[0] == '-' || exp[0] == '*' || exp[0] == '/' || exp[0] == '(' || exp[0] == ')' || exp[0] == '=') return TRUE;
	return FALSE;
}
int isFloat(double data) { return data - (int)data == 0 ? FALSE : TRUE; }
void transform2Stack(Stack *pstack, char* exp) {
	char* ptr = strtok(exp, " ");
	while (ptr != NULL) {
		if (isOperator(ptr))
			SPush(pstack, ptr[0]);
		else
		{
			if (isFloat(atof(exp)))  SPush(pstack, atoi(exp));
			else SPush(pstack, (int)atof(exp));
		}
		ptr = strtok(NULL, " ");
	}
}
//char* cutStringbyOperator(char* exp, int *cursor_position) {
//	char output[100];
//	int output_cursorpos = 0;
//	while (*cursor_position < strlen(exp) && exp[*cursor_position] >= 48 && exp[*cursor_position] <= 57 || exp[*cursor_position] < '.') 
//		output[output_cursorpos++] = exp[*cursor_position++];
//	if (output_cursorpos == 0) *cursor_position++;
//	return output;
//}
#endif