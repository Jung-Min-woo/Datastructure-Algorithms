#ifndef _SLOT2_H__
#define _SLOT2_H__

#include "Person.h"
typedef int Key;
typedef Person* Value;
typedef struct _slot {
	Key key;
	Value val;
}Slot;
#endif