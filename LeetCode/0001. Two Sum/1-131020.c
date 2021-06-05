// Hao Ren
// 13 October, 2020
// 1. Two Sum

// Note: The returned array must be malloced, assume caller calls free().

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    *returnSize = 2;
    // Create an empty array by the size given. In this problem, the length of
    // returned array should be always "2".
    int *output = (int *)malloc((*returnSize) * sizeof(int));
    // Locate the first number to find if there is another one.
    for (int i = 0; i < numsSize; i++) {
        int diff = target - nums[i];
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] == diff) {
                // `i <= j;` should be always True.
                output[0] = i;
                output[1] = j;
            }
        }
    }
    // Return a pointer to the output array.
    return output;
}
