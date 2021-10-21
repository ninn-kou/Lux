/**
 * Binary searching algorithm in C programming language.
 *
 * @Date    12 August, 2021
 * @Author  Hao Ren, <haoren.2906@gmail.com>
 * @GitHub  <https://github.com/flying-yogurt>
 */

#include <stdio.h>
#include <stdbool.h>

/**
 * @Precondition  `array` is sorted in ascending order.
 */
bool binarySearch(int *array, int arraySize, int target) {
    int left = 0;
    int right = arraySize - 1;
    int mid = (left + right) / 2;
    while (left <= right) {
        if (array[mid] == target) {
            return true;
        } else if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }
    return false;
}
