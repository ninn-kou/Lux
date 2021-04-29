// Hao Ren
// 29 April, 2021
// 1342. Number of Steps to Reduce a Number to Zero

int numberOfSteps(int num) {
    int counter = 0;
    while (num > 0) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num -= 1;
        }
        counter += 1;
    }
    return counter;
}
