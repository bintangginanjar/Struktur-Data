#ifndef JAM_H_INCLUDED
#define JAM_H_INCLUDED

#include <iostream>
using namespace std;

struct tJam {
    int hh;
    int mm;
    int ss;

    void setJam(int jam, int menit, int detik) {
        hh = jam;
        mm = menit;
        ss = detik;
    }

    void cetakJam() {
        cout << "Jam sekarang " << hh << ":" << mm << ":" << ss << endl;
    }
};

#endif // JAM_H_INCLUDED
