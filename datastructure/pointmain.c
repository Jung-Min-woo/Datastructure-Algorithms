#include "linkedlist.h"
#include "Point.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef CIRCULAR_LIST
int main(void) {
	List list;
	Point compPos;
	Point *ppos;

	ListInit(&list);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	printf("NData : %d\n", LCount(&list));

	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n\n");

	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, &ppos)) {
		if (PointComp(ppos, &compPos) == 1) {
			ppos = LRemove(&list);
			free(ppos);
		}
		while (LNext(&list, &ppos))
			if (PointComp(ppos, &compPos) == 1) {
				ppos = LRemove(&list);
				free(ppos);
			}
	}

	printf("Now NData is %d\n", LCount(&list));
	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	return 0;
}

#endif

int main(void) {
	List list;
	int data, i, nodeNum;
	ListInit(&list);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsert(&list, 2);
	LInsert(&list, 1);

	if (LFirst(&list, &data)) {
		printf("%d ", data);
		for (i = 0; i < LCount(&list) * 3 - 1; i++) 
			if (LNext(&list, &data))
				printf("%d ", data);
	}
	printf("\n");

	nodeNum = LCount(&list);
	
	if (nodeNum != 0) {
		LFirst(&list, &data);
		if (data % 2 == 0) LRemove(&list);
		for (i = 0; i < nodeNum - 1; i++) {
			LNext(&list, &data);
			if (data % 2 == 0) LRemove(&list);
		}
	}
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		for (i = 0; i < LCount(&list) - 1; i++)
			if (LNext(&list, &data))
				printf("%d ", data);
	}
	return 0;
}