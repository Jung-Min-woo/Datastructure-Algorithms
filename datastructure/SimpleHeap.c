#include "SimpleHeap.h"
#include <stdio.h>

int GetParentIDX(int idx) { return idx / 2; }
int GetLChildIDX(int idx) { return idx*2; }
int GetRChildIDX(int idx) { return idx*2 + 1; }
int GetHiPriCHildIDX(Heap *ph, int idx) {
	if (GetLChildIDX > ph->numofData) return 0;
	else if (GetLChildIDX == ph->numofData) return GetLChildIDX(idx);
	else return ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr ? GetRChildIDX(idx) : GetLChildIDX(idx);
}
void HeapInit(Heap * ph)
{
	ph->numofData = 0;
}

int HIsEmpty(Heap * ph)
{
	return ph->numofData == 0 ? TRUE : FALSE;
}

void HInsert(Heap * ph, HData data, Priority pr)
{
	int idx = ph->numofData;
	HeapElem nelem = { pr, data };

	while (idx != 1) {
		if (pr < (ph->heapArr[GetParentIDX(idx)].pr)) {
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else break;
	}
	ph->heapArr[idx] = nelem;
	ph->numofData++;
}

HData HDelete(Heap * ph)
{
	HData retData = (ph->heapArr[1]).data;
	HeapElem lastElem = ph->heapArr[ph->numofData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriCHildIDX(ph, parentIdx)) {
		if (lastElem.pr <= ph->heapArr[childIdx].pr) break;
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}
	ph->heapArr[parentIdx] = lastElem;
	ph->numofData--;
	return retData;
}
