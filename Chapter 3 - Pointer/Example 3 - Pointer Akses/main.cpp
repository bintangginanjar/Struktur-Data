#include <iostream>

using namespace std;

int main() {
    int x, y;
    int *px; // pointer yang menunjuk variabel bertipe integer

    x = 87;
    px = &x; // pointer px berisi alamat memori dari variabel x
    y = *px; // variabel ya berisi nilai yang ditunjuk oleh pointer px

    cout << "Alamat variabel x = " << &x << endl;
    cout << "Isi pointer px = " << px << endl;
    cout << "Nilai variabel x = " << x << endl;
    cout << "Nilai yang ditunjuk oleh pointer px = " << *px << endl;
    cout << "Nilai y = " << y << endl;

    //cout << "Hello world!" << endl;
    return 0;
}
