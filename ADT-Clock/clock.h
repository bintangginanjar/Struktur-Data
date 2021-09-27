#ifndef CLOCK_H_INCLUDED
#define CLOCK_H_INCLUDED

typedef int Hour;
typedef int Minute;
typedef int Second;

struct Clock {
    Hour HH;
    Minute MM;
    Second SS;
};

Hour getHour(Clock c);
Minute getMinute(Clock c);
Second getSecond(Clock c);

Clock makeClock(int hh, int mm, int ss);
bool isValid(int hh, int mm, int ss);

void setHour(Clock c, int newHH);
void setMinute(Clock c, int newMM);
void setSecond(Clock c, int newSS);

bool isEqual(Clock c1, Clock c2);
Clock addClock(Clock c1, Clock c2);
void printClock(Clock c);

#endif // CLOCK_H_INCLUDED
