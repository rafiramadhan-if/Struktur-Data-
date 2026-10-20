#include "Singlylist.h"

void CreateList(List *L) {
    L->first = Nil;
}

address alokasi(infotype x) {
    address P = (address)malloc(sizeof(struct elmlist));
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address *P) {
    free(*P);
    *P = Nil;
}

void insertFirst(List *L, address P) {
    P->next = L->first;
    L->first = P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        printf("%d ", P->info);
        P = P->next;
    }
    printf("\n");
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil && P->info != x) {
        P = P->next;
    }
    return P;
}

int totalInfo(List L) {
    int sum = 0;
    address P = L.first;
    while (P != Nil) {
        sum += P->info;
        P = P->next;
    }
    return sum;
}
