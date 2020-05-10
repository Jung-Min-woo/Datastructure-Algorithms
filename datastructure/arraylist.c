#include<stdio.h>
#include<stdlib.h>
#include "Point.h"

#define __data Point*
#define TRUE 1
#define FALSE 0
#define LIST_LEN 100

typedef __data LData;

typedef struct List {
	LData arr[LIST_LEN];
	int numofData;
	int curPosition;
}List;
void ListInit(List *plist) {
	plist->numofData = 0;
	plist->curPosition = -1;
}
void LInsert(List *plist, LData data) {
	if (plist->numofData == LIST_LEN) {
		puts("Max num of data Exceeded");
		return;
	}
	plist->arr[plist->numofData++ ] = data;
}
int LFirst(List *plist, LData *pdata) {
	if (plist->numofData != 0) {
		*pdata = plist->arr[0];
		plist->curPosition = 0;
		return TRUE;
	}
	else
		return FALSE;
}
int LNext(List *plist, LData *pdata) {
	if (plist->curPosition < plist->numofData -1 ) {
		*pdata = plist->arr[++plist->curPosition];
		return TRUE;
	}
	else
		return FALSE;
}
LData LRemove(List *plist) {
	int i = 0;
	LData target = plist->arr[plist->curPosition--];
	if (plist->numofData-- == 0) {
		puts("No data removable");
		return plist->arr[plist->curPosition];
	}
	for (i = plist->curPosition+1; i < plist->numofData+1; i++) 
		plist->arr[i] = plist->arr[i + 1];
	return target;
}
int LCount(List *plist) { return plist->numofData; }

//int main(void) {
//	List list;
//	Point compPos;	
//	Point *ppos;
//		
//	ListInit(&list);
//
//	ppos = (Point*)malloc(sizeof(Point));
//	SetPointPos(ppos, 2, 1);
//	LInsert(&list, ppos);
//
//	ppos = (Point*)malloc(sizeof(Point));
//	SetPointPos(ppos, 2, 2);
//	LInsert(&list, ppos);
//
//	ppos = (Point*)malloc(sizeof(Point));
//	SetPointPos(ppos, 3, 1);
//	LInsert(&list, ppos);
//
//	ppos = (Point*)malloc(sizeof(Point));
//	SetPointPos(ppos, 3, 2);
//	LInsert(&list, ppos);
//	
//	printf("NData : %d\n", LCount(&list));
//
//	if (LFirst(&list, &ppos)) {
//		ShowPointPos(ppos);
//		while (LNext(&list, &ppos))
//			ShowPointPos(ppos);
//	}
//	printf("\n\n");
//	
//	compPos.xpos = 2;
//	compPos.ypos = 0;
//
//	if (LFirst(&list, &ppos)) {
//		if (PointComp(ppos, &compPos) ==1 ) {
//			ppos = LRemove(&list);
//			free(ppos);
//		}
//		while(LNext(&list, &ppos))
//			if (PointComp(ppos, &compPos) == 1) {
//				ppos = LRemove(&list);
//				free(ppos);
//			}
//	}
//
//	printf("Now NData is %d\n", LCount(&list));
//	if (LFirst(&list, &ppos)) {
//		ShowPointPos(ppos);
//		while (LNext(&list, &ppos))
//			ShowPointPos(ppos);
//	}
//	printf("\n");
//
//	return 0;
//}