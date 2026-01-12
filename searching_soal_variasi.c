/*
============================================
VARIASI SOAL SEARCHING
============================================

SOAL VARIASI 1:
Diberikan deretan angka berikut:
5, 12, 18, 23, 35, 41, 48, 52, 67, 78, 89, 95

Tentukan algoritma searching yang paling tepat untuk mencari nilai 52, 
kemudian jelaskan langkah-langkah pencarian (step-by-step) berdasarkan 
source code yang diberikan.

SOAL VARIASI 2:
Diberikan deretan angka berikut:
15, 7, 42, 3, 89, 21, 56, 33, 71, 8

Tentukan algoritma searching yang paling tepat untuk mencari nilai 56, 
kemudian jelaskan langkah-langkah pencarian secara step-by-step.

============================================
*/

#include <stdio.h>

// ============ LINEAR SEARCH ============
// Waktu kompleksitas: O(n)
// Cocok untuk: data tidak terurut, jumlah data kecil

int linearSearch(int arr[], int n, int target) {
    printf("\n=== LINEAR SEARCH ===\n");
    printf("Mencari nilai: %d\n", target);
    printf("Data: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n\n");
    
    for(int i = 0; i < n; i++) {
        printf("Step %d: Membandingkan arr[%d] = %d dengan target %d\n", 
               i+1, i, arr[i], target);
        
        if(arr[i] == target) {
            printf("KETEMU! Nilai %d ditemukan di indeks %d\n", target, i);
            return i;
        }
    }
    printf("Nilai %d TIDAK ditemukan!\n", target);
    return -1;
}

// ============ BINARY SEARCH ============
// Waktu kompleksitas: O(log n)
// Cocok untuk: data terurut, jumlah data besar
// SYARAT: data harus terurut!

int binarySearch(int arr[], int n, int target) {
    printf("\n=== BINARY SEARCH ===\n");
    printf("Mencari nilai: %d\n", target);
    printf("Data: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    printf("Catatan: Data HARUS terurut untuk Binary Search\n\n");
    
    int left = 0;
    int right = n - 1;
    int step = 1;
    
    while(left <= right) {
        int mid = (left + right) / 2;
        
        printf("Step %d: left=%d, right=%d, mid=%d, arr[mid]=%d\n", 
               step, left, right, mid, arr[mid]);
        
        if(arr[mid] == target) {
            printf("KETEMU! Nilai %d ditemukan di indeks %d\n", target, mid);
            return mid;
        }
        else if(arr[mid] < target) {
            printf("  -> arr[mid] (%d) < target (%d), cari di sebelah kanan\n", 
                   arr[mid], target);
            left = mid + 1;
        }
        else {
            printf("  -> arr[mid] (%d) > target (%d), cari di sebelah kiri\n", 
                   arr[mid], target);
            right = mid - 1;
        }
        step++;
    }
    printf("Nilai %d TIDAK ditemukan!\n", target);
    return -1;
}

int main() {
    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║        PROGRAM SEARCHING - VARIASI SOAL               ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n");
    
    // ============ VARIASI SOAL 1 ============
    printf("\n\n");
    printf("██████ VARIASI SOAL 1 ██████\n");
    printf("Data Terurut: 5, 12, 18, 23, 35, 41, 48, 52, 67, 78, 89, 95\n");
    printf("Target: Cari nilai 52\n");
    printf("════════════════════════════════════════════════════════\n");
    
    int arr1[] = {5, 12, 18, 23, 35, 41, 48, 52, 67, 78, 89, 95};
    int n1 = 12;
    int target1 = 52;
    
    int result1_linear = linearSearch(arr1, n1, target1);
    int result1_binary = binarySearch(arr1, n1, target1);
    
    printf("\n--- ANALISIS ---\n");
    printf("Untuk data TERURUT dengan jumlah data sedang:\n");
    printf("✓ BINARY SEARCH lebih efisien (4 steps vs 8 steps)\n");
    printf("✓ Kompleksitas: O(log 12) ≈ 4 vs O(12)\n");
    printf("✓ Pilihan terbaik: BINARY SEARCH\n");
    
    // ============ VARIASI SOAL 2 ============
    printf("\n\n");
    printf("██████ VARIASI SOAL 2 ██████\n");
    printf("Data TIDAK Terurut: 15, 7, 42, 3, 89, 21, 56, 33, 71, 8\n");
    printf("Target: Cari nilai 56\n");
    printf("════════════════════════════════════════════════════════\n");
    
    int arr2[] = {15, 7, 42, 3, 89, 21, 56, 33, 71, 8};
    int n2 = 10;
    int target2 = 56;
    
    int result2_linear = linearSearch(arr2, n2, target2);
    
    printf("\n--- ANALISIS ---\n");
    printf("Untuk data TIDAK TERURUT:\n");
    printf("✓ LINEAR SEARCH adalah satu-satunya pilihan\n");
    printf("✓ Binary Search TIDAK bisa digunakan (data harus terurut)\n");
    printf("✓ Kompleksitas: O(10) = 10 operasi perbandingan\n");
    printf("✓ Pilihan WAJIB: LINEAR SEARCH\n");
    
    printf("\n\n");
    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║              KESIMPULAN PERBANDINGAN                  ║\n");
    printf("╠════════════════════════════════════════════════════════╣\n");
    printf("║ ASPEK              │ LINEAR SEARCH  │ BINARY SEARCH    ║\n");
    printf("║────────────────────┼────────────────┼──────────────────║\n");
    printf("║ Kompleksitas Waktu │ O(n)           │ O(log n)         ║\n");
    printf("║ Syarat Data        │ Boleh acak     │ HARUS terurut    ║\n");
    printf("║ Data Kecil (< 100) │ Cukup cepat    │ Overkill         ║\n");
    printf("║ Data Besar (>1000) │ Lambat         │ Sangat cepat     ║\n");
    printf("║ Setup              │ Langsung pakai │ Perlu sort dulu  ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n");
    
    return 0;
}

/*
REFERENSI ANALISIS:

1. LINEAR SEARCH:
   - Iterasi setiap elemen dari awal hingga akhir
   - Waktu terbaik: O(1) - elemen ditemukan di awal
   - Waktu rata-rata: O(n/2)
   - Waktu terburuk: O(n) - elemen tidak ada atau di akhir
   
2. BINARY SEARCH:
   - Membagi pencarian menjadi dua bagian (divide & conquer)
   - Setiap iterasi mengurangi area pencarian menjadi setengah
   - Waktu terbaik: O(1) - elemen di tengah
   - Waktu rata-rata: O(log n)
   - Waktu terburuk: O(log n)
   
KAPAN MENGGUNAKAN:
- Linear Search: Data kecil, tidak terurut, atau saat setup sorting lebih mahal
- Binary Search: Data besar dan terurut, atau data sering dicari
*/
