// COMP2521 Quiz 8 Question 2
//
// How many times would the (T[i+j] != P[j]) test be done in executing the following call to the above function?

#include <stdio.h>
#include <string.h>

int naiveStringMatch(char *t, char *p);

int counter = 0;

int main(void) {
    int where = naiveStringMatch("my string","tri");
    printf("The value of \"int where\" is %d.\n", where);
    printf("However, the test executed %d times.\n", counter);
    return 0;
}

int naiveStringMatch(char *t, char *p) {

    int i, j;           // indices into t and p
    int n = strlen(t);  // length of string
    int m = strlen(p);  // length of pattern
    printf("Length of first string: %d\n", n);
    printf("Length of second string: %d\n", m);

    for (i = 0; i <= n-m; i++) {
        for (j = 0; j < m; j++) {
            counter++;
            if (t[i+j] != p[j]) break;
        }
        if (j == m) return i; // index of match
    }
    return -1;  // no match
}
