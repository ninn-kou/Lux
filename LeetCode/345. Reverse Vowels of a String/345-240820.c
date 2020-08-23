// Hao Ren
// 24 August, 2020
// 345. Reverse Vowels of a String

// Helper function to determine whether a character is a vowel.
bool isVowel(char ch) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
        return true;
    } else {
        return false;
    }
}

char *reverseVowels(char *s) {
    int head = 0;
    int tail = strlen(s) - 1;
    // Must execute one statement of below three statements.
    while (head < tail) {
        // Find the first vowel which has not been swapped.
        if (!isVowel(s[head])) {
            head++;
        // Find the last vowel which has not been swapped.
        } else if (!isVowel(s[tail])) {
            tail--;
        } else {
            // Swap two elements and increase the index of head & tail.
            int temp = s[head];
            s[head] = s[tail];
            s[tail] = temp;
            head++;
            tail--;
        }
    }
    return s;
}
