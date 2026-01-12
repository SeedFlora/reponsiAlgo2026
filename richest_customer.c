#include <stdio.h>
#include <stdlib.h>

/**
 * Fungsi untuk menemukan kekayaan maksimal di antara semua pelanggan
 * accounts: array 2D yang merepresentasikan uang di setiap bank untuk setiap pelanggan
 * accountsSize: jumlah pelanggan
 * accountsColSize: jumlah bank (kolom)
 */
int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int maxWealth = 0;
    
    // Iterate melalui setiap pelanggan
    for (int i = 0; i < accountsSize; i++) {
        int currentWealth = 0;
        
        // Jumlahkan uang di semua bank untuk pelanggan ke-i
        for (int j = 0; j < accountsColSize[i]; j++) {
            currentWealth += accounts[i][j];
        }
        
        // Update maxWealth jika kekayaan saat ini lebih besar
        if (currentWealth > maxWealth) {
            maxWealth = currentWealth;
        }
    }
    
    return maxWealth;
}

int main() {
    printf("===== Richest Customer Wealth (LeetCode 1672) =====\n\n");
    
    // Test Case 1
    printf("Test Case 1:\n");
    int accounts1[2][3] = {{1, 2, 3}, {3, 2, 1}};
    int *ptr1[2];
    ptr1[0] = accounts1[0];
    ptr1[1] = accounts1[1];
    int colSize1[2] = {3, 3};
    
    int result1 = maximumWealth((int**)ptr1, 2, colSize1);
    printf("Input: accounts = [[1,2,3],[3,2,1]]\n");
    printf("Output: %d\n", result1);
    printf("Explanation:\n");
    printf("  1st customer has wealth = 1 + 2 + 3 = 6\n");
    printf("  2nd customer has wealth = 3 + 2 + 1 = 6\n");
    printf("  Both customers are considered the richest with a wealth of 6\n\n");
    
    // Test Case 2
    printf("Test Case 2:\n");
    int accounts2[3][2] = {{1, 5}, {7, 3}, {3, 5}};
    int *ptr2[3];
    ptr2[0] = accounts2[0];
    ptr2[1] = accounts2[1];
    ptr2[2] = accounts2[2];
    int colSize2[3] = {2, 2, 2};
    
    int result2 = maximumWealth((int**)ptr2, 3, colSize2);
    printf("Input: accounts = [[1,5],[7,3],[3,5]]\n");
    printf("Output: %d\n", result2);
    printf("Explanation:\n");
    printf("  1st customer has wealth = 1 + 5 = 6\n");
    printf("  2nd customer has wealth = 7 + 3 = 10\n");
    printf("  3rd customer has wealth = 3 + 5 = 8\n");
    printf("  The 2nd customer is the richest with a wealth of 10\n\n");
    
    // Test Case 3
    printf("Test Case 3:\n");
    int accounts3[3][3] = {{2, 8, 7}, {7, 1, 3}, {1, 9, 5}};
    int *ptr3[3];
    ptr3[0] = accounts3[0];
    ptr3[1] = accounts3[1];
    ptr3[2] = accounts3[2];
    int colSize3[3] = {3, 3, 3};
    
    int result3 = maximumWealth((int**)ptr3, 3, colSize3);
    printf("Input: accounts = [[2,8,7],[7,1,3],[1,9,5]]\n");
    printf("Output: %d\n", result3);
    printf("Explanation:\n");
    printf("  1st customer has wealth = 2 + 8 + 7 = 17\n");
    printf("  2nd customer has wealth = 7 + 1 + 3 = 11\n");
    printf("  3rd customer has wealth = 1 + 9 + 5 = 15\n");
    printf("  The 1st customer is the richest with a wealth of 17\n\n");
    
    return 0;
}
