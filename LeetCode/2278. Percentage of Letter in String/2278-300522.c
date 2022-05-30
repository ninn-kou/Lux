// Hao Ren
// 30 May, 2022
// 2278. Percentage of Letter in String

int percentageLetter(char *s, char letter) {
    float counter = 0;
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == letter) {
            counter += 1;
        }
        i++;
    }
    return (100 * counter) / i;
}
