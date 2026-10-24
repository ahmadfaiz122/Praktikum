#include <iostream>
#include <string>

using namespace std;

int main() {
    const string kataSandiBenar = "AMANda123";
    string kataSandi;

    cout << "Masukkan kata sandi: ";
    getline(cin, kataSandi);

    if (kataSandi == kataSandiBenar) {
        cout << "Login berhasil.\n";
    } else if (kataSandi.length() < 8) {
        cout << "Kata sandi salah dan terlalu pendek (minimal 8 karakter).\n";
    } else {
        cout << "Kata sandi salah.\n";
    }

    return 0;
}
