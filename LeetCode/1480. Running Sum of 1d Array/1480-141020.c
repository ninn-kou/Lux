// Hao Ren
// 14 October, 2020
// 1480. Running Sum of 1d Array


// Note: The returned array must be malloced, assume caller calls free().

int *runningSum(int *nums, int numsSize, int *returnSize) {
    // Create an empty array which has the same length to the given one.
    *returnSize = numsSize;
    int *output = (int *)malloc((*returnSize) * sizeof(int));
    // Because the start point is the 2nd element in the array, we need to
    // assign the first one.
    output[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        output[i] = output[i - 1] + nums[i];
    }
    return output;
}
