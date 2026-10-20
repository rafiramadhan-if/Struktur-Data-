#ifndef Singlylist_H
#define Singlylist_H

#include <stdio.h>
#include <stdlib.h>

#define Nil NULL

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

typedef struct {
    address first;
} List;

void CreateList(List *L);
address alokasi(infotype x);
void dealokasi(address *P);
void insertFirst(List *L, address P);
void printInfo(List L);
address findElm(List L, infotype x);
int totalInfo(List L);

#endif
