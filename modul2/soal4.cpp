#include <iostream>
using namespace std;

void tukardankali(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;

    a *= 10;
    b *= 10;
}

int main(){
    int x, y;

    cin >> x >> y;

    tukardankali(x, y);
    cout << "x: " << x << ", y: " << y << endl;
    return 0;
}
