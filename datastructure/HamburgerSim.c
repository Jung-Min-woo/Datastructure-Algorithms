#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CircularQueue.h"

#define NSIMULATION 3000

#define CUS_COME_TERM 15

#define CHEEZE 0
#define BULGOGI 1
#define DOUBLE 2

#define CHEEZE_TERM 30
#define BULGOGI_TERM 60
#define DOUBLE_TERM 90

int collector[5] = { 0,0,0,0,0 };
void writeReport(int counter) {
	if (counter < 30) collector[0]++;
	if (counter < 50) collector[1]++;
	if (counter < 100) collector[2]++;
	if (counter < 200) collector[3]++;
	if (counter >200) collector[4]++;
}
int getTerm(int burger) {
	switch (burger) {
	case CHEEZE: return CHEEZE_TERM;
	case BULGOGI: return  BULGOGI_TERM;
	case DOUBLE: return  DOUBLE_TERM;
	}
	return 0;
}
int main(void) {
	int ntime = 60*30;
	int term=0;
	int denqtime = 0;
	int counter=0, i, j;
	int burger;
	Queue q;
	srand(time(NULL));
	for (j = 0; j < NSIMULATION; j++) {
		QueueInit(&q);
		counter = 0;
		denqtime = 0;
		for (i = 0; i < ntime; i++) {
			if (i % 15 == 0) Enqueue(&q, rand() % 3), counter++;
			if(!QIsEmpty(&q) && i==(denqtime + getTerm(QPeek(&q)))) Dequeue(&q), counter--, denqtime = i;
		}
		writeReport(counter);
	}
	printf("\n%d %d %d %d %d\n", collector[0], collector[1], collector[2], collector[3], collector[4]);
	printf("\n%5.2f %5.2f %5.2f %5.2f %5.2f\n", (float)collector[0]/NSIMULATION, (float)collector[1] / NSIMULATION, (float)collector[2] / NSIMULATION, (float)collector[3] / NSIMULATION, (float)collector[4] / NSIMULATION);
	return 0;
}

