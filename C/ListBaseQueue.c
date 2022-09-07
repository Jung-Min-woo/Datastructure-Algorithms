#include "ListBaseQueue.h"
#include <stdlib.h>
#include <stdio.h>

void QueueInit(Queue * pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

int QIsEmpty(Queue * pq)
{return pq->front == NULL ? TRUE : FALSE;}

void Enqueue(Queue * pq, Data data)
{
	Node  *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	
	if (QIsEmpty(pq)) pq->front = newNode, pq->rear = newNode;
	else {
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

Data Dequeue(Queue * pq)
{
	Data temp = pq->front->data;
	if (QIsEmpty(pq)) printf("Q is Empty\n"), exit(-1);
	pq->front = pq->front->next;
	return temp;
}

Data QPeek(Queue * pq)
{
	if (QIsEmpty(pq)) printf("Q is Empty!\n"), exit(-1);
	return pq->front->data;
}
