#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node *next;
};
Node *head = NULL;

void insertLast(string nama) {
    Node *baru = new Node{nama, NULL};
    if (head == NULL) {
        head = baru;
    } else {
        Node *p = head;
        while (p->next != NULL) p = p->next;
        p->next = baru;
    }
}

void deleteFirst() {
    if (head == NULL) return;
    Node *hapus = head;
    cout << "Melayani: " << hapus->nama << endl;
    head = head->next;
    delete hapus;
}

void tampil() {
    cout << "Antrean: ";
    for (Node *p = head; p != NULL; p = p->next) {
        cout << p->nama;
        if (p->next != NULL) cout << " -> ";
    }
    cout << endl;
}

int main() {
    int menu;
    string nama;
    do {
        cin >> menu;
        if (menu == 1) {
            cin >> nama;
            insertLast(nama);
            tampil();
        } else if (menu == 2) {
            deleteFirst();
            tampil();
        }
    } while (menu != 3);
    return 0;
}
