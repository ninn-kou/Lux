// Hao Ren
// 07 August, 2021
// 1952. Three Divisors

/**
 * Sieve of Eratosthenes
 * https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 *
 * Check if given integer is a prime number.
 * Time Complexity: $O(n * log log n)$
 */
bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

/**
 * Check if given number is an integer.
 */
bool is_integer(double x) {
    int cut = (int)x;
    return x == cut;
}

bool isThree(int n) {
    if (!is_integer(sqrt(n))) return false;
    return is_prime(sqrt(n));
}
