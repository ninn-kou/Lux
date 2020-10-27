// Hao Ren
// haoren.2906@gmail.com
// Wednesday, 28 October, 2020

// Binary to Decimal Converter
// Version 1.0 - Single using program.

#include <stdio.h>
#include <string.h>
#include <assert.h>

double myPow(double x, long long n);
char *string_reverse(char *str);

int main(void) {
    char string[1000];
    char ch;
    int bit;
    int dec = 0;
    int j = 0;
    printf ("Binary : ");
    while (scanf("%c", &ch) && ch != '\n') {
        string[j] = ch;
        j++;
    }
    string[j] = '\0';
    string_reverse(string);
    printf("Reverse: %s\n", string);
    for (int i = 0; i < strlen(string); i++) {
        assert(string[i] == '0' || string[i] == '1');
        if (string[i] == '0') bit = 0;
        if (string[i] == '1') bit = 1;
        dec += bit * (int) myPow(2, i);
    }
    printf("Decimal: %d\n", dec);
    return 0;
}

// Codes from my LeetCode No.50.
// The last bit of x in binary must be 1 if x is an odd number, so `x & 1` is
// `1`. Additionally, if x is an even number the bit operating should get a `0`.
double myPow(double x, long long n) {
    if (n < 0) {
        return myPow(1 / x, -n);
    } else if (n == 0.0) {
        return 1.0;
    } else if (n == 1.0) {
        return x;
    // if x is odd:
    } else if (n & 1) {
        return x * myPow(x * x, (n - 1) / 2);
    // if x is even:
    } else {
        return myPow(x * x, n / 2);
    }
}

// Check if the string is NULL.
// Swap by using XOR.
char *string_reverse(char *str) {
    char *p1, *p2;
    if (! str || ! *str)
        return NULL;
    p1 = str;
    p2 = str + strlen(str) - 1;
    while (p1 < p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
        p1++;
        p2--;
    }
    return str;
}
