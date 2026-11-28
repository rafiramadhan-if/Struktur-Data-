/* file : bstree.cpp
   Implementasi ADT Binary Search Tree pada bstree.h */

#include <iostream>
#include "bstree.h"
using namespace std;

/********* Soal 1 *********/
address alokasi(infotype x) {
    address baru = new Node;
    baru->info = x;
    baru->left = Nil;
    baru->right = Nil;
    return baru;
}

void insertNode(address &root, infotype x) {
    // cur menyimpan alamat dari pointer yang sedang diperiksa
    address *cur = &root;
    while (*cur != Nil) {
        if (x < (*cur)->info) {
            cur = &((*cur)->left);
        } else if (x > (*cur)->info) {
            cur = &((*cur)->right);
        } else {
            return; // nilai kembar, tidak dimasukkan
        }
    }
    *cur = alokasi(x); // posisi kosong ditemukan
}

address findNode(infotype x, address root) {
    address bantu = root;
    while (bantu != Nil && bantu->info != x) {
        bantu = (x < bantu->info) ? bantu->left : bantu->right;
    }
    return bantu; // Nil jika tidak ditemukan
}

void printInorder(address root) {
    if (root == Nil) return;
    printInorder(root->left);
    cout << root->info << " ";
    printInorder(root->right);
}

/********* Soal 2 *********/
int hitungJumlahNode(address root) {
    if (root == Nil) return 0;
    return hitungJumlahNode(root->left) + hitungJumlahNode(root->right) + 1;
}

int hitungTotalInfo(address root, int start) {
    if (root == Nil) return start;
    // hasil penjumlahan subtree kiri menjadi nilai awal untuk subtree kanan
    int sampaiKiri = hitungTotalInfo(root->left, start + root->info);
    return hitungTotalInfo(root->right, sampaiKiri);
}

int hitungKedalaman(address root, int start) {
    if (root == Nil) return start;
    int dalamKiri  = hitungKedalaman(root->left,  start + 1);
    int dalamKanan = hitungKedalaman(root->right, start + 1);
    if (dalamKiri > dalamKanan) return dalamKiri;
    return dalamKanan;
}

/********* Soal 3 *********/
void printPreorder(address root) {
    if (root == Nil) return;
    cout << root->info << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(address root) {
    if (root == Nil) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->info << " ";
}
