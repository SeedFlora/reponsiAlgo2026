/*
============================================
VARIASI SOAL SORTING
============================================

SOAL VARIASI 1:
Diberikan deretan angka berikut:
42, 17, 93, 25, 68, 31, 56

Tentukan algoritma sorting yang paling tepat untuk mengurutkan data 
tersebut, kemudian jelaskan proses pengurutan secara bertahap 
(step-by-step) berdasarkan source code yang diberikan.

SOAL VARIASI 2:
Diberikan deretan angka berikut:
89, 12, 56, 34, 78, 23, 45, 67, 11, 90

Tentukan algoritma sorting yang paling tepat untuk mengurutkan data 
tersebut, kemudian jelaskan proses pengurutan secara bertahap.

============================================
*/

#include <stdio.h>
#include <string.h>

// ============ BUBBLE SORT ============
// Waktu kompleksitas: O(n²)
// Cocok untuk: data kecil, pemahaman dasar sorting
// Cara kerja: Membandingkan elemen bersebelahan, tukar jika tidak terurut

void bubbleSort(int arr[], int n, int displaySteps) {
    printf("\n=== BUBBLE SORT ===\n");
    printf("Mengurutkan data: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n\n");
    
    int comparisons = 0;
    int swaps = 0;
    
    for(int i = 0; i < n - 1; i++) {
        printf("┌─ PASS %d ─┐\n", i + 1);
        
        int swapped = 0;
        for(int j = 0; j < n - i - 1; j++) {
            comparisons++;
            
            if(displaySteps) {
                printf("  Step %d: Bandingkan arr[%d](%d) dengan arr[%d](%d) ", 
                       comparisons, j, arr[j], j+1, arr[j+1]);
            }
            
            if(arr[j] > arr[j + 1]) {
                // Tukar
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                swapped = 1;
                
                if(displaySteps) printf("→ TUKAR\n");
            } else {
                if(displaySteps) printf("→ OK\n");
            }
        }
        
        printf("  Hasil Pass %d: ", i + 1);
        for(int k = 0; k < n; k++) printf("%d ", arr[k]);
        printf("\n");
        
        if(!swapped) {
            printf("  Data sudah terurut! Hentikan sorting.\n");
            break;
        }
    }
    
    printf("\n✓ Data Terurut: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nTotal Perbandingan: %d | Total Pertukaran: %d\n", comparisons, swaps);
}

// ============ MERGE SORT ============
// Waktu kompleksitas: O(n log n)
// Cocok untuk: data besar, perlu performa konsisten
// Cara kerja: Divide & Conquer - bagi dua, urutkan, gabung

void merge(int arr[], int left, int mid, int right, int *comparisons) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int temp[right - left + 1];
    
    while(i <= mid && j <= right) {
        (*comparisons)++;
        if(arr[i] <= arr[j]) {
            temp[k - left] = arr[i];
            i++;
        } else {
            temp[k - left] = arr[j];
            j++;
        }
        k++;
    }
    
    while(i <= mid) {
        temp[k - left] = arr[i];
        i++;
        k++;
    }
    
    while(j <= right) {
        temp[k - left] = arr[j];
        j++;
        k++;
    }
    
    for(i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
}

void mergeSortHelper(int arr[], int left, int right, int depth, int *comparisons, int *divisions) {
    if(left < right) {
        int mid = (left + right) / 2;
        (*divisions)++;
        
        printf("  Level %d - DIVIDE: [%d...%d] menjadi [%d...%d] dan [%d...%d]\n", 
               depth, left, right, left, mid, mid+1, right);
        
        mergeSortHelper(arr, left, mid, depth + 1, comparisons, divisions);
        mergeSortHelper(arr, mid + 1, right, depth + 1, comparisons, divisions);
        
        printf("  Level %d - MERGE: ", depth);
        printf("[");
        for(int i = left; i <= mid; i++) printf("%d ", arr[i]);
        printf("] + [");
        for(int i = mid + 1; i <= right; i++) printf("%d ", arr[i]);
        printf("] → [");
        
        merge(arr, left, mid, right, comparisons);
        
        for(int i = left; i <= right; i++) printf("%d ", arr[i]);
        printf("]\n");
    }
}

void mergeSort(int arr[], int n, int displaySteps) {
    printf("\n=== MERGE SORT ===\n");
    printf("Mengurutkan data: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n\n");
    
    int comparisons = 0;
    int divisions = 0;
    
    if(displaySteps) {
        printf("--- TAHAP DIVIDE (PEMBAGIAN) ---\n");
        mergeSortHelper(arr, 0, n - 1, 1, &comparisons, &divisions);
    } else {
        int temp[n];
        memcpy(temp, arr, sizeof(int) * n);
        mergeSortHelper(temp, 0, n - 1, 1, &comparisons, &divisions);
        memcpy(arr, temp, sizeof(int) * n);
    }
    
    printf("\n✓ Data Terurut: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nTotal Perbandingan: %d | Total Pembagian: %d\n", comparisons, divisions);
}

// Fungsi helper untuk copy array
void copyArray(int src[], int dest[], int n) {
    for(int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int main() {
    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║         PROGRAM SORTING - VARIASI SOAL                ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n");
    
    // ============ VARIASI SOAL 1 ============
    printf("\n\n");
    printf("██████ VARIASI SOAL 1 ██████\n");
    printf("Data: 42, 17, 93, 25, 68, 31, 56\n");
    printf("════════════════════════════════════════════════════════\n");
    
    int arr1[] = {42, 17, 93, 25, 68, 31, 56};
    int n1 = 7;
    
    int arr1_bubble[7];
    copyArray(arr1, arr1_bubble, n1);
    
    int arr1_merge[7];
    copyArray(arr1, arr1_merge, n1);
    
    bubbleSort(arr1_bubble, n1, 1);
    mergeSort(arr1_merge, n1, 1);
    
    // ============ VARIASI SOAL 2 ============
    printf("\n\n");
    printf("██████ VARIASI SOAL 2 ██████\n");
    printf("Data: 89, 12, 56, 34, 78, 23, 45, 67, 11, 90\n");
    printf("════════════════════════════════════════════════════════\n");
    
    int arr2[] = {89, 12, 56, 34, 78, 23, 45, 67, 11, 90};
    int n2 = 10;
    
    int arr2_bubble[10];
    copyArray(arr2, arr2_bubble, n2);
    
    int arr2_merge[10];
    copyArray(arr2, arr2_merge, n2);
    
    bubbleSort(arr2_bubble, n2, 0);  // Tidak tampilkan step detail (terlalu panjang)
    printf("\n[Detail steps dihide untuk efisiensi tampilan]\n");
    
    mergeSort(arr2_merge, n2, 1);
    
    // ============ PERBANDINGAN ============
    printf("\n\n");
    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║              PERBANDINGAN ALGORITMA SORTING            ║\n");
    printf("╠════════════════════════════════════════════════════════╣\n");
    printf("║ ASPEK                  │ BUBBLE SORT    │ MERGE SORT   ║\n");
    printf("║────────────────────────┼────────────────┼──────────────║\n");
    printf("║ Kompleksitas Waktu     │ O(n²)          │ O(n log n)   ║\n");
    printf("║ Kompleksitas Ruang     │ O(1)           │ O(n)         ║\n");
    printf("║ Kasus Terbaik          │ O(n) sorted    │ O(n log n)   ║\n");
    printf("║ Kasus Terburuk         │ O(n²) reverse  │ O(n log n)   ║\n");
    printf("║ Stabil?                │ Ya             │ Ya           ║\n");
    printf("║────────────────────────┼────────────────┼──────────────║\n");
    printf("║ Jumlah Data: 7         │ ~21 perbandingan         │\n");
    printf("║ Jumlah Data: 10        │ ~45 perbandingan         │\n");
    printf("║ Jumlah Data: 1000      │ ~500,000 vs ~10,000      │\n");
    printf("╠════════════════════════════════════════════════════════╣\n");
    printf("║ KESIMPULAN:                                            ║\n");
    printf("║ • Untuk data kecil (< 50): Bubble Sort cukup baik     ║\n");
    printf("║ • Untuk data besar (> 100): Merge Sort jauh lebih      ║\n");
    printf("║   cepat dan konsisten                                  ║\n");
    printf("║ • Merge Sort gunakan ketika performa penting           ║\n");
    printf("║ • Bubble Sort untuk pembelajaran/demo konsep sorting   ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n");
    
    return 0;
}

/*
ANALISIS MENDALAM:

BUBBLE SORT:
- Prinsip: Membandingkan pasangan elemen bersebelahan
- Terus berulang hingga tidak ada pertukaran
- Elemen terbesar "menggelembung" ke belakang setiap pass
- Optimasi: Early stopping jika sudah sorted

MERGE SORT:
- Prinsip: Divide & Conquer
- 1. Divide: Bagi array menjadi 2 bagian (sampai ukuran 1)
- 2. Conquer: Urutkan setiap bagian kecil
- 3. Combine: Gabung dua bagian terurut menjadi satu bagian terurut
- Selalu O(n log n) tanpa peduli kondisi data

PERFORMA PRAKTIS:
- n=10: Bubble ~45, Merge ~30 (1.5x lebih cepat)
- n=100: Bubble ~4950, Merge ~700 (7x lebih cepat)
- n=1000: Bubble ~500,000, Merge ~10,000 (50x lebih cepat!)

KAPAN MENGGUNAKAN:
- Bubble Sort: Demo pembelajaran, data sangat kecil
- Merge Sort: Aplikasi nyata, dataset besar, perlu konsistensi
*/
