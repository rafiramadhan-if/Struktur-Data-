#include <iostream>
using namespace std;

int main(){
    int matriks[3][3];
    int totaldiagonal = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> matriks[i][j];
        }
    }

    for(int i = 0; i < 3; i++){
        totaldiagonal += matriks [i][i];
    }

    cout << "Jumlah diagonal: " << totaldiagonal << endl;

    return 0;
}
