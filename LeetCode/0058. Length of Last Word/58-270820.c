// Hao Ren
// 27 August, 2020
// 58. Length of Last Word

int lengthOfLastWord(char *s) {
    // First case: the string is empty; no word inside.
    if (*s == NULL) {
        return 0;
    }
    // An index points to the last character in string (not '\0');
    int end = strlen(s) - 1;
    // Then, we move the above index to point at the last "meaningful" character.
    while (s[end] == ' ' && end > 0) {
        end--;
    }
    // From the end index, we move a new index called "start" to the left to
    // find the first "meaningless" character, which should be a space. If it
    // does not exist, which means that there is no space between s[0] and
    // s[end], we should return end + 1, the length of the "last word".
    int start = end;
    while (s[start] != ' ' && start > 0) {
        start--;
    }
    if (s[start] != ' ') {
        return end + 1;
    }
    return end - start;
}
