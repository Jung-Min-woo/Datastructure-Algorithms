#include "Deque.h"
#include <stdio.h>
#include <stdlib.h>

void DequeInit(Deque * pq)
{
	pq->head = NULL;
	pq->tail = pq->tail;
}

int DQIsEmpty(Deque * pq)
{	
	return pq->head == NULL || pq->tail == NULL ? TRUE : FALSE;
}

void DQAddFirst(Deque * pq, Data data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = pq->head;
	newNode->prev = NULL;

	if (DQIsEmpty(pq)) pq->tail = newNode;
	else pq->head->prev = newNode;
	pq->head = newNode;
}

void DQAddLast(Deque * pq, Data data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = pq->tail;
	newNode->next = NULL;

	if (DQIsEmpty(pq)) pq->head = newNode;
	else pq->tail->next = newNode;
	pq->tail = newNode;
}

Data DQRemoveFirst(Deque * pq)
{
	Node *tmp = pq->head;
	Data dtmp;
	if (DQIsEmpty(pq)) printf("DQ is Empty\n"),exit(-1);
	dtmp = pq->head->data;
	pq->head = pq->head->next;
	free(tmp);
	return dtmp;
}

Data DQRemoveLast(Deque * pq)
{
	Node *tmp = pq->tail;
	Data dtmp;
	if (DQIsEmpty(pq)) printf("DQ is Empty\n"), exit(-1);
	dtmp = pq->tail->data;
	pq->tail = pq->tail->prev;
	free(tmp);
	return dtmp;
}
Data DQGetFirst(Deque * pq)
{
	return pq->head->data;
}

Data DQGetLast(Deque * pq)
{
	return pq->tail->data;
}