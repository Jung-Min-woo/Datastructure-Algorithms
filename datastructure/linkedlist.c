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
	plist->numofData = 0;
	plist->head = NULL;
	plist->head->next = NULL;
	plist->cur = NULL;
	plist->before = NULL;
}
void LInsert(List *plist, LData data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
		plist->before = plist->head->next;
		plist->cur = plist->head->next->next;

	newNode->data = data;
	newNode->next = plist->head->next;
	plist->head->next = newNode;
	////cur&before pointer 
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	plist->numofData++;
}
void SInsert(List *plist, LData data);
int LFirst(List *plist, LData *pdata) {
	plist->
}
int LNext(List *plist, LData *pdata);
LData LRemove(List *plist);
int LCount(List *plist);
void SetSortRule(List *plist, int(*comp)(LData d1, LData d2));

int main(void) {
	List list;
	int data;
	ListInit(&list);

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