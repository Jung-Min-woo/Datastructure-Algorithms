#include <cstdio>
#include <cstdlib>
#include "Person.h"
#include "Table2.h"

int MyHashFunc(int k) {
	return k % 100;
}
int main(void) {
	Table mytbl;
	Person *np, *sp, *rp;
	TBLInit(&mytbl, MyHashFunc);
	np = MakePersonData(900254, "Lee", "Seoul");
	TBLInsert(&mytbl, GetSSN(np), np);
}
