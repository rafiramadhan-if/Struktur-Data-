#include <iostream>
#include "bstree.h"
using namespace std;

// memasukkan n data dari array ke dalam tree
void isiTree(address &root, const int data[], int n) {
    for (int i = 0; i < n; i++) {
        insertNode(root, data[i]);
    }
}

// mencari x lalu menampilkan hasilnya
void cariDanTampilkan(address root, infotype x) {
    address hasil = findNode(x, root);
    if (hasil != Nil) {
        cout << "findNode(" << x << ") : ditemukan, info = " << hasil->info << endl;
    } else {
        cout << "findNode(" << x << ") : tidak ditemukan" << endl;
    }
}

int main() {
    // ===== Soal 1 : insert data, tampilkan in-order, dan cari node =====
    cout << "=== Soal 1 : ADT Binary Search Tree ===" << endl;
    address root = Nil;
    int dataA[] = {50, 30, 70, 20, 40, 60, 80, 35, 65, 30}; // 30 terakhir = kembar
    isiTree(root, dataA, 10);

    cout << "in-order : ";
    printInorder(root);
    cout << endl;

    cariDanTampilkan(root, 65);
    cariDanTampilkan(root, 35);
    cariDanTampilkan(root, 99);

    // ===== Soal 2 : kedalaman, jumlah node, dan total info =====
    cout << "\n=== Soal 2 : Perhitungan Tree ===" << endl;
    cout << "kedalaman   : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total info  : " << hitungTotalInfo(root, 0) << endl;

    // ===== Soal 3 : tree kedua, pre-order dan post-order =====
    cout << "\n=== Soal 3 : Traversal Pre-order dan Post-order ===" << endl;
    address root2 = Nil;
    int dataB[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    isiTree(root2, dataB, 9);

    cout << "pre-order  : ";
    printPreorder(root2);
    cout << endl;

    cout << "in-order   : ";
    printInorder(root2);
    cout << endl;

    cout << "post-order : ";
    printPostorder(root2);
    cout << endl;

    return 0;
}
