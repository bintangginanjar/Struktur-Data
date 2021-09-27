#include "clock.h"

Hour getHour(Clock c) {
    return c.HH;
}

Minute getMinute(Clock c) {
    return c.MM;
}

Second getSecond(Clock c) {
    return c.SS;
}

void setHour(Clock &c, int newHH) {
    c.HH = newHH;
}

void setMinute(Clock &c, int newMM) {
    c.MM = newMM;
}

void setSecond(Clock &c, int newSS) {
    c.SS = newSS;
};

//bool isEqual(Clock c1, Clock c2);
//Clock addClock(Clock c1, Clock c2);
//void printClock(Clock c);
