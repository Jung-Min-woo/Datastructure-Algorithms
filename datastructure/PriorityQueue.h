#ifndef __PRIORITYQUEUE_H__
#define __PRIORITYQUEUE_H__

#include "UsefulHeap.h"

typedef Heap PQueue;
typedef HData PQData;

void PQueueInit(PQueue *ppq, PriorityComp pc);
int PQIsEmpty(PQueue *ppq);
void PEnqueue(PQueue *ppq, PQData data);
PQData PDequeue(PQueue *ppq);

#endif