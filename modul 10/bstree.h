/* file : bstree.h
   ADT Binary Search Tree dengan representasi pointer (linked list)
   Modul 10 bagian 10.9 (Latihan) */

#ifndef BSTREE_H_INCLUDED
#define BSTREE_H_INCLUDED

#include <cstddef>

#define Nil NULL

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left, right;
};

/********* Soal 1 *********/
address alokasi(infotype x);
/* membuat node baru berisi x, anak kiri dan kanan diisi Nil */

void insertNode(address &root, infotype x);
/* I.S. tree boleh kosong
   F.S. x ditempatkan sesuai aturan BST, nilai kembar tidak dimasukkan */

address findNode(infotype x, address root);
/* hasil berupa address node yang berisi x, atau Nil jika x tidak ada */

void printInorder(address root);
/* menampilkan tree secara in-order (kiri, root, kanan) */

/********* Soal 2 *********/
int hitungJumlahNode(address root);
/* hasil berupa banyak node pada tree */

int hitungTotalInfo(address root, int start);
/* hasil berupa jumlah seluruh info pada tree, start = nilai awal (isi 0) */

int hitungKedalaman(address root, int start);
/* hasil berupa kedalaman maksimal tree dalam jumlah node,
   start = 0 (tree dengan root saja memiliki kedalaman 1) */

/********* Soal 3 *********/
void printPreorder(address root);
/* menampilkan tree secara pre-order (root, kiri, kanan) */

void printPostorder(address root);
/* menampilkan tree secara post-order (kiri, kanan, root) */

#endif // BSTREE_H_INCLUDED
