#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table.h"

int MyHashFunc(int k) {
	return k % 100;
}
int main(void) {
	Table myTb1;
	Person *np, *sp, *rp;
	TBLInit(&myTb1, MyHashFunc);
	np = MakePersonData(20120003, "Lee", "Seoul");
	TBLInsert(&myTb1, GetSSN(np), np);
	np = MakePersonData(20130012, "Kim", "Jeju");
	TBLInsert(&myTb1, GetSSN(np), np);
	np = MakePersonData(20170049, "Han", "Kangwon");
	TBLInsert(&myTb1, GetSSN(np), np);

	sp = TBLSearch(&myTb1, 20120003);
	if (sp != NULL) ShowPerInfo(sp);
	sp = TBLSearch(&myTb1, 20130012);
	if (sp != NULL) ShowPerInfo(sp);
	sp = TBLSearch(&myTb1, 20170049);
	if (sp != NULL) ShowPerInfo(sp);

	rp = TBLDelete(&myTb1, 20120003);
	if (rp != NULL) free(rp);
	rp = TBLDelete(&myTb1, 20130012);
	if (rp != NULL) free(rp);
	rp = TBLDelete(&myTb1, 20170049);
	if (rp != NULL) free(rp);
	return 0;
}