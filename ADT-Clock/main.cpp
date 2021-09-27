#include <iostream>
#include "clock.cpp"

using namespace std;

int main() {

    Clock c1;
    setHour(c1, 23);
    setMinute(c1, 59);
    setSecond(c1, 59);

    cout << getHour(c1) << ":" << getMinute(c1) << ":" << getSecond(c1) << endl;

    //cout << "Hello world!" << endl;
    return 0;
}
