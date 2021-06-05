// Hao Ren
// 22 October, 2020
// 283. Move Zeroes

void moveZeroes(int *nums, int numsSize) {
    int slow = 0;
    // Copy all non-zero integer in front of all zeros.
    for (int fast = 0; fast < numsSize; fast++) {
        if (nums[fast] != 0) {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    // Put zeros at the end.
    while (slow < numsSize) {
        nums[slow] = 0;
        slow++;
    }
}
