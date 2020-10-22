// Hao Ren
// 23 October, 2020
// 50. Pow(x, n)

// The last bit of x in binary must be 1 if x is an odd number, so `x & 1` is
// `1`. Additionally, if x is an even number the bit operating should get a `0`.
double myPow(double x, long long n) {
    if (n < 0) {
        return myPow(1 / x, -n);
    } else if (n == 0.0) {
        return 1.0;
    } else if (n == 1.0) {
        return x;
    // if x is odd:
    } else if (n & 1) {
        return x * myPow(x * x, (n - 1) / 2);
    // if x is even:
    } else {
        return myPow(x * x, n / 2);
    }
}
