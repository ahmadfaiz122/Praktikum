#include <iostream>
#include <string>

using namespace std;

int main() {
    const int jumlahPeserta = 10;
    const string peserta[jumlahPeserta] = {
        "Andi", "Budi", "Citra", "Dewi", "Eko",
        "Fajar", "Gina", "Hadi", "Intan", "Joko"
    };
    string namaDicari;
    int indeksDitemukan = -1;

    cout << "Masukkan nama peserta yang ingin dicari: ";
    getline(cin, namaDicari);

    for (int i = 0; i < jumlahPeserta; i++) {
        if (peserta[i] == namaDicari) {
            indeksDitemukan = i;
            break;
        }
    }

    if (indeksDitemukan != -1) {
        cout << "Nama \"" << namaDicari << "\" ditemukan pada indeks "
             << indeksDitemukan << ".\n";
    } else {
        cout << "Nama \"" << namaDicari << "\" tidak ditemukan.\n";
    }

    return 0;
}
