// Hao Ren
// 22:45 28 July, 2020

#include <stdio.h>
#include <math.h>

long long fib(int n, long long *map) {
    if (n == 0 || n == 1) {
        return 1;
    } else if (map[n] != 0) {
        return map[n];
    } else {
        return fib(n - 1, map) + fib(n - 2, map);
    }
}

int main(void) {
    long long map[2100] = {0};
    printf("Input the n^{th} number to calclate the fib.\n");
    int n;
    scanf("%d", &n);
    int value = n - 1;
    printf("%lld\n", fib(value, map));
    return 0;
}