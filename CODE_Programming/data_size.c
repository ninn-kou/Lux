// Hao Ren
//28 June, 2020

#include <stdio.h>

int main(void) {
    short s;
    char c;
    int i;
    long l;
    long long ll;
    float f;
    double d;

    printf("short     %lu bytes\n", sizeof(s));
    printf("char      %lu bytes\n", sizeof(c));
    printf("int       %lu bytes\n", sizeof(i));
    printf("long      %lu bytes\n", sizeof(l));
    printf("long long %lu bytes\n", sizeof(ll));
    printf("float     %lu bytes\n", sizeof(f));
    printf("double    %lu bytes\n", sizeof(d));
    return 0;
}