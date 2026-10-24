#include <iostream>
#include <string>

using namespace std;

int main() {
    const int jumlahMahasiswa = 5;
    string namaMahasiswa[jumlahMahasiswa];

    cout << "Masukkan nama " << jumlahMahasiswa << " mahasiswa:\n";
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "Nama mahasiswa ke-" << i + 1 << ": ";
        getline(cin, namaMahasiswa[i]);
    }

    cout << "\nDaftar nama mahasiswa:\n";
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << i + 1 << ". " << namaMahasiswa[i] << '\n';
    }

    return 0;
}
