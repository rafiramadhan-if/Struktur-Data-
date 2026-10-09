#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama, nim;
    float uts, uas, tugas, nilaiAkhir;
};

float hitungNA(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Jumlah mahasiswa (max 10): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        cin.ignore();
        cout << "Nama: "; getline(cin, mhs[i].nama);
        cout << "NIM: "; cin >> mhs[i].nim;
        cout << "UTS UAS Tugas (pisahkan spasi): ";
        cin >> mhs[i].uts >> mhs[i].uas >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNA(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\nHASIL" << endl;
    for (int i = 0; i < n; i++) {
        cout << mhs[i].nama << " (" << mhs[i].nim << ") -> Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}
