#include <iostream>
using namespace std;

void tampilArray2D(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarElemenArray2D(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarViaPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int val1 = 100;
    int val2 = 200;
    int *ptr1 = &val1;
    int *ptr2 = &val2;

    cout << "=== MATRIks A AWAL ===" << endl;
    tampilArray2D(A);

    cout << "\n=== MATRIKS B AWAL ===" << endl;
    tampilArray2D(B);

    tukarElemenArray2D(A, B, 1, 1);

    cout << "\n=== SETELAH TUKAR ELEMEN ARRAY 2D DI INDEKS [1][1] ===" << endl;
    cout << "Matriks A:\n";
    tampilArray2D(A);
    cout << "Matriks B:\n";
    tampilArray2D(B);

    cout << "\n=== SEBELUM TUKAR POINTER ===" << endl;
    cout << "Nilai 1 (*ptr1): " << *ptr1 << endl;
    cout << "Nilai 2 (*ptr2): " << *ptr2 << endl;

    tukarViaPointer(ptr1, ptr2);

    cout << "\n=== SETELAH TUKAR POINTER ===" << endl;
    cout << "Nilai 1 (*ptr1): " << *ptr1 << endl;
    cout << "Nilai 2 (*ptr2): " << *ptr2 << endl;

    return 0;
}
