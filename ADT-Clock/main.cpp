#include <iostream>
#include "clock.cpp"

using namespace std;

int main() {

    Clock c1 = makeClock(23, 59, 59);
    Clock c2 = makeClock(2, 23, 23);

    printClock(c1);
    cout << endl;
    printClock(c2);

    return 0;
}
