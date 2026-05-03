#include "types.h"
#include "data.h"
#include "auth.h"

#include <iostream> 
using namespace std; 

int login(Pengguna *ptrAkun, int jumlahPengguna) {
    string username, password;
    bool akunDitemukan, passwordBenar = false;
    int indeksUser;
    int kesempatan = 3;

    cin.ignore();
    do {
        indeksUser = -1;
        akunDitemukan = false;
        
        cout << "=== MENU LOGIN ==========================================" << endl; 
        cout << "Masukkan Username Anda" << endl; 
        cout << "> "; getline(cin, username); 
        cout << "---------------------------------------------------------" << endl;

        for (int i = 0; i < jumlahPengguna; i++) {
            if (username == (ptrAkun + i) -> username) { 
                cout << "=> Akun ditemukan" << endl;
                cout << "---------------------------------------------------------" << endl;
                akunDitemukan = true; 
                indeksUser = i; 
                break;
            }
        }

        if (!akunDitemukan) {
            cout << "=> Akun tidak ditemukan. Coba lagi" << endl;
            cout << "---------------------------------------------------------" << endl;
        }
    } while (!akunDitemukan);
    
    do {
        cout << "Sisa Kesempatan: " << kesempatan << endl;
        cout << "Masukkan Password Anda" << endl;
        cout << "> "; getline(cin, password);
        cout << "---------------------------------------------------------" << endl;

        if (password == akun[indeksUser].password) {
            cout << "=> Password benar" << endl;
            cout << "---------------------------------------------------------" << endl; 
            passwordBenar = true;
        }
        else {
            cout << "=> Password salah! Silakan coba lagi" << endl;
            cout << "---------------------------------------------------------" << endl;
            kesempatan--;
        }

    } while (kesempatan != 0 && !passwordBenar);

    if (akunDitemukan && passwordBenar) {
        cout << "=> Login berhasil" << endl;
        system("pause");
        cout << "---------------------------------------------------------" << endl;
        return indeksUser;
    } 
    else {
        cout << "=> Login gagal" << endl;
        cout << "---------------------------------------------------------" << endl;
        return -1;
    }
}

// --- Register ---
int regis(Pengguna *ptrAkun, int &jumlahPengguna) {
    string username, password;
    bool usernameValid = true;

    cin.ignore();
    do {
        usernameValid = true;
        if (jumlahPengguna >= MAXPENGGUNA) {
            cout << "=> Data Pengguna Sudah Penuh!" << endl; 
            cout << "---------------------------------------------------------" << endl;
            system("Pause");
            cout << "---------------------------------------------------------" << endl;
            return 0;
        }
        
        cout << "=== MENU REGISTER =======================================" << endl;
        cout << "Masukkan Username" << endl;
        cout << "> "; getline(cin, username);
        cout << "---------------------------------------------------------" << endl;

        if (username.length() == 0) {
            cout << "=> Username Tidak Boleh Kosong!" << endl;
            system("pause"); 
            usernameValid = false;
        }

        for (int i = 0; i < jumlahPengguna; i++) {
            if (username == (ptrAkun + i) -> username) { 
                cout << "=> Username sudah digunakan. Silakan masukkan username lain" << endl;
                system("pause");
                cout << "---------------------------------------------------------" << endl;
                usernameValid = false; 
                break;
            }
        }
    } while (!usernameValid);

    bool passwordValid = false;
    do {
        passwordValid = true;
        cout << "Masukkan Password" << endl; 
        cout << "> "; getline(cin, password); 
        cout << "---------------------------------------------------------" << endl;

        if (password.length() == 0) {
            cout << "=> Password Tidak Boleh Kosong!" << endl; 
            passwordValid = false;
            system("pause");
            cout << "---------------------------------------------------------" << endl;
        }
    } while (!passwordValid);

    ptrAkun[jumlahPengguna].userID = uniqueUser + 1; 
    ptrAkun[jumlahPengguna].username = username; 
    ptrAkun[jumlahPengguna].password = password; 
    ptrAkun[jumlahPengguna].isAdmin = false;
    jumlahPengguna++; uniqueUser++;

    cout << "=> Register berhasil" << endl;
    system("pause");
    cout << "---------------------------------------------------------" << endl;
    return jumlahPengguna;
}