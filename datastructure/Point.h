#ifndef __POINT_H_
#define __POINT_H_

#include <stdio.h>
typedef struct _point {
	int xpos, ypos;
}Point;
void SetPointPos(Point *ppos, int xpos, int ypos) {
	ppos->xpos = xpos;
	ppos->ypos = ypos;
}
void ShowPointPos(Point *ppos) {
	printf("x : %3d\ty: %3d\n", ppos->xpos, ppos->ypos);
}
int PointComp(Point *pos1, Point *pos2) {
	if (pos1->xpos == pos2->xpos && pos1->ypos == pos2->ypos) return 0;
	else if (pos1->xpos == pos2->xpos) return 1;
	else if (pos1->ypos == pos2->ypos)	return 2;
	else return -1;
}
#endif