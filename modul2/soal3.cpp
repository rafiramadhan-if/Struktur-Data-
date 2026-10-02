#include <iostream>
#include <string>
using namespace std;

int main() {
    string kata;
    char cari;
    int ketemu = 0;

    getline(cin, kata);
    cin >> cari;

    for (int i = 0; i < kata.length(); i++) {
        if (kata[i] == cari) {
            ketemu++;
        }
    }

    cout << ketemu << endl;

    return 0;
}
