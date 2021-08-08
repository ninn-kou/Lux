"""
Hao Ren
08 August, 2021
1935. Maximum Number of Words You Can Type
"""

class Solution(object):
    def canBeTypedWords(self, text, brokenLetters):
        """
        :type text: str
        :type brokenLetters: str
        :rtype: int
        """
        words = text.split(' ')
        available = len(words)
        for word in words:
            for letter in brokenLetters:
                if letter in word:
                    available -= 1
                    # Check each word once with each letter in brokenLetters.
                    break
        return available
