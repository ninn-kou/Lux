// Hao Ren
// 29 April, 2021
// 1528. Shuffle String

// If the function free() needs to be called?
char *restoreString(char *s, int *indices, int indicesSize) {
    /*
    Malloc a string called "new" which has the same size as the given one,
    and we could copy each char from "s" to "new" by the correct order.
    The size should be (indicesSize + 1), Because the string "s" should be
    ['c','o','d','e','l','e','e','t','\0'].
    */
    char *new = malloc((indicesSize + 1) * sizeof(char));
    for (int i = 0; i < indicesSize; i++) {
        /*
        Same as the one-line code below.
        int index = indices[i];
        new[index] = s[i];
        */
        new[indices[i]] = s[i];
    }
    // And string should end with a '\0'.
    new[indicesSize] = '\0';
    return new;
}
