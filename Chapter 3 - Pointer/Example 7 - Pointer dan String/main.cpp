#include <iostream>

using namespace std;

int main() {
    char *p;
    p = "Testing";

    for (int i = 0; i < 7; i++) {
        cout << "Nilai variabel " << *(p+i) << " berada pada alamat " << &p + i << endl;
    }

    //cout << "Hello world!" << endl;
    return 0;
}
