"""
Hao Ren
11 October, 2021
495. Teemo Attacking
"""

class Solution(object):
    def findPoisonedDuration(self, timeSeries, duration):
        """
        :type timeSeries: List[int]
        :type duration: int
        :rtype: int
        """
        time = 0
        length = len(timeSeries)
        for i in range(length - 1):
            time += min(timeSeries[i + 1] - timeSeries[i], duration)
        return time + duration
