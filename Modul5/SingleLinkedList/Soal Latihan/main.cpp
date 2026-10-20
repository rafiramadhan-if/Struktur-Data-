#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5, P_cari;
    
    CreateList(&L);

    P1 = alokasi(2);  insertFirst(&L, P1);
    P2 = alokasi(0);  insertFirst(&L, P2);
    P3 = alokasi(8);  insertFirst(&L, P3);
    P4 = alokasi(12); insertFirst(&L, P4);
    P5 = alokasi(9);  insertFirst(&L, P5);

    printf("Isi List setelah insertFirst: ");
    printInfo(L);

    P_cari = findElm(L, 8);
    if (P_cari != Nil) {
        printf("Elemen 8 ditemukan di alamat memori: %p\n", (void*)P_cari);
    } else {
        printf("Elemen 8 tidak ditemukan.\n");
    }

    printf("Total jumlah seluruh elemen (9+12+8+0+2): %d\n", totalInfo(L));

    return 0;
}
