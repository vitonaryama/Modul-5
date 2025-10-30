# <h1 align="center">Laporan Praktikum Modul 5 SINGLY LINKED LIST 2 (SLL) </h1>
<p align="center">Vito Naryama Pramudito</p>

## Dasar Teori

Kode ini digunakan untuk mengimplementasikan struktur data Singly Linked List dalam bahasa C++. Program ini terdiri dari tiga file utama, yaitu Singlylist.h, Singlylist.cpp, dan main.cpp. Setiap elemen pada list (disebut node) memiliki dua bagian, yaitu info yang menyimpan data dan next yang menunjuk ke elemen berikutnya. Dengan memanfaatkan alokasi memori dinamis menggunakan new, ukuran list dapat menyesuaikan kebutuhan program tanpa batasan seperti pada array. Fungsi-fungsi yang digunakan, seperti createList, alokasi, dealokasi, insertFirst, printInfo, findElm, dan totalInfo, membantu dalam membuat list baru, menambahkan data, menampilkan isi, mencari elemen, hingga menghitung total nilai yang tersimpan. Struktur data ini lebih fleksibel dibandingkan array karena tidak memerlukan penggeseran data saat ada perubahan, meskipun pencarian data dilakukan secara berurutan. Secara keseluruhan, kode ini menggambarkan penerapan konsep dasar pengelolaan memori dinamis dan struktur data linier yang sering digunakan dalam pengembangan perangkat lunak modern (Acharjya, Koley, & Barman, 2022; Hussain, Pandya, & Chakravarty, 2024; Mbejo, Nopa, Putri, & Risky, 2025).

## Guided 

### [listbuah.cpp]

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

// fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

// pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah;
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru ke dalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// prosedur-prosedur untuk delete / menghapus node yang ada di dalam list
void delFirst(linkedlist &List) {
    address nodeHapus;
    if (!isEmpty(List)) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List) {
    address nodeHapus, nodePrev;
    if (!isEmpty(List)) {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil) {
            List.first = Nil;
            dealokasi(nodeHapus);
        } else {
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else { // jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama Buah : " << nodeBantu->isidata.nama
                 << ", Jumlah : " << nodeBantu->isidata.jumlah
                 << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// function untuk menampilkan jumlah node di dalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// prosedur untuk menghapus list (menghapus semua node di dalam list)
void deleteList(linkedlist &List) {
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List berhasil terhapus!" << endl;
}

// ----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----

// prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateLast(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            address nodeBantu = nodePrev->next;
            cout << "Masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// ----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----

// prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data) {
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if (nodeBantu->isidata.nama == data) {
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama
                     << ", Jumlah : " << nodeBantu->isidata.jumlah
                     << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if (!found) {
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

// prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if (nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama
                     << ", Jumlah : " << nodeBantu->isidata.jumlah
                     << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if (!found) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

// prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if (harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama
                     << ", Jumlah : " << nodeBantu->isidata.jumlah
                     << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if (!found) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}


```
Kode ini digunakan untuk mengimplementasikan semua fungsi yang telah dideklarasikan pada file header. Kode ini memungkinkan pembuatan list buah, penambahan data di awal, tengah, atau akhir list, penghapusan dan pembaruan data, serta pencarian buah berdasarkan nama, alamat node, atau rentang harga. Hasil setiap operasi ditampilkan ke layar agar pengguna dapat melihat perubahan isi list.

### [listbuah.h]

```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL 

#include <iostream>
using namespace std;

// deklarasi isi data struct mahasiswa
struct buah{
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node{ //node untuk isi linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{//ini linked listnya 
    address first;
};

//semua function &prosedur yg akan dipakai 
//materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodebaru);
void insertAfter(linkedlist &List, address nodebaru, address prev);
void insertLast(linkedlist &List, address nodebaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &list, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5(part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5(part 2 - searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir);

#endif

```
Kode ini digunakan untuk mendefinisikan struktur data buah yang berisi nama, jumlah, dan harga, serta membentuk node dan linked list sebagai wadah penyimpanan data. Kode ini juga berisi deklarasi semua fungsi yang akan digunakan untuk menambah, menghapus, memperbarui, dan mencari data buah pada list.

### [main.cpp]

```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

   updateFirst(List);
   updateLast(List);
   updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData (List, "Kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}


```
Kode ini digunakan untuk menguji seluruh fungsi yang ada pada program linked list buah. Kode ini membuat beberapa data buah seperti Jeruk, Apel, Pir, Semangka, dan Durian, lalu melakukan proses insert, update, search, dan delete. Hasil dari setiap proses ditampilkan ke layar agar pengguna dapat melihat hasil perubahan data pada list.

## Unguided 

### 1. [singlylish.cpp]

```C++
#include "Singlylist.h"

// Membuat list kosong
void createList(List &L) {
    L.first = Nil;
}

// Alokasi node baru
address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

// Dealokasi node
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

// Menyisipkan di awal list
void insertFirst(List &L, address P) {
    if (P != Nil) {
        P->next = L.first;
        L.first = P;
    }
}

// Menampilkan isi list
void printInfo(List L) {
    address P = L.first;
    cout << "Isi list: ";
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

// Mencari elemen dengan nilai tertentu
address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == x) return P;
        P = P->next;
    }
    return Nil;
}

// Menjumlahkan semua nilai info
int totalInfo(List L) {
    int total = 0;
    address P = L.first;
    while (P != Nil) {
        total += P->info;
        P = P->next;
    }
    return total;
}

```

Kode ini digunakan untuk mengimplementasikan fungsi dasar pada single linked list bertipe integer. Kode ini dapat membuat list kosong, menambahkan elemen di awal list, menampilkan isi list, mencari elemen dengan nilai tertentu, menghitung total seluruh nilai dalam list, serta menghapus node dari memori.

#### Full code Screenshot:
<img width="312" height="834" alt="image" src="https://github.com/user-attachments/assets/eb3de15e-bbc4-4ad6-b491-6f44587e01bb" />

### [singlylist.h]

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

// Prototipe fungsi/prosedur
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);
address findElm(List L, infotype x);
int totalInfo(List L);

#endif

```

Kode ini digunakan untuk mendefinisikan struktur data dasar single linked list yang menyimpan elemen bertipe integer. Di dalamnya terdapat struktur node dan list, serta deklarasi fungsi untuk membuat list baru, menambahkan elemen, mencari nilai tertentu, dan menghitung total nilai seluruh elemen dalam list.

#### Full code Screenshot:
<img width="439" height="564" alt="image" src="https://github.com/user-attachments/assets/551230b0-6c0a-4bd8-93f3-0e3faba910bf" />


### [main.cpp]

```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    // Pencarian elemen dengan nilai 8
    address found = findElm(L, 8);
    if (found != Nil)
        cout << "Elemen dengan info 8 ditemukan di alamat " << found << endl;
    else
        cout << "Elemen dengan info 8 tidak ditemukan" << endl;

    // Menghitung total seluruh elemen
    cout << "Total semua info elemen = " << totalInfo(L) << endl;

    return 0;
}


```
#### Output:
<img width="583" height="71" alt="image" src="https://github.com/user-attachments/assets/c691df79-7a68-426c-929e-44a4d84476e3" />

Kode ini digunakan untuk menguji fungsi-fungsi yang ada pada program singly linked list bertipe integer. Kode ini membuat beberapa elemen dengan nilai 2, 0, 8, 12, dan 9, kemudian menampilkannya di layar, mencari nilai 8, serta menghitung total seluruh elemen. Hasilnya ditampilkan untuk memastikan program berjalan dengan benar.

#### Full code Screenshot:
<img width="730" height="732" alt="image" src="https://github.com/user-attachments/assets/8f8fb7ed-fa49-4fe6-9d24-d7f30a724036" />

## Kesimpulan
Secara keseluruhan, seluruh kode menunjukkan pentingnya pemahaman tentang struktur data, pointer, dan manajemen memori dinamis dalam membangun program yang efisien dan fleksibel. Penerapan konsep Singly Linked List dengan pendekatan modular melalui pemisahan file header, implementasi, dan main membuat kode lebih terstruktur serta mudah dipelihara. Sejalan dengan Acharjya, Koley, dan Barman (2022), serta Hussain, Pandya, dan Chakravarty (2024), penerapan struktur data seperti linked list membantu mahasiswa memahami konsep dasar penyimpanan dan pengelolaan data secara dinamis, sekaligus meningkatkan kemampuan analisis dan problem solving dalam pemrograman.

## Referensi
[1] Acharjya, P. P., Koley, S., & Barman, S. (2022). Analysis of the complexity of various linked lists.
[2] Hussain, M. A., Pandya, J., & Chakravarty, P. (2024). Impact of time complexity using array and linked list in data structure.
[3] Mbejo, M. T., Nopa, L. A., Putri, J. S., & Risky, M. (2025). Analisis struktur data linked list dalam pengolahan data mahasiswa.
