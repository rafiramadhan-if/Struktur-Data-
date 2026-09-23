#include <iostream>
#include <string>
using namespace std;

int main() {
    int angka;
    string satuan[] = {"Nol", "Satu", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan", "Sepuluh", "Sebelas"};

    cout << "Masukkan angka (0 - 100): ";
    cin >> angka;

    cout << "Terbilang: ";
    if (angka >= 0 && angka <= 11) {
        cout << satuan[angka] << endl;
    } 
    else if (angka >= 12 && angka <= 19) {
        cout << satuan[angka % 10] << " Belas" << endl;
    } 
    else if (angka >= 20 && angka <= 99) {
        if (angka % 10 == 0) {
            cout << satuan[angka / 10] << " Puluh" << endl;
        } else {
            cout << satuan[angka / 10] << " Puluh " << satuan[angka % 10] << endl;
        }
    } 
    else if (angka == 100) {
        cout << "Seratus" << endl;
    } 
    else {
        cout << "Angka di luar rentang (0 - 100)!" << endl;
    }

    return 0;
}
