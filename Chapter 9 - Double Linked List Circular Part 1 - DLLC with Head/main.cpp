#include <iostream>

using namespace std;

struct TNode {
    int data;       // field data
    TNode *next;    // field pointer next
    TNode *prev;    // field pointer prev
};

TNode *head; // deklarasi variabel pointer head untuk menunjukkan kepala node

void init() {
    head = NULL;
}

int isEmpty() {
    if (head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void insertDepan(int dataBaru) {
    TNode *nodeBaru, *nodeBantu;
    nodeBaru = new TNode;

    nodeBaru->data = dataBaru;
    nodeBaru->next = nodeBaru;
    nodeBaru->prev = nodeBaru;

    if (isEmpty() == 1) {
        head = nodeBaru;
        head->next = head;
        head->prev = head;
    } else {
        nodeBantu = head->prev;
        nodeBaru->next = head;
        head->prev = nodeBaru;
        head = nodeBaru;
        head->prev = nodeBantu;
        nodeBantu->next = head;
    }

    cout << "Data " << dataBaru << " masuk sebagai node paling depan" << endl;
}

void insertBelakang(int dataBaru) {
    TNode *nodeBaru, *nodeBantu;
    nodeBaru = new TNode;

    nodeBaru->data = dataBaru;
    nodeBaru->next = nodeBaru;
    nodeBaru->prev = nodeBaru;

    if (isEmpty() == 1) {
        head = nodeBaru;
        head->next = head;
        head->prev = head;
    } else {
        nodeBantu = head->prev;
        nodeBantu->next = nodeBaru;
        nodeBaru->prev = nodeBantu;
        nodeBaru->next = head;
        head->prev = nodeBaru;
    }

    cout << "Data " << dataBaru << " masuk sebagai node paling belakang" << endl;
}

void hapusDepan() {
    TNode *nodeHapus, *nodeBantu;
    int d;

    if (isEmpty() == 0) {
        if (head->next != head) {
            nodeHapus = head;
            d = nodeHapus->data;
            nodeBantu = head->prev;
            head = head->next;
            nodeBantu->next = head;
            head->prev = nodeBantu;
            delete nodeHapus;
        } else {
            d = head->data;
            head = NULL;
        }
        cout << "Data " << d << " terhapus" << endl;
    } else {
        cout << "Linked List masih kosong\n";
    }
}

void hapusBelakang() {
    TNode *nodeHapus,*nodeBantu;
    int d;

    if (isEmpty() == 0) {
        if (head->next != head) {
            nodeBantu = head;

            while (nodeBantu->next->next != head) {
                nodeBantu = nodeBantu->next;
            }

            nodeHapus = nodeBantu->next;
            d = nodeHapus->data;
            nodeBantu->next = head;
            delete nodeHapus;
        } else {
            d = head->data;
            head = NULL;
        }
        cout << "Data " << d << " terhapus" << endl;
    } else {
        cout << "Linked List masih kosong\n";
    }
}

void hapusSemua() {
    TNode *nodeBantu, *nodeHapus;
    nodeBantu = head;

    while (nodeBantu->next != head) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        delete nodeHapus;
    }

    head = NULL;
    cout << "Linked List kosong\n";
}

void tampilData() {
    TNode *nodeBantu;

    nodeBantu = head;

    if (isEmpty() == 0) {
        do {
            cout << nodeBantu->data << endl;
            nodeBantu = nodeBantu->next;
        } while (nodeBantu != head);
    } else {
        cout << "List masih kosong" << endl;
    }
}

int main() {
    int pil, dataBaru;

    do {
        cout<<" \n"<<endl;
        cout<<" ============================"<<endl;
        cout<<" =   PROGRAM DLLC           ="<<endl;
        cout<<" ============================"<<endl;
        cout<<" = 1. Insert Depan          ="<<endl;
        cout<<" = 2. Insert Belakang       ="<<endl;
        cout<<" = 3. Hapus Depan           ="<<endl;
        cout<<" = 4. Hapus Belakang        ="<<endl;
        cout<<" = 5. Tampil Data           ="<<endl;
        cout<<" = 6. Hapus semua Data      ="<<endl;
        cout<<" = 7. Exit                  ="<<endl;
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
            hapusDepan();
        } else if (pil == 4) {
            hapusBelakang();
        } else if (pil == 5) {
            tampilData();
        } else if (pil == 6) {
            hapusSemua();
        } else if (pil != 7) {
            cout<<"\n Maaf, Pilihan yang anda pilih tidak tersedia!";
        }
    } while (pil != 7);

    return 0;
}
