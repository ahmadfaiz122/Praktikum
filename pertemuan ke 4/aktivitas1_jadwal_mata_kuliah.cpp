#include <iostream>
#include <string>

using namespace std;

int main() {
    const string namaHari[5] = {
        "Senin", "Selasa", "Rabu", "Kamis", "Jumat"
    };
    const string mataKuliah[5] = {
        "Matematika Dasar",
        "Literasi Digital",
        "Penjasbug",
        "Matematika Diskrit",
        "Pemrograman Dasar"
    };
    int pilihan;

    cout << "Masukkan nomor hari (1-5): ";
    cin >> pilihan;

    if (pilihan >= 1 && pilihan <= 5) {
        cout << "Jadwal hari " << namaHari[pilihan - 1] << ": "
             << mataKuliah[pilihan - 1] << '\n';
    } else {
        cout << "Input hari tidak valid\n";
    }

    return 0;
}
