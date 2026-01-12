# 📝 EXAM PREPARATION GUIDE

> **Panduan Lengkap Persiapan Ujian: Searching & Sorting Algorithms**

---

## 📌 Daftar Isi
1. [Ringkasan Materi](#ringkasan-materi)
2. [Cheat Sheet](#cheat-sheet)
3. [Soal Latihan Lengkap](#soal-latihan-lengkap)
4. [Strategi Menjawab](#strategi-menjawab)
5. [Common Mistakes](#common-mistakes)
6. [Practice Problems](#practice-problems)

---

## 📚 Ringkasan Materi

### SEARCHING ALGORITHMS

#### 1. LINEAR SEARCH (Sequential Search)

**Definisi:**
- Mencari elemen dengan membandingkan setiap elemen satu per satu
- Dari elemen pertama hingga elemen terakhir
- Berhenti saat ditemukan atau array habis

**Pseudocode:**
```
function linearSearch(arr[], target):
    for i = 0 to length(arr) - 1:
        if arr[i] == target:
            return i
    return -1
```

**Karakteristik:**
| Aspek | Nilai |
|-------|-------|
| **Best Case** | O(1) - ditemukan di awal |
| **Average Case** | O(n/2) - ditemukan di tengah |
| **Worst Case** | O(n) - tidak ditemukan atau di akhir |
| **Space Complexity** | O(1) |
| **Syarat Data** | Boleh acak atau terurut |
| **Stable** | Ya |

**Kapan Digunakan:**
- ✅ Data tidak terurut
- ✅ Jumlah data kecil (< 100)
- ✅ Hanya dicari sekali
- ✅ Memory sangat terbatas

**Kapan TIDAK Digunakan:**
- ❌ Data besar (> 100,000)
- ❌ Data dicari berkali-kali (gunakan index)
- ❌ Tersedia data terurut (gunakan binary)

---

#### 2. BINARY SEARCH (Logarithmic Search)

**Definisi:**
- Mencari elemen dengan membagi array menjadi dua bagian
- Setiap iterasi mengeliminasi setengah data
- Paradigma: Divide & Conquer

**Pseudocode:**
```
function binarySearch(arr[], target):
    left = 0
    right = length(arr) - 1
    
    while left <= right:
        mid = (left + right) / 2
        
        if arr[mid] == target:
            return mid
        else if arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1
```

**Karakteristik:**
| Aspek | Nilai |
|-------|-------|
| **Best Case** | O(1) - ditemukan di tengah |
| **Average Case** | O(log n) - log₂(n) steps |
| **Worst Case** | O(log n) - consistent |
| **Space Complexity** | O(1) iterative, O(log n) recursive |
| **Syarat Data** | HARUS terurut! |
| **Stable** | Ya |

**Kapan Digunakan:**
- ✅ Data TERURUT (requirement!)
- ✅ Data besar (> 100)
- ✅ Dicari berkali-kali
- ✅ Performa penting

**Kapan TIDAK Digunakan:**
- ❌ Data tidak terurut (sort dulu expensive)
- ❌ Data linked list (tidak bisa akses O(1))
- ❌ Data sedikit & hanya cari sekali

**Perbandingan Performa:**

```
Dataset Size    Linear Search    Binary Search    Ratio
─────────────────────────────────────────────────────
10              10 steps         4 steps          2.5x
100             100 steps        7 steps          14x
1,000           1,000 steps      10 steps         100x
10,000          10,000 steps     14 steps         714x
1,000,000       1,000,000 steps  20 steps         50,000x!!!
```

**⭐ Key Insight:**
> Untuk 1 juta data, Binary Search hanya butuh 20 perbandingan! Linear membutuhkan rata-rata 500,000 perbandingan. **Binary Search 50,000x lebih cepat!**

---

### SORTING ALGORITHMS

#### 1. BUBBLE SORT (Exchange Sort)

**Definisi:**
- Algoritma sorting sederhana
- Membandingkan elemen bersebelahan
- Menukar jika urutan salah
- Elemen terbesar "menggelembung" ke akhir setiap pass

**Pseudocode:**
```
function bubbleSort(arr[]):
    n = length(arr)
    
    for i = 0 to n - 2:
        swapped = false
        
        for j = 0 to n - i - 2:
            if arr[j] > arr[j + 1]:
                swap(arr[j], arr[j + 1])
                swapped = true
        
        if not swapped:
            break  // Optimization: early stop
```

**Karakteristik:**
| Aspek | Nilai |
|-------|-------|
| **Best Case** | O(n) - data sudah terurut + early stop |
| **Average Case** | O(n²) |
| **Worst Case** | O(n²) - data reverse sorted |
| **Space Complexity** | O(1) - in-place |
| **Stable** | Ya - maintain relative order |
| **Adaptive** | Ya - lebih cepat jika data partial sorted |

**Visualisasi Pass-by-Pass:**

```
Data: [5, 2, 8, 1, 9]

Pass 1: (perbandingan 4x, tukar 3x)
[5,2] → [2,5]
[5,8] → OK
[8,1] → [1,8]
[8,9] → OK
Hasil: [2, 5, 1, 8, 9]

Pass 2: (perbandingan 3x, tukar 2x)
[2,5] → OK
[5,1] → [1,5]
[5,8] → OK
Hasil: [2, 1, 5, 8, 9]

Pass 3: (perbandingan 2x, tukar 1x)
[2,1] → [1,2]
[2,5] → OK
Hasil: [1, 2, 5, 8, 9]

Pass 4: (perbandingan 1x, tukar 0x)
[1,2] → OK
Hasil: [1, 2, 5, 8, 9] ✓ SORTED!
```

**Kapan Digunakan:**
- ✅ Data sangat kecil (< 50)
- ✅ Pembelajaran algoritma
- ✅ Deteksi apakah data sudah sorted
- ✅ Memory sangat terbatas

**Kapan TIDAK Digunakan:**
- ❌ Data besar (performa O(n²))
- ❌ Production code
- ❌ Real-time systems

---

#### 2. MERGE SORT (Divide & Conquer)

**Definisi:**
- Algoritma divide & conquer
- Bagi array menjadi dua bagian hingga unit tunggal
- Urutkan & gabung kembali
- Konsisten O(n log n) dalam semua kasus

**Pseudocode:**
```
function mergeSort(arr[], left, right):
    if left < right:
        mid = (left + right) / 2
        
        mergeSort(arr, left, mid)        // Divide & sort left
        mergeSort(arr, mid + 1, right)   // Divide & sort right
        merge(arr, left, mid, right)     // Merge
    
function merge(arr[], left, mid, right):
    leftArr = arr[left...mid]
    rightArr = arr[mid+1...right]
    
    i = j = k = 0
    
    while i < length(leftArr) and j < length(rightArr):
        if leftArr[i] <= rightArr[j]:
            arr[k] = leftArr[i]
            i++
        else:
            arr[k] = rightArr[j]
            j++
        k++
    
    // Copy sisa
    while i < length(leftArr):
        arr[k] = leftArr[i]
        i++, k++
    
    while j < length(rightArr):
        arr[k] = rightArr[j]
        j++, k++
```

**Karakteristik:**
| Aspek | Nilai |
|-------|-------|
| **Best Case** | O(n log n) |
| **Average Case** | O(n log n) |
| **Worst Case** | O(n log n) - CONSISTENT |
| **Space Complexity** | O(n) - temporary arrays |
| **Stable** | Ya - maintain relative order |
| **Adaptive** | Tidak - same untuk semua kasus |

**Visualisasi Divide & Merge:**

```
Data: [38, 27, 43, 3, 9, 82, 10]

DIVIDE PHASE:
Level 0: [38, 27, 43, 3, 9, 82, 10]
Level 1: [38, 27, 43, 3] [9, 82, 10]
Level 2: [38, 27] [43, 3] [9, 82] [10]
Level 3: [38] [27] [43] [3] [9] [82] [10]

MERGE PHASE:
Merge: [38] + [27] → [27, 38]
Merge: [43] + [3] → [3, 43]
Merge: [27,38] + [3,43] → [3, 27, 38, 43]
Merge: [9] + [82] → [9, 82]
Merge: [9,82] + [10] → [9, 10, 82]
Merge: [3,27,38,43] + [9,10,82] → [3, 9, 10, 27, 38, 43, 82] ✓
```

**Kapan Digunakan:**
- ✅ Data besar (> 100)
- ✅ Performa penting
- ✅ Worst case guarantee penting
- ✅ Linked lists (O(n) access)

**Kapan TIDAK Digunakan:**
- ❌ Data sangat kecil (overhead divide)
- ❌ Memory sangat terbatas (O(n) space)
- ❌ Cache efficiency penting (jumps memory)

---

### PERBANDINGAN KOMPLEKSITAS

```
┌─────────────────────┬──────────────┬──────────────┬──────────────┐
│ Algorithm           │ Best Case    │ Average Case │ Worst Case   │
├─────────────────────┼──────────────┼──────────────┼──────────────┤
│ Linear Search       │ O(1)         │ O(n/2)       │ O(n)         │
│ Binary Search       │ O(1)         │ O(log n)     │ O(log n)     │
├─────────────────────┼──────────────┼──────────────┼──────────────┤
│ Bubble Sort         │ O(n)*        │ O(n²)        │ O(n²)        │
│ Merge Sort          │ O(n log n)   │ O(n log n)   │ O(n log n)   │
└─────────────────────┴──────────────┴──────────────┴──────────────┘
* Dengan optimasi early-stop
```

---

## 💾 Cheat Sheet

### Mana yang Dipilih?

```
UNTUK SEARCHING:
┌─ Data TERURUT? ─┐
│                 └─→ Binary Search (O(log n)) ⭐
│
└─ Data ACAK?
                 └─→ Linear Search (O(n))

UNTUK SORTING:
┌─ Data < 50? ────────────→ Bubble Sort (simple)
├─ Data 50-1000? ─────────→ Merge Sort (balance)
└─ Data > 1000? ──────────→ Merge Sort (scalable)

PRODUCTION CODE:
└─ Gunakan library sort atau Quick Sort
```

---

### Formula Cepat

```
Linear Search:
└─ Best: 1 comparison
└─ Average: n/2 comparisons
└─ Worst: n comparisons

Binary Search:
└─ Any: log₂(n) comparisons
└─ Contoh: 1 juta data = log₂(1,000,000) ≈ 20 steps

Bubble Sort:
└─ Pass: n-1 passes
└─ Comparisons per pass: n-1, n-2, ..., 1
└─ Total: (n-1 + n-2 + ... + 1) = n(n-1)/2 ≈ n²/2

Merge Sort:
└─ Divisions: log₂(n) levels
└─ Merges per level: n comparisons
└─ Total: n × log₂(n) = n log n
```

---

## 🧠 Soal Latihan Lengkap

### SOAL 1: Linear Search
```
Diberikan array: [15, 8, 23, 42, 16, 4, 50]
Cari nilai: 42
```

**Jawaban:**
```
Step 1: arr[0]=15 ≠ 42
Step 2: arr[1]=8 ≠ 42
Step 3: arr[2]=23 ≠ 42
Step 4: arr[3]=42 = 42 ✓ FOUND at index 3

Total Comparisons: 4
Complexity: O(n) - dalam hal ini O(7) tetapi ketemu di step 4
```

---

### SOAL 2: Binary Search
```
Diberikan array TERURUT: [2, 5, 8, 12, 16, 23, 38, 45, 50]
Cari nilai: 23
```

**Jawaban:**
```
Iterasi 1:
  left=0, right=8, mid=4
  arr[4]=16 < 23 → search right
  left=5

Iterasi 2:
  left=5, right=8, mid=6
  arr[6]=38 > 23 → search left
  right=5

Iterasi 3:
  left=5, right=5, mid=5
  arr[5]=23 = 23 ✓ FOUND at index 5

Total Comparisons: 3 (vs 6 dengan Linear Search)
Complexity: O(log n) = O(log₂(9)) ≈ 3.17
```

---

### SOAL 3: Bubble Sort
```
Diberikan array: [5, 2, 8, 1, 9]
Urutkan dengan Bubble Sort
```

**Jawaban:**
```
PASS 1:
  Compare 5,2 → Swap → [2,5,8,1,9]
  Compare 5,8 → OK → [2,5,8,1,9]
  Compare 8,1 → Swap → [2,5,1,8,9]
  Compare 8,9 → OK → [2,5,1,8,9]
  Swaps: 2, Result: [2,5,1,8,9]

PASS 2:
  Compare 2,5 → OK
  Compare 5,1 → Swap → [2,1,5,8,9]
  Compare 5,8 → OK
  Swaps: 1, Result: [2,1,5,8,9]

PASS 3:
  Compare 2,1 → Swap → [1,2,5,8,9]
  Compare 2,5 → OK
  Swaps: 1, Result: [1,2,5,8,9]

PASS 4:
  Compare 1,2 → OK
  Swaps: 0, Result: [1,2,5,8,9]
  No swaps → STOP (early termination)

FINAL: [1,2,5,8,9] ✓
Total Comparisons: 4+3+2+1 = 10
Total Swaps: 4
Complexity: O(n²) = O(25) tetapi early stop lebih cepat
```

---

### SOAL 4: Merge Sort
```
Diberikan array: [38, 27, 43, 3, 9]
Urutkan dengan Merge Sort
```

**Jawaban:**
```
DIVIDE:
[38, 27, 43, 3, 9]
    ↙          ↘
[38, 27]      [43, 3, 9]
  ↙  ↘        ↙    ↘
[38] [27]  [43]   [3, 9]
               ↙  ↘
             [3]  [9]

MERGE:
[38] + [27] → [27, 38]
[43] + [3] → [3, 43]
[9] → [9]

[27, 38] + [3, 43] → [3, 27, 38, 43]
[3, 27, 38, 43] + [9] → [3, 9, 27, 38, 43] ✓

FINAL: [3, 9, 27, 38, 43]
Total Comparisons: ~8
Total Divisions: 4
Complexity: O(n log n) = O(9 × log₂(5)) ≈ O(23)
```

---

## 📖 Strategi Menjawab

### SEARCHING QUESTIONS

**Langkah 1: Identifikasi Data**
```
✓ Apakah data terurut?
  - YA → Binary Search (O(log n))
  - TIDAK → Linear Search (O(n))
✓ Berapa jumlah data?
  - Kecil < 100 → Linear OK
  - Besar > 100 → Binary (jika terurut)
✓ Berapa kali dicari?
  - Sekali → Hanya cari langsung
  - Banyak → Pertimbangkan index/sort dulu
```

**Langkah 2: Step-by-Step Trace**
```
✓ Tunjukkan setiap iterasi
✓ Tunjukkan kondisi (left, right, mid untuk binary)
✓ Tunjukkan perbandingan yang terjadi
✓ Tunjukkan kapan ketemu atau tidak
```

**Langkah 3: Analisis Kompleksitas**
```
✓ Best case: elemen ada di awal
✓ Average case: rata-rata
✓ Worst case: elemen tidak ada atau di akhir
✓ Bandingkan dengan O(n) atau O(log n)
```

**Langkah 4: Kesimpulan**
```
✓ Pilih algoritma terbaik untuk kasus
✓ Jelaskan alasan pemilihan
✓ Estimasi performa untuk data besar
✓ Mention trade-offs
```

---

### SORTING QUESTIONS

**Langkah 1: Analisis Dataset**
```
✓ Berapa elemen?
  - < 50: Bubble OK
  - 50-1000: Merge lebih baik
  - > 1000: Merge wajib
✓ Kondisi data?
  - Mostly sorted: Bubble (early stop)
  - Random: Merge (konsisten)
  - Reverse: Merge (bubble terburuk)
✓ Memory constraints?
  - Terbatas: Bubble (O(1))
  - Cukup: Merge (O(n))
```

**Langkah 2: Step-by-Step Sorting**
```
Untuk Bubble Sort:
✓ Tunjukkan setiap pass
✓ Dalam setiap pass, tunjukkan perbandingan
✓ Catat swap/tukar yang terjadi
✓ Hitung total operasi

Untuk Merge Sort:
✓ Tunjukkan pembagian (divide)
✓ Tunjukkan penggabungan (merge)
✓ Tunjukkan array hasil setiap level
✓ Hitung total operasi
```

**Langkah 3: Perbandingan**
```
✓ Tabel: jumlah perbandingan, pertukaran
✓ Kompleksitas: O(n²) vs O(n log n)
✓ Memory: in-place vs O(n) extra
✓ Stability: kedua-duanya stable
```

**Langkah 4: Rekomendasi**
```
✓ Algoritma mana yang dipilih
✓ Mengapa dipilih algoritma itu
✓ Estimasi untuk data lebih besar
✓ Alternatif lain yang mungkin
```

---

## ⚠️ Common Mistakes

### SEARCHING Mistakes

❌ **Mistake 1: Pakai Binary Search untuk data acak**
```
SALAH: 
Data: [15, 7, 42, 3, 89]
Langsung binary search

BENAR:
Cek dulu apakah data terurut
Jika tidak → gunakan linear search
```

❌ **Mistake 2: Hitung steps salah**
```
SALAH:
Binary search pada 1000 elemen = 1000 steps

BENAR:
Binary search pada 1000 elemen ≈ log₂(1000) ≈ 10 steps
```

❌ **Mistake 3: Tidak menghitung semua kasus**
```
SALAH:
"Binary search lebih cepat"

BENAR:
"Binary search O(log n) untuk data terurut
Linear search O(n) untuk data acak
Jika data acak, sort dulu O(n log n) mahal"
```

---

### SORTING Mistakes

❌ **Mistake 1: Bubble Sort untuk data besar**
```
SALAH:
Sorting 10,000 data dengan Bubble Sort (O(n²))

BENAR:
Gunakan Merge Sort, Quick Sort, atau Heap Sort
Bubble hanya untuk < 50 data
```

❌ **Mistake 2: Lupa early termination**
```
SALAH:
Bubble sort selalu n-1 pass

BENAR:
Jika tidak ada swap → data sudah terurut
Hentikan lebih awal
```

❌ **Mistake 3: Hitung operasi salah**
```
SALAH:
Bubble sort pada 100 elemen = 100 + 100 + ... = ?
(kehilangan)

BENAR:
Bubble sort: n(n-1)/2 = 100×99/2 ≈ 5000 operasi
Merge sort: n log n ≈ 100 × log₂(100) ≈ 660 operasi
```

---

## 🎯 Practice Problems

### Problem Set 1: Linear Search

**1.1** Search untuk 25 dalam [10, 25, 35, 50]
- Jawaban: Index 1, 2 perbandingan

**1.2** Search untuk 100 dalam [5, 15, 25, 35, 45]
- Jawaban: Tidak ditemukan, 5 perbandingan (worst case)

**1.3** Berapa worst case steps untuk 1 juta data?
- Jawaban: 1,000,000 perbandingan

---

### Problem Set 2: Binary Search

**2.1** Search untuk 52 dalam [5, 12, 18, 23, 35, 41, 48, 52, 67, 78, 89, 95]
- Jawaban: Index 7, 4 steps (sudah di soal variasi 1)

**2.2** Berapa steps untuk mencari dalam 1 juta data terurut?
- Jawaban: log₂(1,000,000) ≈ 20 steps

**2.3** Jika data 100 elemen, paling banyak berapa steps?
- Jawaban: log₂(100) ≈ 7 steps (worst case)

---

### Problem Set 3: Bubble Sort

**3.1** Sort [3, 1, 4, 1, 5] dengan Bubble Sort, catat setiap pass

**3.2** Berapa total perbandingan untuk 10 elemen?
- Jawaban: 9+8+7+6+5+4+3+2+1 = 45 perbandingan

**3.3** Jika data sudah sorted, berapa passes dengan early stop?
- Jawaban: 1 pass (no swaps → stop)

---

### Problem Set 4: Merge Sort

**4.1** Sort [38, 27, 43, 3, 9, 82, 10] dengan Merge Sort, tunjukkan divide & merge

**4.2** Berapa level pembagian untuk 1000 elemen?
- Jawaban: log₂(1000) ≈ 10 levels

**4.3** Berapa memory yang digunakan (space complexity)?
- Jawaban: O(n) = 1000 elemen tambahan untuk merge

---

## ✅ Answer Key

Lihat file `SOLUTION_SEARCHING_SORTING.txt` untuk jawaban lengkap dengan penjelasan detail.

---

<div align="center">

### 📚 Good Luck with Your Exam!

**Last Updated:** January 12, 2026

</div>
