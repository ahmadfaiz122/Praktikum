#include <iostream>
using namespace std;

int main() {
    int usia;
    double tinggiBadan;

    cout << "Masukkan usia: ";
    cin >> usia;

    cout << "Masukkan tinggi badan (cm): ";
    cin >> tinggiBadan;

    if (usia < 12) {
        cout << "Kategori pengguna: Anak-anak" << endl;

        if (tinggiBadan < 120) {
            cout << "Karcis gratis" << endl;
        } else {
            cout << "Karcis berbayar" << endl;
        }
    } else if (usia >= 19) {
        cout << "Kategori pengguna: Dewasa" << endl;
        cout << "Karcis berbayar" << endl;
    } else {
        cout << "Kategori pengguna: Remaja" << endl;
        cout << "Karcis berbayar" << endl;
    }

    return 0;
}