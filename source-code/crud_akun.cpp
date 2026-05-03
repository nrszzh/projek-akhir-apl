#include "types.h" 
#include "data.h"
#include "utils.h"
#include "crud_akun.h"

#include <iostream>
using namespace std;

void lihatSeluruhAkun(Pengguna *ptrAkun, int ukuran) {
    if (ukuran == 0) {
        cout << "=> Tidak ada Akun yang Tersimpan!" << endl; 
        system("pause"); 
        return; 
    }

    cout << "\n=== DAFTAR SELURUH AKUN ===" << endl; 
    cout << "ID | Username | Role" << endl; 
    for (int i = 0; i < ukuran; i++) {
        if (i % 5 == 0 && i != 0) {
            cout << "--------------------------------------------------------------------------" << endl;
        }

        cout << (ptrAkun + i)->userID
            << " | " << (ptrAkun + i)->username
            << " | " << ((ptrAkun + i)->isAdmin ? "Admin" : "User")
            << endl; 
    }
}

void lihatAkunSpesifik(Pengguna *ptrAkun, int ukuran) {
    if (ukuran == 0) {
        cout << "\n=> Data Akun kosong!" << endl;
        system("pause");
        return;
    }

    lihatSeluruhAkun(ptrAkun, ukuran);

    int idAkunSpesifik;
    cout << "\nMasukkan User ID untuk detail lengkap: ";
    cin >> idAkunSpesifik;

    bool ditemukan = false;
    for (int i = 0; i < ukuran; i++) {
        if ((ptrAkun + i)->userID == idAkunSpesifik) {
            cout << "\n==========================================" << endl;
            cout << "            DETAIL LENGKAP AKUN           " << endl;
            cout << "==========================================" << endl;
            cout << "User ID        : " << (ptrAkun + i)->userID << endl;
            cout << "Username       : " << (ptrAkun + i)->username << endl;
            cout << "Password       : " << (ptrAkun + i)->password << endl;
            cout << "Role           : " << ((ptrAkun + i)->isAdmin ? "Admin" : "Member") << endl;
            cout << "==========================================" << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "\n=> User ID " << idAkunSpesifik << " tidak ditemukan!" << endl;
    }
    system("pause");
}