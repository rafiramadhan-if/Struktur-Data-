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

int sum() {
    int total = 0;
    for (Node *p = head; p != NULL; p = p->next) {
        total += p->data;
    }
    return total;
}

int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertLast(x);
    }
    cout << sum() << endl;
    return 0;
}
