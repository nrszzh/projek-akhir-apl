#ifndef DATA_H
#define DATA_H

#include "types.h"

extern BendaLangit entri[MAXENTRI]; 
extern Pengguna akun[MAXPENGGUNA];
extern int jumlahEntri; 
extern int jumlahPengguna; 
extern int uniqueEntri; 
extern int uniqueUser; 

void penggunaAwal(Pengguna arr[], int &ukuran); 
void entriAwal(BendaLangit arr[], int &ukuran);

#endif