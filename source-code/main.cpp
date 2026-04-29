#include <iostream>
using namespace std; 

// ============================================================
// --- SECTION 1 — DEFINISI STRUCT / TIPE DATA ----------------
// ============================================================
struct BendaLangit {
    int entriID; 
    string namaObjek; 
    string klasifikasi; // Bintang, Planet, Asteroid, Nebula
    string konstelasi; // Objek berada di konstelasi mana
    string jarakDariBumi; // Jarak dari Bumi (dalam Light-Year)
    string tahunPenemuan; // Tahun Penemuan Benda Langit
    string statusObservasi; // "Dalam Pengamatan", "Selesai Pengamatan", "Pengamatan Ditunda"
    string magnitudo; // Cahaya yang dipancarkan oleh Benda Langit
};

const int MAXENTRI = 100; 
BendaLangit entri[MAXENTRI]; 
int jumlahEntri = 10; 
int uniqueEntri = jumlahEntri;

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

// ============================================================
// --- SECTION 2 — PROTOTIPE FUNGSI ---------------------------
// ============================================================
// --- Utilitas ---
int errorHandling(int pilihan); 
void entriAwal(BendaLangit arr[], int &ukuran); 
void penggunaAwal(BendaLangit arr[], int &ukuran); 

// --- CRUD ---
void tambahEntri(BendaLangit newEntri[], int &ukuran); 
void lihatSeluruhEntri(BendaLangit entriTerdaftar[], int ukuran);

// --- Sorting & Searching ---


// --- Authorization ---
int login(Pengguna *ptrAkun, int jumlahPengguna); 
int regis(Pengguna *ptrAkun, int &jumlahPengguna);

// --- Menu Handler ---
void menuUtama(); 
void menuAdmin(int indeksLogin); 
void menuUser(int indeksLogin); 
void menuRead(); 
void menuSort(); 
void menuSearch();

// ============================================================
// --- SECTION 3 — FUNGSI UTILITAS ----------------------------
// ============================================================
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

void entriAwal(BendaLangit arr[], int &ukuran) {
    BendaLangit temp[] {
        {1, "Sirius", "Bintang", "Canis Major", "8.6 LY", "Zaman Kuno", "Selesai Pengamatan", "-1.46"}, 
        {2, "Betelgeuse", "Bintang", "Orion", "700 LY", "Zaman Kuno", "Dalam Pengamatan", "0.42"}, 
        {3, "Jupiter", "Planet", "N/A (Tata Surya)", "0.00008 LY", "Zaman Kuno", "Selesai Pengamatan", "-2.94"},
        {4, "Andromeda", "Galaksi", "Andromeda", "2.537 Juta LY", "964 M", "Dalam Pengamatan", "3.44"},
        {5, "Ceres", "Asteroid", "N/A (Sabuk Asteroid)", "0.00028 LY", "1801", "Selesai Pengamatan", "6.64"},
        {6, "Crab Nebula", "Nebula", "Taurus", "6,500 LY", "1054", "Dalam Pengamatan", "8.4"},
        {7, "Proxima Centauri", "Bintang", "Centaurus", "4.24 LY", "1915", "Selesai Pengamatan", "11.13"},
        {8, "Saturnus", "Planet", "N/A (Tata Surya)", "0.00015 LY", "Zaman Kuno", "Selesai Pengamatan", "0.46"},
        {9, "Pillar of Creation", "Nebula", "Serpens", "6,500 - 7,000 LY", "1920", "Pengamatan Ditunda", "N/A"},
        {10, "Vega", "Bintang", "Lyra", "25 LY", "Zaman Kuno", "Selesai Pengamatan", "0.03"}
    }; 

    int n = sizeof(temp) / sizeof(temp[0]); 

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    ukuran = n; 
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

// ============================================================
// --- SECTION 4 — FUNGSI CRUD --------------------------------
// ============================================================
// --- CREATE
void tambahEntri(BendaLangit newEntri[], int &ukuran) {
    int pilihan; 
     
    if (ukuran >= MAXENTRI) {
        cout << "=> Data Entri sudah Penuh!" << endl; 
        system("pause");
        return; 
    }

    cout << "\n=== BUAT ENTRI BARU ===" << endl; 
    string newObjek, newKlasifikasi, newKonstelasi, newJarak, newTahun, newStatus, newMagnitudo;

    cin.ignore(); 
    cout << "Masukkan Nama Objek: "; getline(cin, newObjek); 
    cout << "Masukkan Klasifikasi Objek: "; getline(cin, newKlasifikasi); 
    cout << "Masukkan Konstelasi: "; getline(cin, newKonstelasi); 
    cout << "Masukkan Jarak Dari Bumi: "; getline(cin, newJarak); 
    cout << "Masukkan Tahun Ditemukan: "; getline(cin, newJarak); 
    cout << "Masukkan Status Observasi: "; getline(cin, newStatus); 
    cout << "Masukkan Magnitudo Objek: "; getline(cin, newMagnitudo); 

    newEntri[jumlahEntri].entriID = uniqueEntri + 1;
    newEntri[jumlahEntri].namaObjek = newObjek;
    newEntri[jumlahEntri].klasifikasi = newKlasifikasi;
    newEntri[jumlahEntri].konstelasi = newKonstelasi;
    newEntri[jumlahEntri].jarakDariBumi = newJarak;
    newEntri[jumlahEntri].tahunPenemuan = newTahun;
    newEntri[jumlahEntri].statusObservasi = newStatus;
    newEntri[jumlahEntri].magnitudo = newMagnitudo;
    jumlahEntri++; uniqueEntri++; 

    cout << "\n=> Entri Berhasil ditambahkan" << endl; 
    system("pause");
    return; 
}

// --- READ ---
// [1] Read Seluruh Entri
void lihatSeluruhEntri(BendaLangit entriTerdaftar[], int ukuran) {
    if (jumlahEntri == 0) {
        cout << "=> Tidak ada Entri yang Tersimpan!" << endl; 
        system("pause"); 
        return; 
    }

    cout << "\n=== DAFTAR SINGKAT ENTRI ===" << endl; 
    cout << "ID | Nama Objek | Klasifikasi | Konstelasi" << endl; 
    for (int i = 0; i < ukuran; i++) {
        if (i % 5 == 0 && i != 0) {
            cout << "--------------------------------------------------------------------------" << endl;
        }

        cout << entri[i].entriID
            << " | " << entri[i].namaObjek
            << " | " << entri[i].klasifikasi
            << " | " << entri[i].konstelasi
            << endl; 
    }

    system("pause");
}

// [2] Read Entri Spesifik
// --- Insert Kode Disini ---

// --- UPDATE ---
// --- Insert Kode Disini ---

// --- DELETE ---
void hapusEntri() {
    if (jumlahEntri == 0) {
        cout << "=> Tidak ada data" << endl;
        system("pause");
        return;
    }
    lihatSeluruhEntri(entri, jumlahEntri);
    int idHapus;
    cout << "Masukkan ID yang ingin dihapus: "; 
    cin >> idHapus;
    int idx = -1;
    for (int i = 0; i < jumlahEntri; i++) {
        if (entri[i].entriID == idHapus) { 
            idx = i;
            break; }
    }
    if (idx != -1) {
        char konfirmasi;
        cout << "Yakin hapus " << entri[idx].namaObjek << "? (y/n): "; 
        cin >> konfirmasi;
        if (konfirmasi == 'y' || konfirmasi == 'Y') {
            for (int j = idx; j < jumlahEntri - 1; j++) entri[j] = entri[j + 1];
            jumlahEntri--;
            cout << "=> " << entri[idx].namaObjek<< " Berhasil dihapus!" << endl;
        }
    } else cout << "=> ID tidak ditemukan!" << endl;
    system("pause");
}

// ============================================================
// --- SECTION 5 — FUNGSI SORTING & SEARCH --------------------
// ============================================================
// [ UNTUK SEMENTARA INI DI KOSONGKAN ]

// ============================================================
// --- SECTION 6 — AUTHORIZATION ------------------------------
// ============================================================
// --- Login ---
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

// ============================================================
// --- SECTION 7 — MENU HANDLER -------------------------------
// ============================================================
// --- Menu Utama ---
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

// --- Menu Admin & User
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
            tambahEntri(entri, jumlahEntri); 
        }
        else if (pilihan == 2) {
            cout << "=> Mengarahkan ke Menu 'Lihat Entri'" << endl;
            menuRead(); 
        }
        else if (pilihan == 3) {
            cout << "=> Mengarahkan ke Menu 'Perbarui Entri'" << endl;
        }
        else if (pilihan == 4) {
            cout << "=> Mengarahkan ke Menu 'Hapus Entri'" << endl;
            hapusEntri();
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
            menuRead(); 
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

// --- Menu Read ---
void menuRead () {
    int pilihan; 
    
    do {
        try {
            cout << "\n=== MENU READ ===" << endl; 
            cout << "1. Lihat Seluruh Entri" << endl; 
            cout << "2. Lihat Entri Spesifik" << endl; 
            cout << "-------------------------------------------" << endl; 
            
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

            if (pilihan > 2 || pilihan < 0) {
                throw length_error("Angka yang Dimasukkan Melebihi Range Menu!"); 
            }

            if (pilihan == 0) {
                cout << "=> Kembali ke Menu Sebelumnya" << endl; 
            }
            else if (pilihan == 1) {
                cout << "=> Menampilkan Seluruh Entri" << endl; 
                lihatSeluruhEntri(entri, jumlahEntri);
            }
            else if (pilihan == 2) {
                cout << "=> Menampilkan Entri Spesifik" << endl; 
            }
        }

        catch (const exception& e) {
            cout << "Error: " << e.what() << endl; 
        }

    } while (pilihan != 0);
}

// --- Menu Sort & Sort ---
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

// ============================================================
// --- SECTION 8 — MAIN ---------------------------------------
// ============================================================
int main() {
    penggunaAwal(akun, jumlahPengguna);
    entriAwal(entri, jumlahEntri);
    menuUtama(); 
    cout << endl;

    return 0;
}