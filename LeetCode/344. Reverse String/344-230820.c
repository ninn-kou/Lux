// Hao Ren
// 23 August, 2020
// 344. Reverse String

void reverseString(char* s, int sSize){
    int head = 0;
    // The last element of string is '\0'.
    int tail = sSize - 1;
    while (head < tail) {
        // Swapping two characters.
        int temp = s[head];
        s[head] = s[tail];
        s[tail] = temp;
        head++;
        tail--;
    }
}
