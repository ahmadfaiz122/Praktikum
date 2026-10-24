#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string kalimat;
    string kata;
    string daftarKata[100];
    int jumlahKata = 0;

    cout << "Masukkan satu kalimat: ";
    getline(cin, kalimat);

    stringstream pemisah(kalimat);
    while (pemisah >> kata && jumlahKata < 100) {
        daftarKata[jumlahKata] = kata;
        jumlahKata++;
    }

    cout << "\nDaftar kata:\n";
    for (int i = 0; i < jumlahKata; i++) {
        cout << i << ". " << daftarKata[i] << '\n';
    }
    cout << "Total jumlah kata: " << jumlahKata << '\n';

    return 0;
}
