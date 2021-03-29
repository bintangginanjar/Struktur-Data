#include <iostream>

using namespace std;

struct tJam {
    int hh;
    int mm;
    int ss;
};

int main() {
    tJam jam;

    cout << "Jam: ";
    cin >> jam.hh;

    cout << "Menit: ";
    cin >> jam.mm;

    cout << "Detik: ";
    cin >> jam.ss;

    cout << "Jam sekarang:" << jam.hh << ":" << jam.mm << ":" << jam.ss << endl;
    //cout << "Hello world!" << endl;
    return 0;
}

