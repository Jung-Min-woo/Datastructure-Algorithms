#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"Point.h"
#define TRUE 1
#define FALSE 0

typedef Point* LData;

typedef struct _node {
	LData data;
	struct _node *next;
}Node;
typedef struct _linkedlist {
	Node *head;
	Node *cur;
	Node *before;
	int numofData;
	int (*comp)(LData d1, LData d2);
}List;

void ListInit(List *plist) {
	Node *DummyNode = (Node*)malloc(sizeof(Node));

	plist->numofData = 0;
	plist->head = DummyNode;
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->before = NULL;
	plist->cur = NULL;

}
void FInsert(List *plist, LData data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = plist->head->next;
	plist->head->next = newNode;
	plist->numofData++;
}
void SInsert(List *plist, LData data) {
	if (plist->comp == NULL)
		return FInsert(plist, data);

	Node *prevcompareNode = plist->head;
	//Node *compareNode = prevcompareNode->next;

	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	plist->numofData++;

	while (prevcompareNode->next != NULL && plist->comp(newNode->data, prevcompareNode->next->data))
		prevcompareNode = prevcompareNode->next;
	newNode->next = prevcompareNode->next;
	prevcompareNode->next = newNode;
}
void LInsert(List *plist, LData data) {
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}
int LFirst(List *plist, LData *pdata) {
	plist->before = plist->head;
	plist->cur = plist->before->next;
	if (plist->cur == NULL)
		return FALSE;
	*pdata = plist->cur->data;
	return TRUE;
}
int LNext(List *plist, LData *pdata) {
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	if (plist->cur == NULL)
		return FALSE;
	*pdata = plist->cur->data;
	return TRUE;
}
LData LRemove(List *plist) {
	LData out = plist->cur->data;
	plist->numofData--;
	if (plist->before->next != NULL)
		plist->before->next = plist->before->next->next;
	free(plist->cur);
	plist->cur = plist->before;
	return out;
}
int LCount(List *plist) {
	return plist->numofData;
}
void SetSortRule(List *plist, int(*comp)(LData d1, LData d2)) {
	plist->comp = comp;
}
int bigger(int d1, int d2) {
	return d1 < d2 ? 0 : 1;
}
#endif