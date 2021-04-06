#include <iostream>

using namespace std;

int main() {
    const int MAX = 4;

    char *nama[MAX] = {"Zara Ali", "Hina Ali", "Nuha Ali", "Sara Ali"};

    for (int i = 0; i < MAX; i++) {
        cout << "Nilai ke-" << i << " adalah "<< *(nama + i) << endl;
    }

    //cout << "Hello world!" << endl;
    return 0;
}
