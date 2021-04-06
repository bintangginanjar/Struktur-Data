#include <iostream>

using namespace std;

int main() {
    float x, *px; // inisialisasi variabel x beserta pointernya

    x = 54.6;
    cout << "Isi variabel x semula " << x << endl;

    px = &x;
    *px = *px + 10;
    cout << "Isi variabel x sekarang " << x << endl;

    //cout << "Hello world!" << endl;
    return 0;
}
