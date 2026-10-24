#include <iostream>
using namespace std;

int main() {
    double angka;
    int hitung = 0;

    cout << "Masukkan angka: ";
    cin >> angka;

    while (angka >= 1) {
        angka /= 2;
        hitung++;
        cout << "Pembagian ke-" << hitung << ": " << angka << endl;
    }

    cout << "Angka dapat dibagi 2 sebanyak " << hitung
         << " kali hingga hasilnya kurang dari 1." << endl;

    return 0;
}