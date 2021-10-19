// Hao Ren
// 19 October, 2021
// 136. Single Number

int singleNumber(int *nums, int numsSize) {
    int single = 0;
    for (int i = 0; i < numsSize; i++) {
        single ^= nums[i];
    }
    return single;
}
