#include "clock.h"

using namespace std;

/* membuat Clock baru, mengembalikan type Clock */
Clock makeClock(int hh, int mm, int ss) {
    Clock tClock;

    tClock.HH = hh;
    tClock.MM = mm;
    tClock.SS = ss;

    return tClock;
}

/* cek apakah jam yang dibuat valid atau tidak */
bool isValid(int hh, int mm, int ss);

/* mengembalikan nilai HH */
Hour getHour(Clock c) {
    return c.HH;
}

/* mengembalikan nilai MM */
Minute getMinute(Clock c) {
    return c.MM;
}

/* mengembalikan nilai SS */
Second getSecond(Clock c) {
    return c.SS;
}

/* set nilai HH */
void setHour(Clock c, int newHH) {
    c.HH = newHH;
}

/* set nilai MM */
void setMinute(Clock c, int newMM) {
    c.MM = newMM;
}

/* set nilai SS */
void setSecond(Clock c, int newSS) {
    c.SS = newSS;
};

/* cek apakah kedua jam bernilai sama */
bool isEqual(Clock c1, Clock c2);

/* tambahkan nilai Clock C1 dengan Clock C2 */
Clock addClock(Clock c1, Clock c2);

/* cetak jam */
void printClock(Clock c) {
    cout << c.HH << ":" << c.MM << ":" << c.SS << endl;
}
