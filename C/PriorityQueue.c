#include "PriorityQueue.h"

void PQueueInit(PQueue * ppq, PriorityComp pc)
{
	ppq->numOfData = 0;
	ppq->comp = pc;
}

int PQIsEmpty(PQueue * ppq)
{
	return ppq->numOfData == 0 ? TRUE : FALSE;
}

void PEnqueue(PQueue * ppq, PQData data)
{
	HInsert(ppq, data);
}

PQData PDequeue(PQueue * ppq)
{
	return HDelete(ppq);
}
