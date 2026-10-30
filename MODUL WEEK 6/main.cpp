#include "dll.h"

// membaca satu data kendaraan dari keyboard
Kendaraan inputKendaraan(string nopol) {
    Kendaraan k;
    k.nopol = nopol;
    cout << "masukkan warna kendaraan: ";
    cin >> k.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> k.thnBuat;
    return k;
}

int main() {
    List L;
    createList(L);
    string nopol;
    ElmList *P, *Q;

    // ===== LATIHAN 1: input data kendaraan (insertLast), nopol tidak boleh sama =====
    int n;
    cout << "jumlah data yang akan dimasukkan: ";
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> nopol;
        if (findElm(L, nopol) != nullptr) {
            Kendaraan buang = inputKendaraan(nopol);
            cout << "nomor polisi sudah terdaftar" << endl << endl;
        } else {
            insertLast(L, alokasi(inputKendaraan(nopol)));
            cout << endl;
        }
    }
    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);

    // ===== LATIHAN 2: cari nomor polisi =====
    cout << endl << "Masukkan Nomor Polisi yang dicari : ";
    cin >> nopol;
    P = findElm(L, nopol);
    cout << endl;
    if (P != nullptr) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Kendaraan tidak ditemukan." << endl;
    }

    // ===== LATIHAN 3: hapus nomor polisi (deleteFirst / deleteLast / deleteAfter) =====
    cout << endl << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> nopol;
    P = findElm(L, nopol);
    if (P == nullptr) {
        cout << "Data dengan nomor polisi " << nopol << " tidak ditemukan." << endl;
    } else {
        if (P == L.first) {
            deleteFirst(L, Q);
        } else if (P == L.last) {
            deleteLast(L, Q);
        } else {
            deleteAfter(L, P->prev, Q);
        }
        dealokasi(Q);
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus." << endl;
    }
    cout << endl << "DATA LIST 1" << endl << endl;
    printInfo(L);

    // ===== LATIHAN 4: sisipkan data (insertFirst / insertAfter / insertBefore) =====
    int pilih;
    cout << endl << "Sisipkan data baru" << endl;
    cout << "1. insert first" << endl;
    cout << "2. insert after" << endl;
    cout << "3. insert before" << endl;
    cout << "pilihan: ";
    cin >> pilih;
    cout << "masukkan nomor polisi: ";
    cin >> nopol;
    if (findElm(L, nopol) != nullptr) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        Kendaraan baru = inputKendaraan(nopol);
        if (pilih == 1) {
            insertFirst(L, alokasi(baru));
        } else if (pilih == 2 || pilih == 3) {
            string acuan;
            cout << "masukkan nomor polisi acuan: ";
            cin >> acuan;
            Q = findElm(L, acuan);
            if (Q == nullptr) {
                cout << "nomor polisi acuan tidak ditemukan." << endl;
            } else if (pilih == 2) {
                insertAfter(L, Q, alokasi(baru));
            } else {
                insertBefore(L, Q, alokasi(baru));
            }
        }
    }
    cout << endl << "DATA LIST 1" << endl << endl;
    printInfo(L);

    // bersihkan sisa node
    while (L.first != nullptr) {
        deleteFirst(L, P);
        dealokasi(P);
    }
    return 0;
}
