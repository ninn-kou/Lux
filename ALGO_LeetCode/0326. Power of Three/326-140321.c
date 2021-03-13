// Hao Ren
// 14 March, 2021
// 326. Power of Three

bool isPowerOfThree(int n) {
    if (n < 1) return false;
    while (n % 3 == 0) {
        n /= 3;
    }
    return n == 1 ? true : false;
}
