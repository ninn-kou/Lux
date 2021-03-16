// Hao Ren
// 16 March, 2021
// 1716. Calculate Money in LeetCode Bank

int totalMoney(int n) {
    // w is the number of full-week past.
    int w = n / 7;
    // r is the number of days which could not be calculated as a full week.
    int r = n % 7;
    // Careful! Because of the integer data type, 49/2 is equal to 24 rather
    // than 24.5, so we need to multiple it by 2 and then divided it by 2.
    return (2 * w * r + r * r + r + 7 * w * w + 49 * w) / 2;
}
