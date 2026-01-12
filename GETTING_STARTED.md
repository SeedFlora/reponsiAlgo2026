# 🎯 Getting Started Guide

> **Mulai Dari Sini - Panduan Cepat 5 Menit**

---

## ⚡ Quick Setup (5 Minutes)

### 1️⃣ Clone Repository

```bash
git clone https://github.com/SeedFlora/reponsiAlgo2026.git
cd reponsiAlgo2026
```

### 2️⃣ Compile Programs

```bash
# Compile Searching Program
gcc searching_soal_variasi.c -o searching.exe

# Compile Sorting Program  
gcc sorting_soal_variasi.c -o sorting.exe
```

### 3️⃣ Run Programs

```bash
# Run Searching
.\searching.exe

# Run Sorting
.\sorting.exe
```

**Output:** Visualisasi step-by-step algorithm dengan perbandingan performa

---

## 📚 Materi untuk Dibaca (Urutan Rekomendasi)

### Jika Punya 10 Menit:
1. ✅ Baca **README.md** - Ringkasan keseluruhan
2. ✅ Jalankan `searching.exe` dan `sorting.exe`
3. ✅ Lihat output dan perhatikan perbedaan steps

### Jika Punya 30 Menit:
1. ✅ Baca **README.md** - Overview
2. ✅ Baca **EXAM_GUIDE.md** - Ringkasan teori
3. ✅ Jalankan kedua program
4. ✅ Baca **README_RINGKASAN.txt** - Quick reference

### Jika Punya 1-2 Jam (Persiapan Ujian Serius):
1. ✅ Baca **README.md** - Pengertian umum
2. ✅ Baca **EXAM_GUIDE.md** - Teori & cheat sheet
3. ✅ Jalankan kedua program berkali-kali
4. ✅ Baca **SOLUTION_SEARCHING_SORTING.txt** - Jawaban lengkap
5. ✅ Pelajari source code `searching_soal_variasi.c` & `sorting_soal_variasi.c`
6. ✅ Kerjakan practice problems di EXAM_GUIDE.md

---

## 🎓 Ringkasan Satu Halaman

### SEARCHING

| Algoritma | Kapan | Kompleksitas | Step Contoh |
|-----------|-------|-------------|------------|
| **Linear** | Data acak | O(n) | 7 steps untuk find 56 |
| **Binary** | Data terurut | O(log n) | 4 steps untuk find 52 |

**Kesimpulan:** Binary 50% lebih cepat untuk data terurut!

---

### SORTING

| Algoritma | Kapan | Kompleksitas | Ops untuk 10 |
|-----------|-------|-------------|------------|
| **Bubble** | Data kecil | O(n²) | ~45 operasi |
| **Merge** | Data besar | O(n log n) | ~25 operasi |

**Kesimpulan:** Merge Sort 44% lebih cepat dan konsisten!

---

## 💡 Instant Insights

### 🔍 Searching - 3 Hal Penting:

```
1️⃣ Data Terurut? → Gunakan BINARY SEARCH
2️⃣ Data Acak? → Gunakan LINEAR SEARCH
3️⃣ Cari Banyak Kali? → SORT dulu, BINARY berulang kali
```

### ↕️ Sorting - 3 Hal Penting:

```
1️⃣ Data < 50 elemen → BUBBLE SORT OK
2️⃣ Data > 100 elemen → Gunakan MERGE SORT
3️⃣ Data 1 juta → Merge 50x lebih cepat!
```

---

## 🏃 Crash Course (10 Minutes)

### Linear Search dalam 2 Menit

```c
// Mulai dari index 0
// Bandingkan satu-satu
// Jika sama → return index
// Jika habis → return -1

for (int i = 0; i < n; i++) {
    if (arr[i] == target) return i;
}
return -1;
```

**Kompleksitas:** O(n) - worst case bandingkan semua

---

### Binary Search dalam 2 Menit

```c
// Cari di tengah
// Jika ketemu → return index
// Jika terlalu kecil → cari kanan
// Jika terlalu besar → cari kiri
// Ulangi

int left = 0, right = n - 1;
while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) left = mid + 1;
    else right = mid - 1;
}
return -1;
```

**Kompleksitas:** O(log n) - eliminasi setengah setiap iterasi

---

### Bubble Sort dalam 2 Menit

```c
// Bandingkan bersebelahan
// Jika salah urutan → tukar
// Ulangi sampai semua di tempat

for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
        }
    }
}
```

**Kompleksitas:** O(n²) - banyak perbandingan

---

### Merge Sort dalam 2 Menit

```c
// Bagi dua sampai unit tunggal
// Urutkan dan gabung sambil naik

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
```

**Kompleksitas:** O(n log n) - divide & conquer power

---

## 🧪 Mini Test Yourself

### Question 1: Searching
```
Diberikan: [5, 12, 18, 23, 35, 41, 48, 52]
Cari: 52
Pakai algoritma apa? Berapa steps?

A) Linear Search, 8 steps
B) Binary Search, 4 steps ✓
C) Linear Search, 4 steps
D) Binary Search, 8 steps
```

### Question 2: Sorting
```
Urutkan [42, 17, 93] dengan Bubble Sort
Pass 1 hasil apa?

A) [17, 42, 93]
B) [17, 42, 93] - tidak, ada 93
C) [17, 42, 93] dengan 2 swaps ✓
```

### Question 3: Complexity
```
Untuk 1 juta data:
Linear Search: berapa steps terburuk?
Binary Search: berapa steps terburuk?

A) 1,000,000 vs 1,000,000
B) 1,000,000 vs 20 ✓
C) 500,000 vs 10
D) 500,000 vs 500,000
```

---

## 📱 Common Questions

### Q: Program compile error?
```bash
# Pastikan GCC terinstall
gcc --version

# Jika tidak ada, download MinGW atau gunakan WSL
```

### Q: Bagaimana cara modify soal?
```c
// Edit main() dan ubah array/target
int arr3[] = {data, baru, di, sini};
int n3 = sizeof(arr3) / sizeof(arr3[0]);
int target3 = 56;

linearSearch(arr3, n3, target3);
binarySearch(arr3, n3, target3);
```

### Q: Output terlalu panjang?
```bash
# Redirect ke file
.\searching.exe > output.txt

# Buka output.txt dengan editor
```

### Q: Mana referensi terlengkap?
```
Untuk teori          → EXAM_GUIDE.md
Untuk jawaban soal   → SOLUTION_SEARCHING_SORTING.txt
Untuk quick lookup   → README_RINGKASAN.txt
Untuk implementasi   → source code (.c files)
```

---

## 🎯 Preparation Timeline

### Jika Ujian Minggu Depan:

```
Hari 1-2:
  • Jalankan program
  • Baca README.md
  • Pahami konsep dasar

Hari 3-4:
  • Baca EXAM_GUIDE.md
  • Pelajari step-by-step di program output
  • Catat rumus kompleksitas

Hari 5:
  • Pelajari source code detail
  • Pahami implementasi algoritma
  • Kerjakan practice problems

Hari 6:
  • Review SOLUTION_SEARCHING_SORTING.txt
  • Latihan menjawab soal
  • Hafal cheat sheet penting

Hari 7 (Hari Ujian):
  • Santai dan percaya diri!
  • Gunakan strategi dari EXAM_GUIDE
```

---

## 🚀 Quick Copy-Paste Answers

### Searching Answer Template

```
Data: [array di sini]
Target: cari ini

Algoritma: [BINARY/LINEAR] Search

Alasan: [jelaskan mengapa]

Step-by-step:
[tunjukkan iterasi demi iterasi]

Total Steps: [hitung]
Kompleksitas: O(?) = [jelaskan]

Kesimpulan: [algoritma mana yang lebih baik dan mengapa]
```

### Sorting Answer Template

```
Data: [array di sini]

Algoritma: [BUBBLE/MERGE] Sort

Alasan: [jelaskan mengapa]

Step-by-step:
[tunjukkan pass/divide/merge demi demi]

Total Operasi: [hitung]
Kompleksitas: O(?) = [jelaskan]

Perbandingan: [tabel atau analisis]

Kesimpulan: [algoritma mana yang lebih baik dan mengapa]
```

---

## ✅ Checklist Sebelum Ujian

- [ ] Paham perbedaan Linear vs Binary Search
- [ ] Paham perbedaan Bubble vs Merge Sort
- [ ] Bisa menghitung Big O complexity
- [ ] Bisa membuat step-by-step trace
- [ ] Bisa membaca & memahami source code C
- [ ] Sudah compile & run kedua program
- [ ] Sudah kerjakan practice problems
- [ ] Sudah hafal rumus penting
- [ ] Yakin dengan strategi menjawab

---

<div align="center">

### 🎓 Ready for Exam?

**You've got this!** 💪

Untuk pertanyaan lebih lanjut, baca file-file lain di repository ini.

**Good Luck!** 🚀

</div>
