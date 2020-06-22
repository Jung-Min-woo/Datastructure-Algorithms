#include <stdlib.h>
#include <stdio.h>
#ifndef __STACK_LINKEDLIST_H__
#define __STACK_LINKEDLIST_H__

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int Data;

typedef struct _node {
	Data data;
	struct _node *next;
}Node;

typedef struct _linkStack {
	Node *head;
	int len;
}LinkStack;

typedef LinkStack Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);
void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);

void StackInit(Stack *pstack) {
	pstack->head = NULL;
	pstack->len = 0;
}
int SIsEmpty(Stack *pstack) { return pstack->head == NULL ? TRUE : FALSE; }
Data SPeek(Stack *pstack) {
	if (SIsEmpty(pstack)) { exit(-1); }
	return pstack->head->data;
}
void SPush(Stack *pstack, Data data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pstack->head;
	pstack->head = newNode, pstack->len++;
}
Data SPop(Stack *pstack) {
	Node *ntmp = pstack->head;
	Data tmp = ntmp->data;
	if (SIsEmpty(pstack)) { exit(-1); }
	pstack->head = pstack->head->next, pstack->len--;
	free(ntmp);
	return tmp;
}
#endif
