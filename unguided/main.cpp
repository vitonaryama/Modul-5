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
