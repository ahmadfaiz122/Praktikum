#include <cctype>
#include <iostream>
#include <string>

using namespace std;

struct Buku {
    string kode;
    string judul;
    string penulis;
    int tahun;
    int stok;
};

const int KAPASITAS_MAKSIMAL = 50;

bool formatKodeValid(const string& kode) {
    if (kode.size() != 6 || kode[0] != 'B' || kode[1] != 'K' ||
        kode[2] != '-') {
        return false;
    }

    for (int i = 3; i < 6; i++) {
        if (!isdigit(static_cast<unsigned char>(kode[i]))) {
            return false;
        }
    }
    return true;
}

bool kodeSudahAda(const Buku buku[], int jumlahBuku, const string& kode) {
    for (int i = 0; i < jumlahBuku; i++) {
        if (buku[i].kode == kode) {
            return true;
        }
    }
    return false;
}

string hurufKecil(string teks) {
    for (char& karakter : teks) {
        karakter = static_cast<char>(
            tolower(static_cast<unsigned char>(karakter)));
    }
    return teks;
}

void tambahBuku(Buku buku[], int& jumlahBuku) {
    if (jumlahBuku == KAPASITAS_MAKSIMAL) {
        cout << "Kapasitas buku sudah penuh.\n";
        return;
    }

    Buku bukuBaru;
    do {
        cout << "Kode buku (format BK-000): ";
        getline(cin, bukuBaru.kode);

        if (!formatKodeValid(bukuBaru.kode)) {
            cout << "Kesalahan: kode harus berformat BK- diikuti tepat 3 digit.\n";
        } else if (kodeSudahAda(buku, jumlahBuku, bukuBaru.kode)) {
            cout << "Kesalahan: kode buku sudah digunakan.\n";
        } else {
            break;
        }
    } while (true);

    cout << "Judul buku: ";
    getline(cin, bukuBaru.judul);
    cout << "Penulis: ";
    getline(cin, bukuBaru.penulis);
    cout << "Tahun terbit: ";
    cin >> bukuBaru.tahun;
    cout << "Stok: ";
    cin >> bukuBaru.stok;
    cin.ignore();

    buku[jumlahBuku] = bukuBaru;
    jumlahBuku++;
    cout << "Buku berhasil ditambahkan.\n";
}

void tampilkanSemuaBuku(const Buku buku[], int jumlahBuku) {
    if (jumlahBuku == 0) {
        cout << "Belum ada data buku.\n";
        return;
    }

    int totalStok = 0;
    cout << "\nDaftar semua buku:\n";
    for (int i = 0; i < jumlahBuku; i++) {
        cout << "\nBuku ke-" << i + 1 << '\n'
             << "Kode    : " << buku[i].kode << '\n'
             << "Judul   : " << buku[i].judul << '\n'
             << "Penulis : " << buku[i].penulis << '\n'
             << "Tahun   : " << buku[i].tahun << '\n'
             << "Stok    : " << buku[i].stok << '\n';
        totalStok += buku[i].stok;
    }
    cout << "\nTotal stok seluruh buku: " << totalStok << '\n';
}

void cariBuku(const Buku buku[], int jumlahBuku) {
    string kataKunci;
    cout << "Masukkan kata kunci judul: ";
    getline(cin, kataKunci);
    kataKunci = hurufKecil(kataKunci);

    bool ditemukan = false;
    for (int i = 0; i < jumlahBuku; i++) {
        if (hurufKecil(buku[i].judul).find(kataKunci) != string::npos) {
            if (!ditemukan) {
                cout << "\nBuku yang ditemukan:\n";
            }
            ditemukan = true;
            cout << "- " << buku[i].kode << " | " << buku[i].judul
                 << " | " << buku[i].penulis << '\n';
        }
    }

    if (!ditemukan) {
        cout << "Buku dengan kata kunci tersebut tidak ditemukan.\n";
    }
}

void urutkanBuku(Buku buku[], int jumlahBuku) {
    for (int i = 0; i < jumlahBuku - 1; i++) {
        for (int j = 0; j < jumlahBuku - i - 1; j++) {
            if (hurufKecil(buku[j].judul) > hurufKecil(buku[j + 1].judul)) {
                Buku sementara = buku[j];
                buku[j] = buku[j + 1];
                buku[j + 1] = sementara;
            }
        }
    }
    cout << "Buku berhasil diurutkan berdasarkan judul A-Z.\n";
}

int main() {
    Buku daftarBuku[KAPASITAS_MAKSIMAL];
    int jumlahBuku = 0;
    int pilihan;

    do {
        cout << "\n=== Menu Manajemen Buku ===\n"
             << "1. Tambah buku\n"
             << "2. Tampilkan semua buku\n"
             << "3. Cari buku berdasarkan kata kunci judul\n"
             << "4. Urutkan buku berdasarkan judul (A-Z)\n"
             << "5. Keluar\n"
             << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                tambahBuku(daftarBuku, jumlahBuku);
                break;
            case 2:
                tampilkanSemuaBuku(daftarBuku, jumlahBuku);
                break;
            case 3:
                cariBuku(daftarBuku, jumlahBuku);
                break;
            case 4:
                urutkanBuku(daftarBuku, jumlahBuku);
                break;
            case 5:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    return 0;
}
