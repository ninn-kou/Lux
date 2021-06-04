// Hao Ren
// 27 August, 2020
// 1119. Remove Vowels from a String

// Helper function to determine whether a character is a lower case vowel.
bool isVowel(char ch) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        return true;
    } else {
        return false;
    }
}

char *removeVowels(char *S){
    int len = strlen(S);
    int i,j = 0;
    // Use a buffer array to store the new string.
    // Passing the string one by one, and checking if the character is a vowel.
    // If no, copy it to the new array.
    char noVowel[len];
    while (i < len) {
        if (isVowel(S[i]) != true) {
            noVowel[j] = S[i];
            j++;
        }
        i++;
    }
    // Copy the buffer array into S, and then return S.
    noVowel[j] = '\0';
    strcpy(S, noVowel);
    return S;
}
