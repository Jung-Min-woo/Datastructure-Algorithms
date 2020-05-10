#include<stdio.h>

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100

typedef int LData;

typedef struct List {
	LData arr[LIST_LEN];
	int numofData;
	int curPosition;
}List;

void ListInit(List *plist) {
	plist->numofData = 0;
	plist->curPosition = 0;
}
void LInsert(List *plist, LData data) {
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
	--plist->numofData;
	return --plist->curPosition;
}
int LCount(List *plist) { return plist->numofData; }

int main(void) {
	List list;
	int data;
	ListInit(&list);

	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);

	printf("현재 데이터의 수 : %d\n", LCount(&list));
	printf("test: curPosition : %d\n", list.curPosition);
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


