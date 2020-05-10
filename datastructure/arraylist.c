#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "Point.h"
#include "NameCard.h"

#define __data NameCard*
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

int main(void) {
	List list;
	NameCard *pcard;
	ListInit(&list);

	pcard = MakeNameCard("이진수", "010-1111-2222");
	LInsert(&list, pcard);

	pcard = MakeNameCard("한지영", "010-3333-4444");
	LInsert(&list, pcard);
	
	pcard = MakeNameCard("조수진", "010-5555-6666");
	LInsert(&list, pcard);
	
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "한지영"))
			ShowNameInfo(pcard);
		else
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "한지영")) {
					ShowNameInfo(pcard);
					break;
				}
			}
	}
	
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "이진수"))
			ChangePhoneNum(pcard, "010-9999-888");
		else
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "이진수")) {
					ChangePhoneNum(pcard, "010-9999-888");
					
					break;
				}
			}
	}

	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "조수진")) {
			pcard = LRemove(&list);
			free(pcard);
		}
		else 
			while(LNext(&list, &pcard)) 
				if (!NameCompare(pcard, "조수진")) {
					pcard = LRemove(&list);
					free(pcard);
					break;
				}
	}

	printf("현재 데이터 수 : %d\n", LCount(&list));
	if (LFirst(&list, &pcard)) {
		ShowNameInfo(pcard); 
		while (LNext(&list, &pcard)) 
			ShowNameInfo(pcard);
	}
	return 0;
}