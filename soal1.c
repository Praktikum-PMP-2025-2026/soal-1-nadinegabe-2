/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 3
 *   Hari dan Tanggal    : Selasa, 28 April 2026
 *   Nama (NIM)          : Nadine Gabe Ulina Sianturi (13224005)
 *   Nama File           : soal1.c
 *   Deskripsi           : menentukan penjaga terbaik pada tiap shift agar jadwal evaluasi dapat segera 
 * disusun berdasarkan skor, id dan nama, shift hanya ada 3 yaitu pagi, siang malam. Aturannya skor lebih tinggi lebih baik, jika skor sama, 
 * ID lebih kecil lebih baik, jika id sama, nama alfabetis lebih kecil lebih baik. 
 * 
 */


 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 typedef struct penjaga {
    char *name; 
    int id;
    char shift;
    int skor;
 } penjaga;

 void urutkan(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
  
 int main() {
    //deklarasi array dinamis
    penjaga *daftar = NULL;
    int jumlah_penjaga = 0;
    char buffer_name [100];

    int i,j, n;
    int temp;
    scanf("%d", &n);
    for (i = 0; i < n; i ++){
        jumlah_penjaga ++;
        daftar = (penjaga*) realloc(daftar, jumlah_penjaga * sizeof(penjaga));
        penjaga *p_baru = &daftar[jumlah_penjaga - 1];
        scanf("%s", &buffer_name);
        p_baru->name = (char*) malloc((strlen(buffer_name) + 1) * sizeof(char));
        strcpy(p_baru->name, buffer_name);
        scanf("%d", &p_baru->id);
        scanf("%s", &p_baru->shift);
        scanf("%d", &p_baru->skor);
        break;
    }

    if (strcmp("shift") = "PAGI") == 0 {
        urutkan(penjaga,n); 
        

        
    
    }

return 0;
}



    
