#include <iostream>

using namespace std;

struct TNode {
    int data;       // field data
    TNode *next;    // field pointer
};

TNode *head, *tail; // deklarasi variabel pointer head untuk menunjukkan kepala node

void init() {
    head = NULL; // inisialisasi linked list kosong (tanpa node sama sekali)
    tail = NULL;
}

int isEmpty() {
    if (tail == NULL) {
        return 1;   // kembalikan 1 kalau linked list masih kosong
    } else {
        return 0;   // kembalikan 0 kalau linked list sudah ada isinya
    }
}

void insertDepan(int dataBaru) {
    TNode *nodeBaru;
    nodeBaru = new TNode;

    nodeBaru->data = dataBaru;
    nodeBaru->next = NULL;

    if (isEmpty() == 1) {
        head = tail = nodeBaru;
        tail->next=NULL;
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
        tail = nodeBaru;
        tail->next = NULL;
    } else {
        tail->next = nodeBaru;
        tail = nodeBaru;
    }

    cout << "Data " << dataBaru << " masuk sebagai node paling belakang" << endl;
}

void hapusDepan() {
    TNode *hapus;
    int d;

    if (isEmpty() == 0) {
        if (head != tail) {
            hapus = head;
            d = hapus->data;
            head = head->next;
            delete hapus;
        } else {
            d = tail->data;
            head = tail = NULL;
        }
    cout << "Data " << d << " terhapus" << endl;
    } else {
        cout<<"Linked List masih kosong\n";
    }
}

void hapusBelakang() {
    TNode *hapus,*nodeBantu;
    int d;

    if (isEmpty() == 0) {
        nodeBantu = head;

        if (head != tail) {
            while (nodeBantu->next != tail) {
                nodeBantu = nodeBantu->next;
            }
            hapus = tail;
            tail = nodeBantu;
            d = hapus->data;
            delete hapus;
            tail->next = NULL;
        } else {
            d = tail->data;
            head = tail = NULL;
        }
        cout << "Data " << d << " terhapus" << endl;
    } else {
        cout<<"Linked List masih kosong\n";
    }
}

void hapusSemua() {
    TNode *nodeBantu, *hapus;
    nodeBantu = head;

    while (nodeBantu != NULL) {
        hapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        delete hapus;
    }
    head = NULL;
    cout << "Linked List kosong\n";
}

void tampilData() {
    TNode *nodeBantu; // step 1. buatlah node bantu

    nodeBantu = head; // tempatkan node bantu di head sebagai awal tracing

    if (isEmpty() == 0) {   // kondisi 1. linked list tidak kosong
        while (nodeBantu != NULL) {             // lakukan looping dengan menggunakan variabel bantu sampai ketemu ekor dari linked list
            cout << nodeBantu->data << endl;    // tampilkan data dari setiap node yang dilalui
            nodeBantu = nodeBantu->next;        // pindahkan node bantu ke node selanjutnya
        }
    } else {
        cout << "List masih kosong" << endl;    // kondisi 2. linked list masih kosong
    }
}

int main() {
    int pil, dataBaru;

    do {
        cout<<" \n"<<endl;
        cout<<" ============================"<<endl;
        cout<<" =   PROGRAM LINKED LIST    ="<<endl;
        cout<<" =        HEAD & TAIL       ="<<endl;
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
