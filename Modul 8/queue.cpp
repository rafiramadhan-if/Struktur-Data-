1.
  #include "queue.h"
 
// head diam di indeks 0, tail bergerak
void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}
 
bool isEmptyQueue(Queue Q) {
    return Q.head == -1 && Q.tail == -1;
}
 
bool isFullQueue(Queue Q) {
    return Q.tail == MAX - 1;
}
 
void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}
 
infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong" << endl;
        return -1;
    }
    infotype x = Q.info[Q.head];
    // geser semua elemen satu langkah ke depan
    for (int i = Q.head; i < Q.tail; i++) {
        Q.info[i] = Q.info[i + 1];
    }
    Q.tail--;
    if (Q.tail < Q.head) {
        Q.head = -1;
        Q.tail = -1;
    }
    return x;
}
 
void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
2.
  #include "queue.h"
 
// head bergerak, tail bergerak
void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}
 
bool isEmptyQueue(Queue Q) {
    return Q.head == -1 && Q.tail == -1;
}
 
bool isFullQueue(Queue Q) {
    // penuh jika head di awal dan tail di akhir
    return Q.head == 0 && Q.tail == MAX - 1;
}
 
void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh" << endl;
        return;
    }
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        if (Q.tail == MAX - 1) {
            // penuh semu: geser elemen ke awal tabel
            int geser = Q.head;
            for (int i = Q.head; i <= Q.tail; i++) {
                Q.info[i - geser] = Q.info[i];
            }
            Q.tail = Q.tail - geser;
            Q.head = 0;
        }
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}
 
infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong" << endl;
        return -1;
    }
    infotype x = Q.info[Q.head];
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head++;
    }
    return x;
}
 
void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
3. 
  #include "queue.h"
 
// head dan tail berputar (circular buffer)
void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}
 
bool isEmptyQueue(Queue Q) {
    return Q.head == -1 && Q.tail == -1;
}
 
bool isFullQueue(Queue Q) {
    return !isEmptyQueue(Q) && (Q.tail + 1) % MAX == Q.head;
}
 
void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh" << endl;
        return;
    }
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
    }
    Q.info[Q.tail] = x;
}
 
infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong" << endl;
        return -1;
    }
    infotype x = Q.info[Q.head];
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAX;
    }
    return x;
}
 
void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        int i = Q.head;
        while (true) {
            cout << Q.info[i] << " ";
            if (i == Q.tail) break;
            i = (i + 1) % MAX;
        }
    }
    cout << endl;
}
