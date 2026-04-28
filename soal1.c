/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 3
 *   Hari dan Tanggal    : Selasa, 28 April 2026
 *   Nama (NIM)          : Nadine Gabe Ulina Sianturi (13224005)
 *   Nama File           : SOAL1.c
 *   Deskripsi           : menentukan penjaga terbaik pada tiap shift agar jadwal evaluasi dapat segera 
 * disusun berdasarkan skor, id dan nama, shift hanya ada 3 yaitu pagi, siang malam. Aturannya skor lebih tinggi lebih baik, jika skor sama, 
 * ID lebih kecil lebih baik, jika id sama, nama alfabetis lebih kecil lebih baik. 
 * 
 */




#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char *name;
    int id;
    char shift[20];
    int skor;
} penjaga;


char *copyName(char *asal) {
    char *baru = (char *) malloc((strlen(asal) + 1) * sizeof(char));

    if (baru == NULL) {
        exit(1);
    }

    strcpy(baru, asal);
    return baru;
}

/* mengecek apakah data a lebih baik dari b */
int isBetter(penjaga a, penjaga b) {
    if (a.skor > b.skor) {
        return 1;
    }

    if (a.skor < b.skor) {
        return 0;
    }

    if (a.id < b.id) {
        return 1;
    }

    if (a.id > b.id) {
        return 0;
    }

    if (strcmp(a.name, b.name) < 0) {
        return 1;
    }

    return 0;
}

void tampilShift(char *nameShift, penjaga arr[], int idx) {
    if (idx == -1) {
        printf("%s -\n", nameShift);
    } else {
        printf("%s %s %d %d\n",
               nameShift,
               arr[idx].name,
               arr[idx].id,
               arr[idx].skor);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    penjaga *arr = (penjaga *) malloc(n * sizeof(penjaga));

    if (arr == NULL) {
        return 1;
    }

    int pagi = -1;
    int siang = -1;
    int malam = -1;

    for (int i = 0; i < n; i++) {
        char temp[100];

        scanf("%s %d %s %d",
              temp,
              &arr[i].id,
              arr[i].shift,
              &arr[i].skor);

        arr[i].name = copyName(temp);

        if (strcmp(arr[i].shift, "PAGI") == 0) {
            if (pagi == -1 || isBetter(arr[i], arr[pagi])) {
                pagi = i;
            }
        }
        else if (strcmp(arr[i].shift, "SIANG") == 0) {
            if (siang == -1 || isBetter(arr[i], arr[siang])) {
                siang = i;
            }
        }
        else if (strcmp(arr[i].shift, "MALAM") == 0) {
            if (malam == -1 || isBetter(arr[i], arr[malam])) {
                malam = i;
            }
        }
    }

    tampilShift("PAGI", arr, pagi);
    tampilShift("SIANG", arr, siang);
    tampilShift("MALAM", arr, malam);

    for (int i = 0; i < n; i++) {
        free(arr[i].name);
    }

    free(arr);

    return 0;
}
