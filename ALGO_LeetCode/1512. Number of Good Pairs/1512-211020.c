// Hao Ren
// 21 October, 2020
// 1512. Number of Good Pairs

int numIdenticalPairs(int *nums, int numsSize) {
    int good_pairs = 0;
    for (int i = 0; i < numsSize; i++) {
        // Start from the next element.
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                good_pairs += 1;
            }
        }
    }
    return good_pairs;
}
