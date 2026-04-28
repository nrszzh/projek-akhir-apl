#include <iostream>
using namespace std; 

struct Pengguna {
    int userID; 
    string username; 
    string password; 
    bool isAdmin;
};

const int MAXPENGGUNA = 100; 
Pengguna akun[MAXPENGGUNA]; 
int jumlahPengguna = 2; 
int uniqueUser = jumlahPengguna;

int errorHandling(int pilihan) {
    if (cin.fail()) {
        cin.clear();
        while (cin.peek() != '\n') {
            cin.ignore();
        }
        return pilihan = -1;
    } 
    else {
        cin.clear();
        while (cin.peek() != '\n') {
            cin.ignore();
        }
    }
    return pilihan;
}

void penggunaAwal(Pengguna arr[], int &ukuran) {
    Pengguna temp[] = {
        {1, "Yoga", "017", true}, 
        {2, "Pirlo", "008", false}, 
        {3, "Nur", "018", false}
    };

    int n = sizeof(temp) / sizeof(temp[0]); 

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i]; 
    }

    ukuran = n; 
}

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


void menuSort() {
    int pilihan;

    do {
        try {
            cout << "\n=== MENU SORT ===" << endl; 
            cout << "1. Urutkan Berdasarkan Jarak" << endl; 
            cout << "2. Urutkan Berdasarkan Nama" << endl; 
            cout << "3. Urutkan Berdasarkan Tahun Penemuan" << endl; 
            cout << "4. Urutkan Berdasarkan Magnitudo" << endl; 
            cout << "--------------------------------------" << endl; 
            cout << "0. Kembali" << endl; 

            cout << "Masukkan Pilihan Anda" << endl; 
            cout << "> "; cin >> pilihan; 

            if (cin.fail()) {
                cin.clear(); 
                while (cin.peek() != '\n') {
                    cin.ignore();
                }

                pilihan = -1; 
                throw invalid_argument("Input Harus Berupa Angka!");
            }

            if (pilihan > 4 || pilihan < 0) {
                throw length_error("Angka yang Dimasukkan diluar Range Menu!");
            }

            if (pilihan == 0) {
                cout << "=> Kembali ke Menu Sebelumnya" << endl;
            }
            else if (pilihan == 1) {
                cout << "=> Mengurutkan Berdasarkan Jarak" << endl;
            }
            else if (pilihan == 2) {
                cout << "=> Mengurutkan Berdasarkan Nama" << endl; 
            }
            else if (pilihan == 3) {
                cout << "=> Mengurutkan Berdasarkan Tahun Penemuan" << endl; 
            }
            else if (pilihan == 4) {
                cout << "=> Mengurutkan Berdasarkan Magnitudo" << endl;
            }
        }

        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    } while (pilihan != 0);
}

void menuSearch() {
    int pilihan;

    do {
        try {
            cout << "\n=== MENU SORT ===" << endl; 
            cout << "1. Cari Berdasarkan Nama" << endl;
            cout << "2. Cari Berdasarkan Kategori" << endl; 
            cout << "3. Cari Berdasarkan Konstelasi" << endl; 
            cout << "---------------------------------------------" << endl; 
            cout << "0. Kembali" << endl; 
            cout << "Masukkan Pilihan Anda" << endl; 
            cout << "> "; cin >> pilihan; 

            if (cin.fail()) {
                cin.clear(); 
                while (cin.peek() != '\n') {
                    cin.ignore();
                }
                pilihan = -1;
                throw invalid_argument("Input Harus Berupa Angka!");
            }

            if (pilihan > 3 || pilihan < 0) {
                throw length_error("Angka yang Dimasukkan Melebihi Range Menu!");
            }

            if (pilihan == 0) {
                cout << "=> Kembali ke Menu Sebelumnya" << endl; 
            }
            else if (pilihan == 1) {
                cout << "=> Mencari Entri Berdasarkan Nama" << endl;
            }
            else if (pilihan == 2) {
                cout << "=> Mencari Entri Berdasarkan Kategori" << endl;
            }   
            else if (pilihan == 3) {
                cout << "=> Mencari Entri Berdasarkan Konstelasi" << endl;
            }
        }

        catch (const exception& e) {
            cout << "Error: " << e.what() << endl; 
        }

    } while (pilihan != 0);
}

void menuUser(int indeksLogin) {
    int pilihan; 
    
    do {
        cout << "\n=== MENU USER ===" << endl; 
        cout << "Selamat Datang Kembali " << akun[indeksLogin].username << endl; 
        cout << "[ENTRI]" << endl;
        cout << "1. Lihat Entri" << endl; 
        cout << "2. Urutkan Entri" << endl; 
        cout << "3. Cari Entri" << endl;
        
        cout << "\n[AKUN]" << endl; 
        cout << "4. Perbarui Data Pribadi" << endl;
        cout << "------------------------------------------" << endl; 
        cout << "0. Logout" << endl; 
        
        cout << "Masukkan Pilihan Anda" << endl; 
        cout << "> "; cin >> pilihan; 
        
        pilihan = errorHandling(pilihan);

        if (pilihan == 0) {
            cout << "=> Logout dari Akun" << endl; 
            break; 
        }
        else if (pilihan == 1) {
            cout << "=> Mengarahkan ke Menu 'Lihat Entri'" << endl; 
        }
        else if (pilihan == 2) {
            cout << "=> Mengarahkan ke Menu 'Urutkan Entri'" << endl;
            menuSort();
        }
        else if (pilihan == 3) {
            cout << "=> Mengarahkan ke Menu 'Cari Entri'" << endl;
            menuSearch(); 
        }
        else if (pilihan == 4) {
            cout << "=> Mengarahkan ke Menu 'Perbarui Data Pribadi'" << endl;
        }
        else {
            cout << "=> Pilihan Tidak Valid!" << endl;
        }
    } while (pilihan != 0); 
}

void menuAdmin(int indeksLogin) {
    int pilihan; 

    do {
        cout << "\n=== MENU ADMIN ===" << endl; 
        cout << "Selamat Datang Kembali Admin " << akun[indeksLogin].username << endl; 
        cout << "[ENTRI]" << endl; 
        cout << "1. Tambah Entri Baru" << endl; 
        cout << "2. Lihat Entri" << endl; 
        cout << "3. Perbarui Entri" << endl; 
        cout << "4. Hapus Entri" << endl; 
        cout << "5. Urutkan Entri" << endl; 
        cout << "6. Cari Entri" << endl;

        cout << "\n[AKUN]" << endl; 
        cout << "7. Tambah Akun" << endl; 
        cout << "8. Lihat Akun" << endl; 
        cout << "9. Perbarui Akun" << endl; 
        cout << "10. Hapus Akun" << endl; 

        cout << "-------------------------------------" << endl;
        cout << "0. Keluar" << endl; 
        cout << "Masukkan Pilihan Anda" << endl; 
        cout << "> "; cin >> pilihan;
        
        pilihan = errorHandling(pilihan); 

        if (pilihan == 0) {
            cout << "=> Logout dari Akun" << endl; 
            break;  
        }
        else if (pilihan == 1) {
            cout << "=> Mengarahkan ke Menu 'Tambah Entri'" << endl; 
        }
        else if (pilihan == 2) {
            cout << "=> Mengarahkan ke Menu 'Lihat Entri'" << endl; 
        }
        else if (pilihan == 3) {
            cout << "=> Mengarahkan ke Menu 'Perbarui Entri'" << endl;
        }
        else if (pilihan == 4) {
            cout << "=> Mengarahkan ke Menu 'Hapus Entri'" << endl;
        }
        else if (pilihan == 5) {
            cout << "=> Mengarahkan ke Menu 'Urutkan Entri'" << endl;
            menuSort();
        }
        else if (pilihan == 6) {
            cout << "=> Mengarahkan ke Menu 'Cari Entri'" << endl;
            menuSearch();
        }
        else if (pilihan == 7) {
            cout << "=> Mengarahkan ke Menu 'Tambah Akun'" << endl;
            regis(akun, jumlahPengguna);
        }
        else if (pilihan == 8) {
            cout << "=> Mengarahkan ke Menu 'Lihat Akun'" << endl; 
        }
        else if (pilihan == 9) {
            cout << "=> Mengarahkan ke Menu 'Perbarui Akun'" << endl; 
        }
        else if (pilihan == 10) {
            cout << "=> Mengarahkan ke Menu 'Hapus Akun'" << endl;
        }
        else {
            cout << "=> Pilihan Tidak Valid!" << endl;
        }
    
    } while (pilihan != 0);
}

void menuUtama() {
    int pilihan; 
    
    do {
        try {
            cout << "\n=== Menu Utama ===" << endl;
            cout << "1. Login" << endl; 
            cout << "2. Register" << endl; 
            cout << "0. Keluar" << endl;
            
            cout << "Masukkan Pilihan Anda" << endl; 
            cout << "> "; cin >> pilihan; 

            if (cin.fail()) {
                cin.clear();
                while (cin.peek() != '\n') {
                    cin.ignore();
                }

                pilihan = -1; 
                throw invalid_argument("Input Harus Angka!");
            }

            if (pilihan > 2 || pilihan < 0) {
                throw length_error("Pilihan Tidak Valid");
            }

            if (pilihan == 0) {
                cout << "=> Keluar Dari Program!" << endl;
                break; 
            }
            else if (pilihan == 1) {
                cout << "=> Mengarahkan ke 'Menu Login'" << endl;
                int indeksUser = login(akun, jumlahPengguna);
                
                if (indeksUser >= 0) {
                    cout << "=> Mengarahkan ke menu selanjutnya" << endl;
                    cout << "---------------------------------------------------------" << endl;
                    if (akun[indeksUser].isAdmin) { 
                        menuAdmin(indeksUser);
                    } 
                    else {
                        menuUser(indeksUser);
                    }
                } 
                else {
                    cout << "=> Keluar dari program" << endl;
                    cout << "---------------------------------------------------------" << endl;
                    cout << "===               Kesempatan Login Habis              ===" << endl;
                    cout << "================= Silakan Ulang Program =================" << endl;
                    pilihan = 0; 

                    cout << endl;
                } 
            }
            else if (pilihan == 2) {
                cout << "=> Mengarahkan ke 'Menu Register'" << endl;
                regis(akun, jumlahPengguna); 
            }
            else {
                cout << "=> Pilihan Tidak Valid!" << endl;
            }
        }
    
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (pilihan != 0);
}

int main() {
    penggunaAwal(akun, jumlahPengguna);
    menuUtama(); 
    cout << endl;

    return 0;
}