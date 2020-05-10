#ifndef __NAMECARD_H__
#define __NAMECARD_H__

#include <stdio.h>
#include <stdlib.h>
#include<string.h>


#define NAME_LEN	30
#define PHONE_LEN	30

typedef struct __namecard {
	char name[NAME_LEN];
	char phone[PHONE_LEN];
}NameCard;

NameCard* MakeNameCard(const char *name, const char *phone) {
	NameCard* newcard = (NameCard*)malloc(sizeof(NameCard));
	strcpy(newcard->name, name);
	strcpy(newcard->phone, phone);
	return newcard;
}
void ShowNameInfo(NameCard* pcard) {
	printf("Name : %10s\n", pcard->name );
	printf("phone : %10s\n", pcard->phone);
}
int NameCompare(NameCard *pcard, const char* name) {
	return strcmp(pcard->name, name);
}
int ChangePhoneNum(NameCard *pcard, const char *phone) {
	strcpy(pcard->phone, phone);
}
#endif
