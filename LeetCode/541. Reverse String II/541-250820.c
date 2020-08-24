// Hao Ren
// 25 August, 2020
// 541. Reverse String II

void reverseString(char *s, int head, int tail) {
    while (head < tail) {
        // Swapping two characters.
        int temp = s[head];
        s[head] = s[tail];
        s[tail] = temp;
        head++;
        tail--;
    }
}

char *reverseStr(char *s, int k) {
    // See the diagram for help.
    int groups = strlen(s) / (2 * k);
    int n = 0;
    // Reverse substrings until the remainder less than 2k;
    while (n < groups) {
        reverseString(s, 2 * k * n, 2 * k * n + k - 1);
        n++;
    }
    // k > remainder;
    if (strlen(s) % (2 * k) < k) {
        reverseString(s, 2 * k * n, strlen(s) - 1);
    // 2k > remainder > k.
    } else {
        reverseString(s, 2 * k * n, 2 * k * n + k - 1);
    }
    return s;
}
