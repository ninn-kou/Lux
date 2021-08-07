"""
Hao Ren
07 August, 2021
1952. Three Divisors
"""

import math

class Solution(object):
    def is_prime(self, x):
        if x < 2:
            return False
        if x % 2 == 0 and x > 2:
            return False
        for i in range(3, int(math.sqrt(x)) + 1, 2):
            if x % i == 0:
                return False
        return True

    def isThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if (math.sqrt(n).is_integer() == False):
            return False
        return self.is_prime(math.sqrt(n))
