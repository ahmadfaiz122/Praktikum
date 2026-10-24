#include <iostream>
using namespace std;

int main() {
    int nilai;
    char nilaiHuruf;

    cout << "Masukkan nilai ujian: ";
    cin >> nilai;

    if (nilai >= 85 && nilai <= 100) {
        nilaiHuruf = 'A';
    } else if (nilai >= 70 && nilai <= 84) {
        nilaiHuruf = 'B';
    } else if (nilai < 70) {
        nilaiHuruf = 'C';
    } else {
        cout << "Nilai harus berada antara 0 dan 100." << endl;
        return 0;
    }

    cout << "\n+-------------+-------+" << endl;
    cout << "| Rentang     | Huruf |" << endl;
    cout << "+-------------+-------+" << endl;
    cout << "| 85 - 100    | A     |" << endl;
    cout << "| 70 - 84     | B     |" << endl;
    cout << "| < 70        | C     |" << endl;
    cout << "+-------------+-------+" << endl;
    cout << "\nNilai " << nilai << " mendapatkan nilai huruf: " << nilaiHuruf << endl;

    return 0;
}