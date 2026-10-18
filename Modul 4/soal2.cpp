#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};
Node *head = NULL;

void insertLast(int x) {
    Node *baru = new Node{x, NULL};
    if (head == NULL) {
        head = baru;
    } else {
        Node *p = head;
        while (p->next != NULL) p = p->next;
        p->next = baru;
    }
}

void insertAfter(int cari, int x) {
    Node *p = head;
    while (p != NULL && p->data != cari) p = p->next;
    if (p != NULL) {
        Node *baru = new Node{x, p->next};
        p->next = baru;
    }
}

void tampil() {
    for (Node *p = head; p != NULL; p = p->next) {
        cout << p->data;
        if (p->next != NULL) cout << " -> ";
    }
    cout << endl;
}

int main() {
    int n, x, cari, baru;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertLast(x);
    }
    cin >> cari >> baru;
    insertAfter(cari, baru);
    tampil();
    return 0;
}
