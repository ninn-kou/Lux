#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../binary_search.c"

/**
 * @Test
 *
 * To run tests, execute following commands:
 *   $ clang v_test_binary.c -o v_test_binary
 *   $ ./v_test_binary
 *
 * NOTE: The tester needs to make using `scanf()` "size" times, and in ascending order. Otherwise, it would lead to an incorrect result.
 */
void testVisually_BinarySearch() {
    int size;
    printf("Integer Array Size: ");
    scanf("%d", &size);
    int *array = malloc(size * sizeof(int));
    printf("Input the array in ASCENDING order, split by space: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    printf("Target number: ");
    int target;
    scanf("%d", &target);
    if (binarySearch(array, size, target)) {
        printf("%d is in the array.\n", target);
    } else {
        printf("%d is NOT in the array.\n", target);
    }
    free(array);
}


int main(void) {
    testVisually_BinarySearch();
    return 0;
}
