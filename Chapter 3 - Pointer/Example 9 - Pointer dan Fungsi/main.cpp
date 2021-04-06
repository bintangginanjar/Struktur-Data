#include <iostream>

using namespace std;

char *namaBulan(int n) {
    static char *bulan[] = {
        "Kode bulan salah",
        "Januari",
        "Februari",
        "Maret",
        "April",
        "Mei",
        "Juni",
        "Juli",
        "Agustus",
        "September",
        "Oktober",
        "Nopember",
        "Desember"
    };

    if (n<1 || n>12) {
        return bulan[0];
    } else {
        return bulan[n];
    }
}

int main() {
    int bl;
    cout << "Bulan (1 .. 12):" << endl;
    cin >> bl;
    char *nama = namaBulan(bl);
    cout << "Nama bulan " << &nama << endl;

    //cout << "Hello world!" << endl;
    return 0;
}
