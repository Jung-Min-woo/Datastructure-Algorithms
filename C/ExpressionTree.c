#include "ExpressionTree.h"
#include "BinaryTree.h"
#include "stack_linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void ShowCharData(char tgt) {
	if (tgt>=0 && tgt<=9) printf("%d",tgt);
	else printf("%c", tgt);
}
BTreeNode * MakeExpTree(char exp[])
{
	Stack stack;
	BTreeNode *pnode;

	int explen = strlen(exp);
	int i;
	
	StackInit(&stack);

	for (i = 0; i < explen; i++) {
		pnode = MakeBTreeNode();

		if (isdigit(exp[i])) SetData(pnode, exp[i] - '0');
		else {
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}
		SPush(&stack, pnode);
	}
	return SPop(&stack);
}

int EvaluateExpTree(BTreeNode * bt)
{
	int inp1, inp2;
	char op;
	
	if (GetLeftSubTree(bt) == NULL || GetRightSubTree(bt) == NULL) return GetData(bt);
	inp1 = EvaluateExpTree(bt->left);
	inp2 = EvaluateExpTree(bt->right);
	op = bt->data;
	switch (op) {
	case '+': return inp1 + inp2;
	case '-': return inp1 - inp2;
	case '*': return inp1 * inp2;
	case '/': return inp1 / inp2;
	}
}

void ShowPrefixTypeExp(BTreeNode * bt)
{
	Traverse_PreOrder(bt, ShowCharData);
}

void ShowPostfixTypeExp(BTreeNode * bt)
{
	Traverse_PostOrder(bt, ShowCharData);
}

void ShowInfixTypeExp(BTreeNode * bt)
{	
	if (bt == NULL) return;
	if (bt->left != NULL || bt->right != NULL) printf("(");
	ShowInfixTypeExp(bt->left);
	ShowCharData(bt->data);
	ShowInfixTypeExp(bt->right);
	if (bt->left != NULL || bt->right != NULL) printf(")");
}
