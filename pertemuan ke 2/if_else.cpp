#include <iostream>
using namespace std;

int main(){
    // int umur = 25;
    // bool punyaKTP = false;

    // if (umur >= 17 && punyaKTP) {
    // cout << "Boleh mendaftar" << endl;
    // } else {
    // cout << "Belum boleh mendaftar" << endl;
    // }

    int angka;

    cout << "Masukkan angka: ";
    cin >> angka;

    if (angka >0) {
        cout << "angka positif" << endl;
    }else if (angka < 0){
        cout << "angka negatif" << endl;
    }else{
        cout << "angka nol" << endl;
    }


}