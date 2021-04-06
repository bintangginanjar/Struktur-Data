#include <iostream>

using namespace std;

int main() {
    int nilai[3], *penunjuk;

    nilai[0] = 220;
    nilai[1] = 330;
    nilai[2] = 440;

    penunjuk = &nilai[0]; // inisialisasi pointer yang menunjuk ke alamat dari variabel nilai[0]

    cout << "Nilai " << *penunjuk << " ada di alamat " << penunjuk << endl;
    cout << "Nilai " << *(penunjuk + 1) << " ada di alamat " << penunjuk + 1 << endl;
    cout << "Nilai " << *(penunjuk + 2) << " ada di alamat " << penunjuk + 2 << endl;

    //cout << "Hello world!" << endl;
    return 0;
}
