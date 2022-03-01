// Hao Ren
// 02 March, 2022
// 485. Max Consecutive Ones

int findMaxConsecutiveOnes(int *nums, int numsSize) {
    int max_consec = 0;
    int cur_consec = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            cur_consec++;
            max_consec = cur_consec > max_consec ? cur_consec : max_consec;
        } else {
            cur_consec = 0;
        }
    }
    return max_consec;
}
