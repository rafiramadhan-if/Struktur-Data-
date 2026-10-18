#include <iostream>
#include <string>
using namespace std;

struct Buku {
    string judul;
    int tahun;
    Buku *next;
};
Buku *head = NULL;

void insertLast(string judul, int tahun) {
    Buku *baru = new Buku{judul, tahun, NULL};
    if (head == NULL) {
        head = baru;
    } else {
        Buku *p = head;
        while (p->next != NULL) p = p->next;
        p->next = baru;
    }
}

void deleteLast() {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Buku *p = head;
    while (p->next->next != NULL) p = p->next;
    delete p->next;
    p->next = NULL;
}

void tampil() {
    cout << "Daftar Buku:" << endl;
    for (Buku *p = head; p != NULL; p = p->next) {
        cout << p->judul << " (" << p->tahun << ")" << endl;
    }
}

int main() {
    string baris;
    while (getline(cin, baris)) {
        if (baris == "") continue;
        int spasi = baris.rfind(' ');
        insertLast(baris.substr(0, spasi), stoi(baris.substr(spasi + 1)));
    }
    deleteLast();
    tampil();
    return 0;
}
