"""
Hao Ren
27 August, 2021
1672. Richest Customer Wealth
"""

class Solution(object):
    def maximumWealth(self, accounts):
        """
        :type accounts: List[List[int]]
        :rtype: int
        """
        return max([sum(customer) for customer in accounts])
