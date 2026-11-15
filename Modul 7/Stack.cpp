#include "stack.h"

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top == MAX - 1) {
        cout << "Stack penuh" << endl;
        return;
    }
    S.top++;
    S.info[S.top] = x;
}

infotype pop(Stack &S) {
    if (S.top == -1) {
        cout << "Stack kosong" << endl;
        return -1;
    }
    infotype x = S.info[S.top];
    S.top--;
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP]";
    for (int i = S.top; i >= 0; i--) {
        cout << " " << S.info[i];
    }
    cout << endl;
}

void balikStack(Stack &S) {
    int i = 0;
    int j = S.top;
    while (i < j) {                   
        infotype temp = S.info[i];
        S.info[i] = S.info[j];
        S.info[j] = temp;
        i++;
        j--;
    }
}

void pushAscending(Stack &S, infotype x) {
    if (S.top == MAX - 1) {
        cout << "Stack penuh" << endl;
        return;
    }
    int i = S.top;
    while (i >= 0 && S.info[i] > x) { 
        S.info[i + 1] = S.info[i];
        i--;
    }
    S.info[i + 1] = x;                
    S.top++;
}

void getInputStream(Stack &S) {
    int c = cin.get();
    while (c != '\n' && c != EOF) {
        if (c >= '0' && c <= '9') {  
            if (S.top == MAX - 1) {
                cout << "Stack penuh" << endl;
                break;
            }
            push(S, c - '0');         
        }
        c = cin.get();
    }
}
