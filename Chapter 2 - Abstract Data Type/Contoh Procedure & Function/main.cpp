#include <iostream>

using namespace std;

struct tJam {
    int hh;
    int mm;
    int ss;
};

tJam jam;

void setJam(int h, int m, int s) {
    jam.hh = h;
    jam.mm = m;
    jam.ss = s;
}

void cetakJam() {
    cout << jam.hh << ":" << jam.mm << ":" << jam.ss << endl;
}

int main() {

    setJam(12, 45, 10);
    cetakJam();

/*
    jam.hh = 12;
    jam.mm = 45;
    jam.ss = 10;
*/

    //cout << jam.hh << ":" << jam.mm << ":" << jam.ss << endl;

    //cout << "Hello world!" << endl;
    return 0;
}
