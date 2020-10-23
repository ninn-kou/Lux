// Hao Ren
// 24 October, 2020
// 75. Sort Colors

// Swap two integers by pointers.
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int *nums, int numsSize) {
    int curr = 0;
    int head = 0;
    int tail = numsSize - 1;
    while (curr <= tail) {
        // Case 1: current value is 0
        // Swap the current value with the head value to sort 0.
        // After swapping, both `head` and `curr` index should be added 1.
        // Because we could make sure from the start to head index, all values
        // are 0.
        if (nums[curr] == 0) {
            swap(&nums[curr++], &nums[head++]);
        // Case 2: current value is 2
        // Swap the current value with the tail value to make all 2 attach the end.
        // However, we only make the `tail` index minus one and keep the `curr` index.
        // Because the tail value has not been check, so we could not make sure
        // what is the value of the current one.
        } else if (nums[curr] == 2) {
            swap(&nums[curr], &nums[tail--]);
        // Case 3: current value is 1
        // Great, all 1 are in the middle. Go ahead.
        } else {
            curr++;
        }
    }
}
