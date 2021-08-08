// Hao Ren
// Sunday, 08 August, 2021
// 1929. Concatenation of Array

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getConcatenation(int *nums, int numsSize, int *returnSize) {
    // *returnSize could be ignored in real programming;
    // but for here, it depends the returning size of array `ans`.
    // If we do not set it, the output would be
    //     Your input   [1,2,1]
    //     Output       ]
    //     Expected     [1,2,1,1,2,1]
    // And the numsSize is the length of array `nums`.
    *returnSize = 2 * numsSize;
    int *ans = malloc(sizeof(int) * *returnSize);
    for (int i = 0; i < numsSize; i++) {
        ans[i] = nums[i];
        ans[i + numsSize] = nums[i];
    }
    // Equals to `&(*ans)`;
    return ans;
}
