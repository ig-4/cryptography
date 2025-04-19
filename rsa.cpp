//RSA ALGORITHM

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Simple power function (for small exponents)
long long power(long long base, long long exp, long long mod) 
{
    long long res = 1;
    base %= mod;
    while (exp > 0) 
	{
        res = (res * base) % mod;
        exp--;
    }
    return res;
}

// Simple GCD function
long long gcd(long long a, long long b) 
{
    while (b) 
	{
        a %= b;
        long long temp = a;
        a = b;
        b = temp;
    }
    return a;
}

// Simple modular inverse (only works for small cases)
long long modInverse(long long a, long long m) 
{
    for (long long x = 1; x < m; x++) 
	{
        if ((a * x) % m == 1) 
			return x;
    }
    return -1;
}

int main() {
    // Choose prime numbers
    long long p = 3;
    long long q = 11;
    long long n = p * q;
    long long phi_n = (p - 1) * (q - 1);
    long long e = 7; // Choose e such that 1 < e < phi_n and gcd(e, phi_n) == 1
    long long d = modInverse(e, phi_n);

    if (d == -1) 
	{
        printf("Modular inverse for d doesn't exist!\n");
        return 1;
    }

    printf("Public key (n, e): (%lld, %lld)\n", n, e);
    printf("Private key (n, d): (%lld, %lld)\n", n, d);

    long long message = 31; // Example message (must be less than n)
    printf("Original message: %lld\n", message);

    // Encryption
    long long ciphertext = power(message, e, n);
    printf("Ciphertext: %lld\n", ciphertext);

    // Decryption
    long long decryptedMessage = power(ciphertext, d, n);
    printf("Decrypted message: %lld\n", decryptedMessage);

    return 0;
}
