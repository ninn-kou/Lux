"""
Hao Ren
20 November, 2020
1227. Airplane Seat Assignment Probability
"""

class Solution(object):
    def nthPersonGetsNthSeat(self, n):
        """
        :type n: int
        :rtype: float
        """
        if n > 1:
            return 0.5
        else:
            return 1.0
