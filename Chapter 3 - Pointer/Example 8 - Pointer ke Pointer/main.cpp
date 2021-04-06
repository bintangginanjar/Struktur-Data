#include <iostream>

using namespace std;

int main() {
    int x = 234;
    int *ptr1;
    int **ptr2;

    ptr1 = &x;
    ptr2 = &ptr1;

    // akses nilai x melalui ptr1
    cout << "Nilai variabel x dari ptr1 adalah " << *ptr1 << endl;

    // akses nilai x melalui ptr2
    cout << "Nilai variabel x dari ptr2 adalah " << **ptr2 << endl;

    **ptr2 = 456;
    cout << "Nilai variabel x dari ptr2 sekarang adalah " << **ptr2 << endl;

    //cout << "Hello world!" << endl;
    return 0;
}
