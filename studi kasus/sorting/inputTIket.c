#include <stdio.h>
#include <stdlib.h>

// Struktur untuk menyimpan informasi tiket
struct Tiket {
    int id_tiket;
    char jurusan[50];
    float harga;
};

// Variabel global untuk menyimpan data tiket
struct Tiket dataTiket[100]; // Maksimum 100 data tiket

// Deklarasi fungsi
void isiData();
void tampilkanDataTiket(int jumlahData);
void bubbleSort(struct Tiket *arr, int n);

int main() {
    int pilihan;
    int jumlahData = 0;

    do {
        printf("Menu:\n");
        printf("1. Isi Data\n");
        printf("2. Tampilkan Data Tiket\n");
        printf("3. Keluar Program\n");
        printf("Pilih menu (1-3): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                isiData(&jumlahData);
                break;
            case 2:
                bubbleSort(dataTiket, jumlahData); // Mengurutkan data sebelum menampilkan
                tampilkanDataTiket(jumlahData);
                break;
            case 3:
                printf("Keluar dari program...\n");
                exit(0);
                break;
            default:
                printf("Pilihan tidak valid!.\n");
        }
    } while (1); // Loop terus menerus sampai pengguna memilih untuk keluar

    return 0;
}

void isiData(int *jumlahData) {
    // Meminta pengguna untuk memasukkan informasi tiket
    printf("ID Tiket: ");
    scanf("%d", &(dataTiket[*jumlahData].id_tiket));
    printf("Jurusan: ");
    scanf("%s", dataTiket[*jumlahData].jurusan);
    printf("Harga: ");
    scanf("%f", &(dataTiket[*jumlahData].harga));

    // Menambahkan jumlah data tiket
    (*jumlahData)++;

    // Konfirmasi bahwa data telah dimasukkan
    printf("Data tiket telah dimasukkan.\n");
}

void tampilkanDataTiket(int jumlahData) {
    if (jumlahData == 0) {
        printf("Belum ada data tiket yang dimasukkan.\n");
        return;
    }

    printf("Data Tiket:\n");
    printf("ID Tiket\tJurusan\t\tHarga\n");
    for (int i = 0; i < jumlahData; i++) {
        printf("%d\t\t%s\t\t%.2f\n", dataTiket[i].id_tiket, dataTiket[i].jurusan, dataTiket[i].harga);
    }
}
    void bubbleSort(struct Tiket *arr, int n) {
    int i, j;
    struct Tiket temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j].id_tiket > arr[j+1].id_tiket) {
                // Tukar elemen jika urutannya salah
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
