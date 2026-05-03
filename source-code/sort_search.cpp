#include "types.h"
#include "sort_search.h"

#include <iostream>
using namespace std;

void urutkanBerdasarkanNama(BendaLangit arr[], int ukuran) {
    char urutan;
    cout << "\n=== URUTKAN BERDASARKAN NAMA ===" << endl;
    cout << "Pilih urutan pengurutan:" << endl;
    cout << "A. Ascending (A-Z)" << endl;
    cout << "D. Descending (Z-A)" << endl;
    cout << "Masukkan pilihan (A/D): ";
    cin >> urutan;
    cin.ignore();
    urutan = toupper(urutan);
    
    for (int i = 0; i < ukuran - 1; i++) {
        for (int j = 0; j < ukuran - i - 1; j++) {
            bool perluTukar = false;
            if (urutan == 'A') {
                if ((arr+j)->namaObjek > (arr+j+1)->namaObjek) {
                    perluTukar = true;
                }
            }
            else if (urutan == 'D') {
                if ((arr+j)->namaObjek < (arr+j+1)->namaObjek) {
                    perluTukar = true;
                }
            }
            
            if (perluTukar) {
                BendaLangit temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
            }
        }
    }
    
    cout << "=> Data berhasil diurutkan!" << endl;
    system("pause");
}