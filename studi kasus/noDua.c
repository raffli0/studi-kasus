#include <stdio.h>

typedef struct {
    char nama_pemesanan[20];
    int kode_jurusan;
    int jumlah_tiket;
    int total_penjualan;
} dataPenjualan;

int main() {
    dataPenjualan data[100];
    int index = 0;
    int i, jumlah_data;
    int x;

    // Input data
    char jawab;
    do {
        printf("Masukkan nama pemesanan: ");
        scanf("%s", data[index].nama_pemesanan);
        printf("Masukkan kode jurusan (1,2,3,4): ");
        scanf("%d", &data[index].kode_jurusan);
        printf("Masukkan jumlah tiket: ");
        scanf("%d", &data[index].jumlah_tiket);

        // Hitung harga total
        switch (data[index].jumlah_tiket) {
            case 1:
                data[index].total_penjualan = 100000 * data[index].jumlah_tiket;
                break;
            case 2:
                data[index].total_penjualan = 100000 * data[index].jumlah_tiket;
                break;
            case 3:
                data[index].total_penjualan = 300000 * data[index].jumlah_tiket;
                break;
            case 4:
                data[index].total_penjualan = 300000 * data[index].jumlah_tiket;
                break;
            default:
                printf("Jumlah tiket salah!\n");
                return 1;
        }

        // Diskon jika jumlah tiket lebih dari 3
        if (data[index].jumlah_tiket >= 3) {
            data[index].total_penjualan *= 0.5; // Apply 10% discount
        }

        printf("Data berhasil diinput! Tambah lagi? (Y/T): ");
        scanf(" %c", &jawab);
        index++;

    } while (jawab == 'Y' || jawab == 'y');

    // Input batas nilai x
    printf("Cari data yang total penjulannya lebih dari (X): ");
    scanf("%d", &x);

    // Tampilkan rekap penjualan
printf("\nRekap penjualan tiket:\n");
jumlah_data = index;
int found = 0; // To keep track if any records are found
for (i = 0; i < jumlah_data; i++) {
    if (data[i].total_penjualan < x) {
        found = 1; // Set found to 1 if any records are found
        printf("%d\n", i + 1);
        printf("Nama Pemesanan: %s\n", data[i].nama_pemesanan);
        printf("Jenis Transportasi: ");
        switch (data[i].kode_jurusan) {
            case 1:
                printf("Bandung-Jakarta\n");
                break;
            case 2:
                printf("Jakarta-Bandung\n");
                break;
            case 3:
                printf("Bandung-Surabaya\n");
                break;
            case 4:
                printf("Surabaya-Bandung\n");
                break;
            default:
                printf("Kode jurusan tidak valid\n");
        }
        printf("Total penjualan: %d\n", data[i].total_penjualan);
        printf("\n");
    }
}

// If no records are found, inform the user
if (!found) {
    printf("Tidak ada penjualan tiket dengan total penjualan kurang dari %d\n", x);
}

}
