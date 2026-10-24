#include <iostream>
using namespace std;

int main() {
    int n;
    unsigned long faktorial = 1; //biar ga membesar terlalu cepat

    cout << "Masukkan bilangan bulat: ";
    cin >> n;

    if (n < 0) {
        cout << "Faktorial tidak terdefinisi untuk bilangan negatif." << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        faktorial *= i;
    }

    cout << n << "! = " << faktorial << endl;

    return 0;
}