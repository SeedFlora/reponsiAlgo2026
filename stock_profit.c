#include <stdio.h>

// Struktur untuk menyimpan data saham
struct Stock {
    int day;      // Nomor hari
    int price;    // Harga saham pada hari tersebut
};

int main() {
    // ===== BACA FILE INPUT =====
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error: File data.txt tidak bisa dibuka!\n");
        return 0;
    }

    // Baca jumlah hari
    int n;
    fscanf(fp, "%d", &n);

    // Baca harga saham setiap hari ke dalam struct array
    struct Stock data[100];
    for (int i = 0; i < n; i++) {
        data[i].day = i + 1;           // Hari dimulai dari 1
        fscanf(fp, "%d", &data[i].price);  // Baca harga dari file
    }
    fclose(fp);

    // ===== PROSES DATA =====
    // Variabel untuk menyimpan hasil
    int minPrice = data[0].price;   // Harga terendah
    int minDay = data[0].day;       // Hari harga terendah
    int maxProfit = 0;              // Keuntungan maksimal
    int buyDay = 0, sellDay = 0;    // Hari beli dan jual

    // Algoritma single pass - cari profit maksimal
    for (int i = 1; i < n; i++) {
        // Hitung profit jika jual pada hari i
        int profit = data[i].price - minPrice;

        // Update profit maksimal jika profit hari ini lebih besar
        if (profit > maxProfit) {
            maxProfit = profit;
            buyDay = minDay;        // Beli pada hari harga terendah
            sellDay = data[i].day;  // Jual pada hari i
        }

        // Update harga terendah jika harga hari ini lebih rendah
        if (data[i].price < minPrice) {
            minPrice = data[i].price;
            minDay = data[i].day;
        }
    }

    // ===== TULIS KE FILE OUTPUT =====
    FILE *out = fopen("summary.txt", "w");
    if (out == NULL) {
        printf("Error: File summary.txt gagal dibuat!\n");
        return 0;
    }

    // Tulis hasil analisis
    fprintf(out, "=== ANALISIS SAHAM ===\n\n");
    fprintf(out, "Total hari         : %d\n", n);
    fprintf(out, "Harga terendah     : %d (Hari %d)\n", minPrice, minDay);
    fprintf(out, "Keuntungan maksimal: %d\n\n", maxProfit);

    if (maxProfit > 0) {
        fprintf(out, "Strategi terbaik:\n");
        fprintf(out, "- Beli  pada hari %d dengan harga %d\n", buyDay, minPrice);
        fprintf(out, "- Jual  pada hari %d dengan harga %d\n", sellDay, minPrice + maxProfit);
        fprintf(out, "- Keuntungan: %d\n", maxProfit);
    } else {
        fprintf(out, "Status: Tidak ada peluang keuntungan\n");
        fprintf(out, "Keuntungan: 0\n");
    }

    fclose(out);

    // ===== TAMPILKAN DI TERMINAL JUGA =====
    printf("========================================\n");
    printf("     PROGRAM ANALISIS HARGA SAHAM\n");
    printf("========================================\n\n");
    printf("DATA YANG DIBACA DARI FILE:\n");
    printf("Jumlah hari: %d\n", n);
    printf("Harga: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i].price);
    }
    printf("\n\n");

    printf("HASIL ANALISIS:\n");
    printf("- Harga terendah     : %d (Hari %d)\n", minPrice, minDay);
    printf("- Keuntungan maksimal: %d\n", maxProfit);
    
    if (maxProfit > 0) {
        printf("\nStrategi terbaik:\n");
        printf("  Beli  hari %d (harga %d)\n", buyDay, minPrice);
        printf("  Jual  hari %d (harga %d)\n", sellDay, minPrice + maxProfit);
        printf("  Profit: %d\n", maxProfit);
    } else {
        printf("\nTidak ada peluang keuntungan (profit = 0)\n");
    }

    printf("\n========================================\n");
    printf("✓ Output tersimpan di file summary.txt\n");
    printf("========================================\n");

    return 0;
}
