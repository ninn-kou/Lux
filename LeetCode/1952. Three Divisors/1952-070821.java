import java.lang.Math.*;

/**
 * 1952. Three Divisors
 *
 * 07 August, 2021
 *
 * @author Hao Ren
 */
class Solution {
    public boolean isPrime(int x) {
        if (x < 2)
            return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }

    public boolean isThree(int n) {
        double root = Math.sqrt(n);
        if (root != (int) root)
            return false;
        return isPrime((int) root);
    }
}
