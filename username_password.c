Perbandingan              | Return | Arti
--------------------------|--------|----------
strcmp("A", "A")          | 0      | SAMA ✓
strcmp("A", "B")          | -1     | A < B (A lebih kecil)
strcmp("B", "A")          | 1      | B > A (B lebih besar)
strcmp("Abc", "Abc")      | 0      | SAMA ✓
strcmp("CodeCrucks", ...) | 0      | SAMA ✓#include <stdio.h>
#include <string.h>

int main()
{
    // Username dan password yang benar (disimpan di program)
    char user_name[] = "CodeCrucks";
    char user_password[] = "cc@123";
    
    // Variabel untuk menampung input dari user
    char user_name1[20];
    char user_password1[20];
    
    // Input Username
    printf("====================================\n");
    printf("  Login System - Username & Password\n");
    printf("====================================\n\n");
    printf("Enter Username: ");
    fgets(user_name1, sizeof(user_name1), stdin);
    // Hapus newline character dari fgets
    user_name1[strcspn(user_name1, "\n")] = 0;
    
    // Input Password
    printf("Enter Password: ");
    fgets(user_password1, sizeof(user_password1), stdin);
    // Hapus newline character dari fgets
    user_password1[strcspn(user_password1, "\n")] = 0;
    
    printf("\n");
    
    // Validasi username dan password
    // strcmp() membandingkan dua string
    // Jika sama, return 0 (false), jika berbeda return non-zero (true)
    if ((strcmp(user_name, user_name1) == 0) && (strcmp(user_password, user_password1) == 0))
    {
        printf("✓ LOGIN SUCCESSFUL!\n");
        printf("Welcome, %s!\n", user_name1);
    }
    else
    {
        printf("✗ LOGIN FAILED!\n");
        printf("Invalid username or password.\n");
    }
    
    printf("\n====================================\n");
    
    return 0;
}
