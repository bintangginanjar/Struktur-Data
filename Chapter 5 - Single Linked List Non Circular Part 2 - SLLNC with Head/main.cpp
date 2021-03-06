
#include <iostream>

using namespace std;

struct TNode {
    int data;       // field data
    TNode *next;    // field pointer
};

TNode *head; // deklarasi variabel pointer head untuk menunjukkan kepala node

void init() {
    head = NULL; // inisialisasi linked list kosong (tanpa node sama sekali)
    //tail = NULL;
}

int isEmpty() {
    if (head == NULL) {
        return 1;   // kembalikan 1 kalau linked list masih kosong
    } else {
        return 0;   // kembalikan 0 kalau linked list sudah ada isinya
    }
}

void insertDepan(int dataBaru) {
    TNode *nodeBaru;        // step 1. buatlah node baru
    nodeBaru = new TNode;

    nodeBaru->data = dataBaru;  // step 2. input data yang diinginkan di node yang baru
    nodeBaru->next = NULL;      // node belum disambungkan ke linked list

    if (isEmpty() == 1) {       // step 3. cek apakah linked list masih kosong atau tidak
        head = nodeBaru;        // kondisi 1. linked list masih kosong sehingga pointer head kita pindahkan ke node yang baru
        head->next = NULL;
    } else {
        nodeBaru->next = head;  // kondisi 2. linked list sudah terbentuk sehingga node yang baru menjadi kepala dari linked list
        head = nodeBaru;
    }

    cout << "Data " << dataBaru << " masuk sebagai node paling depan" << endl;
}

void insertBelakang(int dataBaru) {
    TNode *nodeBaru, *nodeBantu;    // step 1. buatlah node baru dan node bantu
    nodeBaru = new TNode;

    nodeBaru->data = dataBaru;  // step 2. input data yang diinginkan di node yang baru
    nodeBaru->next = NULL;      // node belum disambungkan ke linked list

    if (isEmpty() == 1) {   // step 3. cek apakah linked list masih kosong atau tidak
        head = nodeBaru;    // kondisi 1. linked list masih kosong sehingga pointer head kita pindahkan ke node yang baru
        head->next = NULL;
    } else {
        nodeBantu = head;   // kondisi 2. linked list sudah terbentuk, tempatkan nodeBantu di head sebagai awal tracing

        while (nodeBantu->next != NULL) {   // lakukan looping dengan menggunakan variabel bantu untuk mencari ekor dari linked list
            nodeBantu = nodeBantu->next;    // ekor dari linked list ditunjukkan dengan pointer next = NULL
        }

        nodeBantu->next = nodeBaru; // keluar looping, ekor linked list disambungkan ke node yang baru
    }

    cout << "Data " << dataBaru << " masuk sebagai node paling belakang" << endl;
}

void hapusDepan() {
    TNode *hapus;
    int d;

    if (isEmpty()==0) {
        if(head->next != NULL){
            hapus = head;
            d = hapus->data;
            head = head->next;
            delete hapus;
        } else {
            d = head->data;
            head = NULL;
        }
    cout << "Data " << d << " terhapus" << endl;
    } else {
        cout<<"Linked List masih kosong\n";
    }
}

void hapusBelakang() {
    TNode *hapus,*bantu;
    int d;

    if (isEmpty()==0) {
        if(head->next != NULL){
            bantu = head;
            while(bantu->next->next!=NULL){
                bantu = bantu->next;
            }
            hapus = bantu->next;
            d = hapus->data;
      		bantu->next = NULL;
            delete hapus;
        } else {
            d = head->data;
            head = NULL;
        }
        cout << "Data " << d << " terhapus" << endl;
    } else {
        cout<<"Linked List masih kosong\n";
    }
}

void hapusSemua() {
    TNode *bantu, *hapus;
    bantu = head;

    while(bantu!=NULL) {
        hapus=bantu;
        bantu=bantu->next;
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
