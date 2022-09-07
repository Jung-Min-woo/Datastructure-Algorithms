#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node *next;
	struct _node *prev;
}Node;
typedef struct _dlDeque {
	Node *head;
	Node *tail;
}DLDeque;
typedef DLDeque Deque;

void DequeInit(Deque *pq);
int DQIsEmpty(Deque *pq);
void DQAddFirst(Deque *pq, Data data);
void DQAddLast(Deque *pq, Data data);
Data DQRemoveLast(Deque *pq);
Data DQRemoveFirst(Deque *pq);
Data DQGetFirst(Deque *pq);
Data DQGetLast(Deque *pq);
#endif