// Hao Ren
// 26 August, 2020
// 709. To Lower Case

#define TOLOWER 'a' - 'A'

// Eg: In ASCII table, char 'a' = 97, and char 'A' = 65.
// To converse upper case to lower case, we need to add 32, which is the
// difference between 'a' and 'A'.
// However, for a non-ASCII machine, ('a' - 'A') might not equal to 32.
char *toLowerCase(char *str) {
    int n = 0;
    while (str[n] != '\0') {
        if (str[n] >= 'A' && str[n] <= 'Z') {
            str[n] += TOLOWER;
        }
        n++;
    }
    return str;
}
