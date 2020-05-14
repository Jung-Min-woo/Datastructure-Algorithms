#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node { 
	int data;
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
	if(plist->before->next !=NULL)
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
void bigger(int d1, int d2) {
	return d1 < d2 ? 0 : 1;
}
int main(void) {
	List list;
	int data;
	
	ListInit(&list);
	SetSortRule(&list, bigger);

	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);

	printf("현재 데이터의 수 : %d\n", LCount(&list));
	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	if (LFirst(&list, &data)) {
		if (data == 22)
			LRemove(&list);
		while (LNext(&list, &data)) {
			if (data == 22)
				LRemove(&list);
		}
	}
	printf("현재 데이터의 수 : %d\n", LCount(&list));
	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}