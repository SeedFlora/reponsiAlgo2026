# 📊 ANALISIS LENGKAP SEMUA PROGRAM

> **Dokumentasi Komprehensif: Searching, Sorting, dan Program Praktis Lainnya**

---

## 📑 Daftar Isi
1. [Overview Semua Program](#overview-semua-program)
2. [Searching Programs](#searching-programs)
3. [Sorting Programs](#sorting-programs)
4. [Practical Programs](#practical-programs)
5. [Perbandingan & Rekomendasi](#perbandingan--rekomendasi)
6. [Kompleksitas Analysis](#kompleksitas-analysis)

---

## 🎯 Overview Semua Program

Workspace ini terdiri dari **5 program C** dengan berbagai topik algoritma:

| # | Program | File | Topik | Kompleksitas | Status |
|---|---------|------|-------|---|---|
| 1 | Linear Search | `searching_soal_variasi.c` | Searching | O(n) | ✅ |
| 2 | Binary Search | `searching_soal_variasi.c` | Searching | O(log n) | ✅ |
| 3 | Bubble Sort | `sorting_soal_variasi.c` | Sorting | O(n²) | ✅ |
| 4 | Merge Sort | `sorting_soal_variasi.c` | Sorting | O(n log n) | ✅ |
| 5 | Richest Customer | `richest_customer.c` | Array 2D | O(m×n) | ✅ |
| 6 | Stock Profit | `stock_profit.c` | File I/O | O(n) | ✅ |
| 7 | Login System | `username_password.c` | String | O(n) | ✅ |

---

## 🔍 SEARCHING PROGRAMS

### Program 1: Linear Search
**File:** `searching_soal_variasi.c`

#### Deskripsi
Program yang mengimplementasikan Linear Search untuk mencari elemen dalam array.

#### Konsep Algoritma
```
LINEAR SEARCH
├─ Iterasi dari index 0 sampai n-1
├─ Bandingkan setiap elemen dengan target
├─ Jika sama → return index
└─ Jika tidak ada → return -1
```

#### Karakteristik
| Aspek | Nilai |
|-------|-------|
| **Kompleksitas Waktu - Best Case** | O(1) |
| **Kompleksitas Waktu - Average Case** | O(n/2) |
| **Kompleksitas Waktu - Worst Case** | O(n) |
| **Kompleksitas Ruang** | O(1) |
| **Stabil** | Ya |
| **Syarat Data** | Boleh acak atau terurut |

#### Pseudocode
```
function linearSearch(arr, target):
    for i = 0 to length(arr) - 1:
        if arr[i] == target:
            return i
    return -1
```

#### Contoh Eksekusi

**Input:**
```
Data: [5, 12, 18, 23, 35, 41, 48, 52, 67, 78, 89, 95]
Target: 52
```

**Step-by-Step:**
```
Step 1: arr[0] = 5  ≠ 52
Step 2: arr[1] = 12 ≠ 52
Step 3: arr[2] = 18 ≠ 52
Step 4: arr[3] = 23 ≠ 52
Step 5: arr[4] = 35 ≠ 52
Step 6: arr[5] = 41 ≠ 52
Step 7: arr[6] = 48 ≠ 52
Step 8: arr[7] = 52 = 52 ✓ FOUND!

Total Comparisons: 8
```

#### Kapan Gunakan
- ✅ Data tidak terurut
- ✅ Jumlah data kecil (< 100)
- ✅ Hanya dicari sekali
- ✅ Memory sangat terbatas

#### Kapan TIDAK Gunakan
- ❌ Data terurut (gunakan binary search)
- ❌ Data besar & dicari berkali-kali
- ❌ Performa time-critical

---

### Program 2: Binary Search
**File:** `searching_soal_variasi.c`

#### Deskripsi
Program yang mengimplementasikan Binary Search untuk mencari elemen dalam array terurut.

#### Konsep Algoritma
```
BINARY SEARCH (Divide & Conquer)
├─ Tentukan left = 0, right = n-1
├─ Hitung mid = (left + right) / 2
├─ Bandingkan arr[mid] dengan target:
│  ├─ Jika sama → return mid
│  ├─ Jika arr[mid] < target → left = mid + 1
│  └─ Jika arr[mid] > target → right = mid - 1
└─ Ulangi sampai left > right
```

#### Karakteristik
| Aspek | Nilai |
|-------|-------|
| **Kompleksitas Waktu - Best Case** | O(1) |
| **Kompleksitas Waktu - Average Case** | O(log n) |
| **Kompleksitas Waktu - Worst Case** | O(log n) |
| **Kompleksitas Ruang** | O(1) iterative |
| **Stabil** | Ya |
| **Syarat Data** | HARUS terurut! |

#### Pseudocode
```
function binarySearch(arr, target):
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

#### Contoh Eksekusi

**Input:**
```
Data: [5, 12, 18, 23, 35, 41, 48, 52, 67, 78, 89, 95]
Target: 52
```

**Step-by-Step:**
```
Iterasi 1:
  left=0, right=11
  mid = (0+11)/2 = 5
  arr[5] = 41 < 52 → left = 6

Iterasi 2:
  left=6, right=11
  mid = (6+11)/2 = 8
  arr[8] = 67 > 52 → right = 7

Iterasi 3:
  left=6, right=7
  mid = (6+7)/2 = 6
  arr[6] = 48 < 52 → left = 7

Iterasi 4:
  left=7, right=7
  mid = (7+7)/2 = 7
  arr[7] = 52 = 52 ✓ FOUND!

Total Comparisons: 4
```

#### Perbandingan Binary vs Linear

```
Dataset Size    Linear    Binary    Improvement
──────────────────────────────────────────────
10              10        4         2.5x
100             100       7         14x
1,000           1,000     10        100x
10,000          10,000    14        714x
1,000,000       1,000,000 20        50,000x !!!
```

#### Kapan Gunakan
- ✅ Data TERURUT (requirement!)
- ✅ Data besar (> 100)
- ✅ Dicari berkali-kali
- ✅ Performa penting

#### Kapan TIDAK Gunakan
- ❌ Data tidak terurut
- ❌ Data linked list (no O(1) access)
- ❌ Data sedikit & hanya cari sekali

---

## ↕️ SORTING PROGRAMS

### Program 3: Bubble Sort
**File:** `sorting_soal_variasi.c`

#### Deskripsi
Program yang mengimplementasikan Bubble Sort - algoritma sorting sederhana yang membandingkan elemen bersebelahan.

#### Konsep Algoritma
```
BUBBLE SORT
├─ Outer loop: Setiap pass (n-1 pass)
│  └─ Inner loop: Bandingkan elemen bersebelahan
│     ├─ Jika arr[j] > arr[j+1] → TUKAR
│     └─ Elemen terbesar "menggelembung" ke akhir
└─ Optimasi: Early stop jika tidak ada tukar
```

#### Karakteristik
| Aspek | Nilai |
|-------|-------|
| **Kompleksitas Waktu - Best Case** | O(n) with early stop |
| **Kompleksitas Waktu - Average Case** | O(n²) |
| **Kompleksitas Waktu - Worst Case** | O(n²) |
| **Kompleksitas Ruang** | O(1) in-place |
| **Stabil** | Ya |
| **Adaptive** | Ya |

#### Pseudocode
```
function bubbleSort(arr):
    n = length(arr)
    
    for i = 0 to n-2:
        swapped = false
        
        for j = 0 to n-i-2:
            if arr[j] > arr[j+1]:
                swap(arr[j], arr[j+1])
                swapped = true
        
        if not swapped:
            break  // Early termination
```

#### Contoh Eksekusi

**Input:**
```
Data: [42, 17, 93, 25, 68, 31, 56]
```

**Pass-by-Pass:**
```
PASS 1: (Compare 6x, Swap 3x)
  [42,17] → [17,42]
  [42,93] → OK
  [93,25] → [25,93]
  [93,68] → [68,93]
  [93,31] → [31,93]
  [93,56] → [56,93]
  Result: [17, 42, 25, 68, 31, 56, 93]

PASS 2: (Compare 5x, Swap 2x)
  [17,42] → OK
  [42,25] → [25,42]
  [42,68] → OK
  [68,31] → [31,68]
  [68,56] → [56,68]
  Result: [17, 25, 42, 31, 56, 68, 93]

PASS 3: (Compare 4x, Swap 1x)
  [17,25] → OK
  [25,42] → OK
  [42,31] → [31,42]
  [42,56] → OK
  Result: [17, 25, 31, 42, 56, 68, 93]

PASS 4: (Compare 3x, Swap 0x)
  [17,25] → OK
  [25,31] → OK
  [31,42] → OK
  Result: [17, 25, 31, 42, 56, 68, 93] ✓ SORTED!
```

**Total Operasi: 18 perbandingan, 6 pertukaran**

#### Kapan Gunakan
- ✅ Data sangat kecil (< 50)
- ✅ Pembelajaran algoritma
- ✅ Memory sangat terbatas
- ✅ Deteksi data sudah sorted

#### Kapan TIDAK Gunakan
- ❌ Data besar (O(n²) lambat)
- ❌ Production code
- ❌ Real-time systems

---

### Program 4: Merge Sort
**File:** `sorting_soal_variasi.c`

#### Deskripsi
Program yang mengimplementasikan Merge Sort - algoritma divide & conquer yang menghasilkan O(n log n) konsisten.

#### Konsep Algoritma
```
MERGE SORT (Divide & Conquer)
├─ DIVIDE: Bagi array menjadi 2 bagian sampai unit tunggal
├─ CONQUER: Urutkan setiap bagian
└─ MERGE: Gabungkan 2 bagian terurut menjadi 1 bagian terurut
```

#### Karakteristik
| Aspek | Nilai |
|-------|-------|
| **Kompleksitas Waktu - Best Case** | O(n log n) |
| **Kompleksitas Waktu - Average Case** | O(n log n) |
| **Kompleksitas Waktu - Worst Case** | O(n log n) CONSISTENT |
| **Kompleksitas Ruang** | O(n) temporary arrays |
| **Stabil** | Ya |
| **Adaptive** | Tidak |

#### Pseudocode
```
function mergeSort(arr, left, right):
    if left < right:
        mid = (left + right) / 2
        mergeSort(arr, left, mid)           // Urutkan kiri
        mergeSort(arr, mid+1, right)        // Urutkan kanan
        merge(arr, left, mid, right)        // Gabung

function merge(arr, left, mid, right):
    // Gabungkan arr[left...mid] dan arr[mid+1...right]
    // Dengan memastikan urutan ascending
```

#### Contoh Eksekusi

**Input:**
```
Data: [42, 17, 93, 25, 68, 31, 56]
```

**DIVIDE Phase:**
```
Level 0: [42, 17, 93, 25, 68, 31, 56]
Level 1: [42, 17, 93, 25] | [68, 31, 56]
Level 2: [42, 17] | [93, 25] | [68, 31] | [56]
Level 3: [42] | [17] | [93] | [25] | [68] | [31] | [56]
```

**MERGE Phase:**
```
Merge [42] + [17] → [17, 42]
Merge [93] + [25] → [25, 93]
Merge [68] + [31] → [31, 68]

Merge [17,42] + [25,93] → [17, 25, 42, 93]
Merge [31,68] + [56] → [31, 56, 68]

Merge [17,25,42,93] + [31,56,68] → [17, 25, 31, 42, 56, 68, 93] ✓
```

**Total Operasi: ~14 perbandingan, 6 pembagian**

#### Perbandingan Bubble vs Merge

```
Elemen    Bubble    Merge     Ratio
─────────────────────────────────
7         18        14        1.3x
10        45        25        1.8x
100       5,000     700       7x
1,000     500,000   10,000    50x
10,000    50,000,000 130,000   385x !!!
```

#### Kapan Gunakan
- ✅ Data besar (> 100)
- ✅ Performa penting
- ✅ Worst case guarantee penting
- ✅ Linked lists

#### Kapan TIDAK Gunakan
- ❌ Data sangat kecil (overhead divide)
- ❌ Memory sangat terbatas (O(n) space)
- ❌ Cache efficiency penting

---

## 💼 PRACTICAL PROGRAMS

### Program 5: Richest Customer Wealth
**File:** `richest_customer.c`
**Sumber:** LeetCode Problem 1672

#### Deskripsi
Program untuk menemukan kekayaan maksimal di antara semua pelanggan yang memiliki akun di beberapa bank.

#### Konsep Algoritma
```
RICHEST CUSTOMER
├─ Input: Array 2D (customers × banks)
├─ Setiap cell = uang di bank tertentu
├─ Proses:
│  ├─ Loop setiap customer
│  └─ Jumlahkan uang di semua bank
├─ Output: Kekayaan maksimal
└─ Algoritma: Brute force iteration
```

#### Pseudocode
```
function maximumWealth(accounts, n, banks):
    maxWealth = 0
    
    for i = 0 to n-1:          // Setiap customer
        currentWealth = 0
        
        for j = 0 to banks-1:  // Setiap bank
            currentWealth += accounts[i][j]
        
        if currentWealth > maxWealth:
            maxWealth = currentWealth
    
    return maxWealth
```

#### Kompleksitas
| Metrik | Nilai |
|--------|-------|
| **Waktu** | O(m × n) |
| **Ruang** | O(1) |
| **m** | Jumlah customers |
| **n** | Jumlah banks |

#### Contoh Kasus

**Test Case 1:**
```
Input: accounts = [[1,2,3], [3,2,1]]

Proses:
  Customer 1: 1 + 2 + 3 = 6
  Customer 2: 3 + 2 + 1 = 6
  
Output: 6
```

**Test Case 2:**
```
Input: accounts = [[1,5], [7,3], [3,5]]

Proses:
  Customer 1: 1 + 5 = 6
  Customer 2: 7 + 3 = 10
  Customer 3: 3 + 5 = 8
  
Output: 10 (Customer 2 paling kaya)
```

**Test Case 3:**
```
Input: accounts = [[2,8,7], [7,1,3], [1,9,5]]

Proses:
  Customer 1: 2 + 8 + 7 = 17
  Customer 2: 7 + 1 + 3 = 11
  Customer 3: 1 + 9 + 5 = 15
  
Output: 17 (Customer 1 paling kaya)
```

#### Analisis
- **Algoritma:** Brute Force (Simple Iteration)
- **Efisiensi:** Optimal (harus visit semua cell)
- **Use Case:** Permasalahan sederhana 2D array
- **Key Insight:** Maksimal jumlah baris dan kolom

---

### Program 6: Stock Profit Maximization
**File:** `stock_profit.c`

#### Deskripsi
Program untuk mencari profit maksimal dengan membeli & menjual saham sekali. Membaca data dari file, proses, dan output ke file.

#### Konsep Algoritma
```
STOCK PROFIT (Single Pass Strategy)
├─ Input: Harga saham setiap hari (dari file)
├─ Strategi:
│  ├─ Track minimum price seen so far
│  ├─ Untuk setiap hari: hitung profit jika jual
│  ├─ Track profit maksimal
│  └─ Track buy & sell day untuk profit maksimal
└─ Output: Profit maksimal & strategi (ke file)
```

#### Pseudocode
```
function maxProfit(prices):
    if length(prices) < 2:
        return 0
    
    minPrice = prices[0]
    maxProfit = 0
    buyDay = 0, sellDay = 0
    
    for i = 1 to length(prices)-1:
        profit = prices[i] - minPrice
        
        if profit > maxProfit:
            maxProfit = profit
            buyDay = day when minPrice occurred
            sellDay = i
        
        if prices[i] < minPrice:
            minPrice = prices[i]
            update buyDay
    
    return {maxProfit, buyDay, sellDay}
```

#### Kompleksitas
| Metrik | Nilai |
|--------|-------|
| **Waktu** | O(n) |
| **Ruang** | O(1) |
| **n** | Jumlah hari |

#### Contoh Kasus

**Input File (data.txt):**
```
7
7 1 5 3 6 4 9
```

**Proses:**
```
Hari 1: Harga = 7 (minimum)
Hari 2: Harga = 1 (baru minimum), profit = 1-7 = -6 (rugi)
Hari 3: Harga = 5, profit = 5-1 = 4
Hari 4: Harga = 3, profit = 3-1 = 2
Hari 5: Harga = 6, profit = 6-1 = 5 ✓ (profit terbesar sekarang)
Hari 6: Harga = 4, profit = 4-1 = 3
Hari 7: Harga = 9, profit = 9-1 = 8 ✓ (profit maksimal!)

Result:
  Beli  pada Hari 2 (Harga 1)
  Jual  pada Hari 7 (Harga 9)
  Profit: 8
```

**Output File (summary.txt):**
```
=== ANALISIS SAHAM ===

Total hari         : 7
Harga terendah     : 1 (Hari 2)
Keuntungan maksimal: 8

Strategi terbaik:
- Beli  pada hari 2 dengan harga 1
- Jual  pada hari 7 dengan harga 9
- Keuntungan: 8
```

#### Fitur Spesial
- ✅ File I/O (baca & tulis file)
- ✅ Struct untuk data organization
- ✅ Single pass algorithm (efficient)
- ✅ Edge case handling (no profit)

#### Optimasi
Algoritma ini **OPTIMAL** karena:
- Hanya 1 pass (O(n))
- Space O(1) - no extra array
- Tidak perlu sort atau nested loop

---

### Program 7: Login System with Username & Password
**File:** `username_password.c`

#### Deskripsi
Program sistem login sederhana yang memvalidasi username dan password dengan string comparison.

#### Konsep Algoritma
```
LOGIN SYSTEM
├─ Stored: Username & Password (hardcoded)
├─ Input: Username & Password dari user
├─ Validasi:
│  ├─ strcmp(username, input_username) == 0 ?
│  └─ strcmp(password, input_password) == 0 ?
├─ Jika keduanya sama → LOGIN BERHASIL
└─ Jika berbeda → LOGIN GAGAL
```

#### String Comparison Details
```
strcmp() Function:
├─ Return 0 jika string SAMA
├─ Return < 0 jika string1 < string2
└─ Return > 0 jika string1 > string2

Contoh:
  strcmp("A", "A")       → 0  (SAMA) ✓
  strcmp("A", "B")       → -1 (A < B)
  strcmp("B", "A")       → 1  (B > A)
  strcmp("Hello", "Hello") → 0 (SAMA) ✓
```

#### Pseudocode
```
function validateLogin():
    stored_user = "CodeCrucks"
    stored_pass = "cc@123"
    
    INPUT: user_input, pass_input
    
    if strcmp(stored_user, user_input) == 0 AND
       strcmp(stored_pass, pass_input) == 0:
        PRINT "LOGIN SUCCESSFUL"
    else:
        PRINT "LOGIN FAILED"
```

#### Kompleksitas
| Metrik | Nilai |
|--------|-------|
| **Waktu** | O(n) |
| **Ruang** | O(1) |
| **n** | Panjang string |

#### Contoh Kasus

**Test Case 1 (Berhasil):**
```
Input:
  Username: CodeCrucks
  Password: cc@123

Proses:
  strcmp("CodeCrucks", "CodeCrucks") → 0 ✓
  strcmp("cc@123", "cc@123") → 0 ✓
  
Output: ✓ LOGIN SUCCESSFUL!
         Welcome, CodeCrucks!
```

**Test Case 2 (Gagal - Username Salah):**
```
Input:
  Username: UserName
  Password: cc@123

Proses:
  strcmp("CodeCrucks", "UserName") → non-zero ✗
  
Output: ✗ LOGIN FAILED!
         Invalid username or password.
```

**Test Case 3 (Gagal - Password Salah):**
```
Input:
  Username: CodeCrucks
  Password: wrongpass

Proses:
  strcmp("CodeCrucks", "CodeCrucks") → 0 ✓
  strcmp("cc@123", "wrongpass") → non-zero ✗
  
Output: ✗ LOGIN FAILED!
         Invalid username or password.
```

#### Features
- ✅ String input dengan `fgets()`
- ✅ Newline removal dengan `strcspn()`
- ✅ String comparison dengan `strcmp()`
- ✅ Logical AND untuk validasi ganda

#### Keamanan (DISCLAIMER)
⚠️ **Program ini BUKAN untuk production!**
- Password hardcoded di source (insecure)
- Tidak ada encryption
- Input tidak divalidasi
- Tidak ada rate limiting
- **Gunakan library keamanan untuk sistem real**

---

## 📊 PERBANDINGAN & REKOMENDASI

### Comparison Table

```
┌──────────────────┬──────────────┬──────────────┬─────────────────┐
│ Program          │ Kompleksitas │ Use Case     │ Priority Belajar │
├──────────────────┼──────────────┼──────────────┼─────────────────┤
│ Linear Search    │ O(n)         │ Data acak    │ ⭐⭐⭐⭐⭐ HIGH   │
│ Binary Search    │ O(log n)     │ Data terurut │ ⭐⭐⭐⭐⭐ HIGH   │
│ Bubble Sort      │ O(n²)        │ Data kecil   │ ⭐⭐⭐⭐  MED    │
│ Merge Sort       │ O(n log n)   │ Data besar   │ ⭐⭐⭐⭐  MED    │
│ Richest Customer │ O(m×n)       │ 2D array     │ ⭐⭐⭐   LOW    │
│ Stock Profit     │ O(n)         │ File I/O     │ ⭐⭐⭐   LOW    │
│ Login System     │ O(n)         │ String comp  │ ⭐⭐⭐   LOW    │
└──────────────────┴──────────────┴──────────────┴─────────────────┘
```

### Program Mana yang Paling Penting?

**Untuk Ujian Algoritma:**
1. ⭐⭐⭐⭐⭐ **LINEAR & BINARY SEARCH** - Fundamental
2. ⭐⭐⭐⭐⭐ **BUBBLE & MERGE SORT** - Fundamental
3. ⭐⭐⭐ **Richest Customer** - Array 2D basics
4. ⭐⭐⭐ **Stock Profit** - File I/O + optimization
5. ⭐⭐⭐ **Login System** - String handling

**Untuk Developer Practical:**
1. ⭐⭐⭐⭐⭐ **Stock Profit** - Real-world optimization
2. ⭐⭐⭐⭐ **Binary Search** - Database indexing
3. ⭐⭐⭐⭐ **Merge Sort** - Large dataset handling
4. ⭐⭐⭐ **Richest Customer** - 2D data structure
5. ⭐⭐ **Login System** - Basic string handling

---

## 🔬 KOMPLEKSITAS ANALYSIS

### Time Complexity Comparison

```
Best Case Scenario (Ideal Conditions):
┌─────────────────┬─────────────┐
│ Algorithm       │ Complexity  │
├─────────────────┼─────────────┤
│ Linear Search   │ O(1)        │
│ Binary Search   │ O(1)        │
│ Bubble Sort     │ O(n)*       │
│ Merge Sort      │ O(n log n)  │
└─────────────────┴─────────────┘
* With early termination

Average Case (Normal Conditions):
┌─────────────────┬─────────────┐
│ Algorithm       │ Complexity  │
├─────────────────┼─────────────┤
│ Linear Search   │ O(n/2)      │
│ Binary Search   │ O(log n)    │
│ Bubble Sort     │ O(n²)       │
│ Merge Sort      │ O(n log n)  │
└─────────────────┴─────────────┘

Worst Case (Unfavorable Conditions):
┌─────────────────┬─────────────┐
│ Algorithm       │ Complexity  │
├─────────────────┼─────────────┤
│ Linear Search   │ O(n)        │
│ Binary Search   │ O(log n)    │
│ Bubble Sort     │ O(n²)       │
│ Merge Sort      │ O(n log n)  │
└─────────────────┴─────────────┘
```

### Space Complexity Comparison

```
┌──────────────────┬─────────────┬─────────────────────┐
│ Algorithm        │ Space       │ Tipe                │
├──────────────────┼─────────────┼─────────────────────┤
│ Linear Search    │ O(1)        │ In-place            │
│ Binary Search    │ O(1)        │ In-place            │
│ Bubble Sort      │ O(1)        │ In-place (no extra) │
│ Merge Sort       │ O(n)        │ Out-of-place        │
│ Richest Customer │ O(1)        │ In-place            │
│ Stock Profit     │ O(1)        │ In-place            │
│ Login System     │ O(n)        │ Input string storage│
└──────────────────┴─────────────┴─────────────────────┘
```

### Growth Rate Visualization

```
Untuk 1000 Elemen:

O(1)      : 1 operation
O(log n)  : ~10 operations (very fast!)
O(n)      : 1,000 operations
O(n log n): ~10,000 operations
O(n²)     : 1,000,000 operations (very slow!)

Perbandingan:
Binary Search vs Linear Search (1 juta data):
  Binary: ~20 operations
  Linear: ~500,000 operations average
  ➜ Binary 25,000x LEBIH CEPAT!

Merge Sort vs Bubble Sort (1000 data):
  Merge:  ~10,000 operations
  Bubble: ~500,000 operations
  ➜ Merge 50x LEBIH CEPAT!
```

---

## 📝 TIPS MENGANALISIS PROGRAM

### Checklist untuk Setiap Program

```
1. PAHAMI INPUT & OUTPUT
   ✓ Apa format input?
   ✓ Apa format output?
   ✓ Ada constraint apa?

2. IDENTIFIKASI ALGORITMA
   ✓ Algoritma apa yang digunakan?
   ✓ Apakah ada metode khusus (DFS, BFS, DP)?
   ✓ Apakah ada optimasi?

3. HITUNG KOMPLEKSITAS
   ✓ Best case: O(?)
   ✓ Average case: O(?)
   ✓ Worst case: O(?)
   ✓ Space: O(?)

4. TRACE EKSEKUSI
   ✓ Jalankan dengan input kecil
   ✓ Catat setiap step
   ✓ Verifikasi output

5. BUAT IMPROVEMENT
   ✓ Ada cara lebih cepat?
   ✓ Ada cara hemat memory?
   ✓ Ada edge case?
```

---

<div align="center">

## 🎓 KESIMPULAN

Repository ini berisi **7 program berbeda** yang mencakup:
- ✅ Fundamental Algorithms (Searching & Sorting)
- ✅ Array Operations (2D arrays)
- ✅ File I/O & Data Processing
- ✅ String Handling

**Semua program siap untuk belajar, referensi, dan ujian!**

---

Last Updated: January 12, 2026
Quality: ⭐⭐⭐⭐⭐ COMPREHENSIVE

</div>
