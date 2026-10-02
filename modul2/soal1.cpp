#include <iostream>
#include <vector>
#include <string>


using namespace std;

int arr [10];

int main(){

int n;
float rata_rata = 0;
int total = 0;
int rata2 = 0;

cout << "masukan jumlah nilai : ";
cin >> n;

for (int i = 0; i < n; i++) {
cin >> arr[i];

total = total + arr[i];
}
rata_rata = total / n;
cout << "rata-rata nilai : " << rata_rata << endl;

for (int i = 0; i < n; i++) {
    if (arr[i] > rata_rata) {
        rata2 += 1;
    }
}

cout << "nilai di atas rata_rata: " << rata2;
return 0;
}
