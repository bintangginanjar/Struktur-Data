#include <iostream>

using namespace std;

struct TNode {
    int data;
    TNode *next;
};

TNode *head, *tail;

void init() {
    head = NULL;
    //tail = NULL;
}

int isEmpty() {
    if (head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void insertDepan(int dataBaru) {
    TNode *nodeBaru;
    nodeBaru = new TNode;

    nodeBaru->data = dataBaru;
    nodeBaru->next = NULL;

    if (isEmpty() == 1) {
        head = nodeBaru;
        head->next = NULL;
    } else {
        nodeBaru->next = head;
        head = nodeBaru;
    }

    cout << "Data " << dataBaru << " masuk sebagai node paling depan" << endl;
}

void insertBelakang(int dataBaru) {
    TNode *nodeBaru, *nodeBantu;
    nodeBaru = new TNode;

    nodeBaru->data = dataBaru;
    nodeBaru->next = NULL;

    if (isEmpty() == 1) {
        head = nodeBaru;
        head->next = NULL;
    } else {
        nodeBantu = head;

        while (nodeBantu->next != NULL) {
            nodeBantu = nodeBantu->next;
        }

        nodeBantu->next = nodeBaru;
    }

    cout << "Data " << dataBaru << " masuk sebagai node paling belakang" << endl;
}

void tampilData() {
    TNode *nodeBantu;

    nodeBantu = head;

    if (isEmpty() == 0) {
        while (nodeBantu != NULL) {
            cout << nodeBantu->data << endl;
            nodeBantu = nodeBantu->next;
        }
    } else {
        cout << "List masih kosong" << endl;
    }
}

int main() {
    int pil, dataBaru;

    do {
        cout<<" ============================"<<endl;
        cout<<" =   PROGRAM LINKED LIST    ="<<endl;
        cout<<" ============================"<<endl;
        cout<<" = 1. Insert Depan          ="<<endl;
        cout<<" = 2. Insert Belakang       ="<<endl;
        cout<<" = 3. Tampil Data           ="<<endl;
        cout<<" = 4. Exit                  ="<<endl;
        cout<<" ============================"<<endl;
        cout<<" Masukan Pilihan : ";
        cin>>pil;

        if (pil == 1) {
            cout<<"Masukan Data = ";
            cin>>dataBaru;
            insertDepan(dataBaru);
        } else if (pil == 2) {
            cout<<"Masukan Data = ";
            cin>>dataBaru;
            insertBelakang(dataBaru);
        } else if (pil == 3) {
            tampilData();
        } else if (pil != 4) {
            cout<<"\n Maaf, Pilihan yang anda pilih tidak tersedia!";
        }
    } while (pil != 4);

    //int dataBaru = 2;
    //insertDepan(dataBaru);

    //cout << "Hello world!" << endl;
    return 0;
}
