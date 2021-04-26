#include <iostream>

using namespace std;

struct TNode {
    int data;       // field data
    TNode *next;    // field pointer
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
    TNode *nodeBaru, *nodeBantu;            // step 1. inisialisasi nodeBaru dan nodeBantu
    nodeBaru = new TNode;

    nodeBaru->data = dataBaru;
    nodeBaru->next = NULL;
                                            // cek apakah SLLC kosong?
    if (isEmpty() == 1) {                   // step 2a. SLLLC masih kosong
        head = nodeBaru;                    // step 3a. pointer head di-assign kepada nodeBaru
        head->next = head;                  // step 4a. next pointer diarahkan kepada head
    } else {                                // step 2b. SLLC sudah ada node (tidak kosong)
        nodeBantu = head;                   // step 3b. pointer nodeBantu diassign ke head

        while (nodeBantu->next != head) {   // step 4b. cari node terakhir dengan acuan next != head
            nodeBantu = nodeBantu->next;
        }
        nodeBaru->next = head;              // step 5b. keluar looping, assign next nodeBaru kepada head
        head = nodeBaru;                    // step 6b. assign head kepada nodeBaru
        nodeBantu->next = head;             // step 7b. assign next untuk node terakhir kepada head yang baru
    }

    cout << "Data " << dataBaru << " masuk sebagai node paling depan" << endl;
}

void insertBelakang(int dataBaru) {
    TNode *nodeBaru, *nodeBantu;            // step 1. inisialisasi nodeBaru dan nodeBantu
    nodeBaru = new TNode;

    nodeBaru->data = dataBaru;
    nodeBaru->next = nodeBaru;
                                            // cek apakah SLLC masih kosong
    if (isEmpty() == 1) {                   // step 2a. SLLLC masih kosong
        head = nodeBaru;                    // step 3a. pointer head di-assign kepada nodeBaru
        head->next = head;                  // step 4a. next pointer diarahkan kepada head
    } else {                                // step 2b. SLLC sudah ada node (tidak kosong)
        nodeBantu = head;                   // step 3b. pointer nodeBantu diassign ke head

        while (nodeBantu->next != head) {   // step 4b. cari node terakhir dengan acuan next != head
            nodeBantu = nodeBantu->next;
        }

        nodeBantu->next = nodeBaru;         // step 5b. keluar looping, assign next nodeBantu kepada nodeBaru
        nodeBaru->next = head;              // step 6b. assign next nodeBaru kepada head
    }

    cout << "Data " << dataBaru << " masuk sebagai node paling belakang" << endl;
}

void hapusDepan() {
    TNode *nodeHapus, *nodeBantu;               // step 1. inisialisasi nodeHapus dan nodeBantu
    int d;
                                                // cek apakah SLLC masih kosong
    if (isEmpty() == 0) {                       // step 2a. SLLC tidak kosong
        nodeHapus = head;                       // step 3a. assign nodeHapus kepada head
        d = nodeHapus->data;
                                                // cek apakah SLLC hanya berisi satu node
        if (head->next != head) {               // step 4a.a SLLC berisi lebih dari satu node
            nodeBantu = head;                   // step 5a.b assign nodeBantu kepada head

            while (nodeBantu->next != head) {   // step 6a.b selama next dari nodeBantu != head
                nodeBantu = nodeBantu->next;    // step 7a.b pindahkan nodeBantu ke node selanjutnya
            }
                                                // keluar looping
            head = head->next;                  // step 8a.b pindahkan head ke node selanjutnya
            nodeBantu->next = head;             // step 9a.b assign next dari node terakhir ke head yang baru
            delete nodeHapus;                   // step 10a.b hapus head yang lama
        } else {
            head = NULL;                        // step 4b.a SLLC berisi hanya satu node, maka head kita assign dengan NULL
        }
        cout << "Data " << d << " terhapus" << endl;
    } else {                                    // SLLC masih kosong
        cout << "Linked List masih kosong\n";
    }
}

void hapusBelakang() {
    TNode *nodeHapus,*nodeBantu;                // step 1. inisialisasi nodeHapus dan nodeBantu
    int d;
                                                // cek apakah SLLC masih kosong
    if (isEmpty() == 0) {                       // step 2a. SLLC tidak kosong
        nodeHapus = head;                       // step 3a. assign nodeHapus kepada head
                                                // cek apakah SLLC hanya berisi satu node
        if (head->next == head) {
            d = nodeHapus->data;
            head = NULL;                        // step 4a.a SLLC hanya berisi satu node maka head kita assign dengan NULL
        } else {                                // step 4a.b SLLC berisi lebih dari satu node
            nodeBantu = head;                       // step 5a.b assign nodeBantu kepada

            while (nodeBantu->next->next != head) { // step 6a.b selama next dari next-nya nodeBantu != head
                nodeBantu = nodeBantu->next;        // step 7a.b pindahkan nodeBantu ke node berikutnya
            }
                                                    // keluar looping, nodeBantu sudah berada di posisi node kedua terakhir
            nodeHapus = nodeBantu->next;            // step 8a.b assign nodeHapus kepada next dari nodeBantu
            d = nodeHapus->data;
            nodeBantu->next = head;                 // step 9a.b assign next dari nodeBantu ke head
            delete nodeHapus;                       // step 10.a hapus node terakhir
        }
        cout << "Data " << d << " terhapus" << endl;
    } else {
        cout << "Linked List masih kosong\n";   // step 2b. SLLC masih kosong
    }
}

void hapusSemua() {
    TNode *nodeBantu, *nodeHapus;       // step 1. inisialisasi nodeHapus dan nodeBantu
    nodeBantu = head;                   // step 2. nodeBantu di assign kepada head

    while (nodeBantu->next != head) {   // step 3. selama next dari nodeBantu != head
        nodeHapus = nodeBantu;          // step 4. assign nodeHapus kepada nodeBantu
        nodeBantu = nodeBantu->next;    // step 5. pindahkan nodeBantu ke node selanjutnya
        delete nodeHapus;               // step 6. hapus node
    }
                                        // keluar looping, nodeBantu di posisi terakhir
    head = NULL;                        // step 7. assign head dengan NULL
    cout << "Linked List kosong\n";
}

void tampilData() {
    TNode *nodeBantu;                           // step 1. inisialisasi nodeBantu

    nodeBantu = head;                           // step 2. assign nodeBantu kepada head
                                                // cek apakah SLLC masih kosong
    if (isEmpty() == 0) {                       // step 3a. SLLC tidak kosong
        do {
            cout << nodeBantu->data << endl;    // step 4a. cetak data
            nodeBantu = nodeBantu->next;        // step 5a. pindahkan nodeBantu ke node selanjutnya selama nodeBantu bukan head
        } while (nodeBantu != head);
    } else {
        cout << "List masih kosong" << endl;    // step 3b. SLLC masih kosong
    }
}

int main() {
    int pil, dataBaru;

    do {
        cout<<" \n"<<endl;
        cout<<" ============================"<<endl;
        cout<<" =   PROGRAM SLLC           ="<<endl;
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
