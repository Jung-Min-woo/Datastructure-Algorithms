#include<stdio.h>
#include "ExpressionTree.h"

int main(void) {
	char exp[] = "125+-7*";
	BTreeNode *eTree = MakeExpTree(exp);

	printf("PreFix Expression : ");
	ShowPrefixTypeExp(eTree), printf("\n");
	printf("PostFix Expression : ");
	ShowPostfixTypeExp(eTree), printf("\n");
	printf("InFix Expression : ");
	ShowInfixTypeExp(eTree), printf("\n");
	printf("\n\nResult : %d\n", EvaluateExpTree(eTree));
	return 0;
}