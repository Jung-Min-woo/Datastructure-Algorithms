#include <stdio.h>
#include "Deque.h"

int main(void) {
	Deque deq;
	int i;
	DequeInit(&deq);

	DQAddFirst(&deq, 1);
	DQAddFirst(&deq, 2);
	DQAddLast(&deq, 3);
	DQAddLast(&deq, 4);
	while (1) printf("%d ", DQRemoveLast(&deq));
	return 0;
}