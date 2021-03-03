// MATH1231 Week 8
// Online Tutorials
// T6Q3

#include <stdio.h>
#include <math.h>
#include <stdint.h>

__int128_t recursion(int n, __int128_t *map) {
    if (n == 1) {
        return 4;
    } else if (n == 2) {
        return 1;
    } else if (n == 3) {
        return -1;
    } else if (map[n] != 0) {
        return map[n];
    } else {
        map[n] = recursion(n - 1, map) - 4 * recursion(n - 2, map) + recursion(n - 3, map);
        return map[n];
    }
}

int print_int128(__int128_t n) {
  if (n == 0)  return printf("0\n");
  char str[40] = {0}; // log10(1 << 128) + '\0'
  char *s = str + sizeof(str) - 1; // start at the end
  while (n != 0) {
    if (s == str) return -1; // never happens

    *--s = "0123456789"[n % 10]; // save last digit
    n /= 10;                     // drop it
  }
  return printf("%s\n", s);
}

int main(void) {
    __int128_t map[150] = {0};
    printf("Input the value n for a(n).\n");
    int input;
    scanf("%d", &input);
    int value = input - 1;
    print_int128(recursion(value + 1, map));
    return 0;
}
