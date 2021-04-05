#include <iostream>

using namespace std;

int main() {
    int i; // deklarasi variabel i
    int *iAddr; // deklarasi pointer iAddr

    i = 10; // nilai i diisi dengan 10
    iAddr = &i; // pointer iAddr diisi dengan alamat dari variabel i

    cout << "Alamat variabel i adalah " << iAddr << endl;
    cout << "Nilai variabel i adalah " << i << endl;
    cout << "Nilai pointer iAddr adalah " << *iAddr << endl;

    i = 50;
    iAddr = &i;

    cout << "Alamat variabel i sekarang adalah " << iAddr << endl;
    cout << "Nilai variabel i sekarang adalah " << i << endl;
    cout << "Nilai pointer iAddr sekarang adalah " << *iAddr << endl;

    *iAddr = 30;
    cout << "Nilai variabel i sekarang adalah " << i << endl;
    cout << "Nilai pointer iAddr sekarang adalah " << &i << endl;

    //cout << "Hello world!" << endl;
    return 0;
}
