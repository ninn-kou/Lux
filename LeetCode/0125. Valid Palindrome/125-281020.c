// Hao Ren
// 28 October, 2020
// 125. Valid Palindrome

// isalnum() checks whether the argument is an alphanumeric character or not.
// tolower() convert the argument to a lowercase character.
bool isPalindrome(char *s) {
    int head = 0;
    int tail = strlen(s) - 1;
    while (head < tail) {
        // Check the condition `head < tail` to avoid the runtime error.
        while (head < tail && !isalnum(s[head])) {
            head++;
        }
        // Check the condition `head < tail` to avoid the runtime error.
        while (head < tail && !isalnum(s[tail])) {
            tail--;
        }
        if (tolower(s[head]) != tolower(s[tail])) {
            return false;
        }
        head++;
        tail--;
    }
    return true;
}
