#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    float nilai[3];
    float rataRata;
};

string ubahKeHurufKapital(string teks) {
    for (char& karakter : teks) {
        karakter = static_cast<char>(
            toupper(static_cast<unsigned char>(karakter)));
    }
    return teks;
}

int main() {
    const int kapasitasMaksimal = 10;
    Mahasiswa mahasiswa[kapasitasMaksimal];
    int jumlahMahasiswa;

    do {
        cout << "Masukkan jumlah mahasiswa (1-10): ";
        cin >> jumlahMahasiswa;
        if (jumlahMahasiswa < 1 || jumlahMahasiswa > kapasitasMaksimal) {
            cout << "Jumlah mahasiswa tidak valid.\n";
        }
    } while (jumlahMahasiswa < 1 || jumlahMahasiswa > kapasitasMaksimal);
    cin.ignore();

    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << '\n';
        cout << "NIM: ";
        getline(cin, mahasiswa[i].nim);
        cout << "Nama: ";
        getline(cin, mahasiswa[i].nama);
        cout << "Nilai Tugas: ";
        cin >> mahasiswa[i].nilai[0];
        cout << "Nilai UTS: ";
        cin >> mahasiswa[i].nilai[1];
        cout << "Nilai UAS: ";
        cin >> mahasiswa[i].nilai[2];
        cin.ignore();

        mahasiswa[i].rataRata =
            (mahasiswa[i].nilai[0] + mahasiswa[i].nilai[1] +
             mahasiswa[i].nilai[2]) / 3.0f;
    }

    int indeksTertinggi = 0;
    for (int i = 1; i < jumlahMahasiswa; i++) {
        if (mahasiswa[i].rataRata > mahasiswa[indeksTertinggi].rataRata) {
            indeksTertinggi = i;
        }
    }

    cout << "\nRekap nilai mahasiswa:\n";
    cout << left << setw(15) << "NIM"
         << setw(25) << "NAMA"
         << right << setw(10) << "TUGAS"
         << setw(10) << "UTS"
         << setw(10) << "UAS"
         << setw(12) << "RATA-RATA" << '\n';
    cout << string(82, '-') << '\n';

    cout << fixed << setprecision(2);
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << left << setw(15) << mahasiswa[i].nim
             << setw(25) << ubahKeHurufKapital(mahasiswa[i].nama)
             << right << setw(10) << mahasiswa[i].nilai[0]
             << setw(10) << mahasiswa[i].nilai[1]
             << setw(10) << mahasiswa[i].nilai[2]
             << setw(12) << mahasiswa[i].rataRata << '\n';
    }

    cout << "\nMahasiswa dengan rata-rata tertinggi: "
         << ubahKeHurufKapital(mahasiswa[indeksTertinggi].nama)
         << " (" << mahasiswa[indeksTertinggi].rataRata << ")\n";

    return 0;
}
