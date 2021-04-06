#include <iostream>

using namespace std;

int main() {
    int daftarNilai[] = {13, 23, 33};
    int *ptr;

    ptr = daftarNilai;
    cout << "Nilai yang ditunjuk ptr adalah " << *ptr << endl;
    cout << "Nilai yang ditunjuk ptr adalah " << daftarNilai[0] << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Nilai array ke-" << i << " adalah " << *(ptr+i) << endl;
    }

    //cout << "Hello world!" << endl;
    return 0;
}
