// HILL CIPHER

#include <stdio.h>
#define MOD 26

int main() {
    int key[3][3] = { {6, 3, 4}, {5, 2, 3}, {1, 3, 2} };
    int inverseKey[3][3] = { {-5, 6, 1}, {-7, 8, 2}, {13, -15, -3} }; 

    char msg[20];
    int c[3], d[3], i, j;

    printf("Enter plain text (3 letters): ");
    scanf("%s", msg);

    // Convert plaintext characters to numbers
    for (i = 0; i < 3; i++)
        c[i] = msg[i] - 'A';

    // Encryption using matrix multiplication
    for (i = 0; i < 3; i++) 
	{
        d[i] = 0;
        for (j = 0; j < 3; j++)
            d[i] += c[j] * key[i][j] ;
        d[i] %= MOD;
    }

    printf("\nEncrypted Cipher Text: ");
    for (i = 0; i < 3; i++)
        printf("%c", d[i] + 'A');

    // Decryption using the **predefined inverse matrix**
    for (i = 0; i < 3; i++) 
	{
        c[i] = 0;
        for (j = 0; j < 3; j++)
            c[i] +=  d[j] * inverseKey[i][j];
        c[i] = (c[i] % MOD + MOD ) % MOD;
    }

    printf("\nDecrypted Plain Text: ");
    for (i = 0; i < 3; i++)
        printf("%c", c[i] + 'A');

    return 0;
}
