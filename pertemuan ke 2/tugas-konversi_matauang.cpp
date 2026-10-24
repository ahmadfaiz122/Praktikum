#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double rupiah, hasilKonversi;
    int pilihan;

    cout << "Masukkan jumlah uang dalam rupiah: Rp ";
    cin >> rupiah;

    cout << "\nPilih mata uang tujuan:" << endl;
    cout << "1. Yen Jepang" << endl;
    cout << "2. Dolar Amerika" << endl;
    cout << "3. Pound Sterling" << endl;
    cout << "Masukkan pilihan (1-3): ";
    cin >> pilihan;

    if (pilihan == 1) {
        hasilKonversi = rupiah / 112.07;
        cout << fixed << setprecision(2);
        cout << "Hasil konversi: " << hasilKonversi << " yen Jepang" << endl;
    } else if (pilihan == 2) {
        hasilKonversi = rupiah / 16.475;
        cout << fixed << setprecision(2);
        cout << "Hasil konversi: " << hasilKonversi << " dolar Amerika" << endl;
    } else if (pilihan == 3) {
        hasilKonversi = rupiah / 22.438;
        cout << fixed << setprecision(2);
        cout << "Hasil konversi: " << hasilKonversi << " pound sterling" << endl;
    } else {
        cout << "Pilihan mata uang tidak tersedia." << endl;
    }

    return 0;
}
