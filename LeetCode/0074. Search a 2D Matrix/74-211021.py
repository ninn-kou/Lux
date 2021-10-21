"""
Hao Ren
21 October, 2021
74. Search a 2D Matrix
"""

class Solution_One(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        seq = []
        row = len(matrix)

        for i in range(row):
            seq += matrix[i]

        l = 0
        r = len(seq) - 1

        while l <= r:
            mid = (l + r) // 2
            if seq[mid] == target:
                return True
            elif seq[mid] < target:
                l = mid + 1
            else:
                r = mid - 1

        return False

class Solution_Two(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        firstColumn = self.column(matrix, 0)
        index = self.searchColumn(firstColumn, target)
        if index == -1:
            return True
        elif index == -2:
            return False
        else:
            return self.searchRow(matrix[index], target)

    def searchRow(self, row, target):
        l = 0
        r = len(row) - 1
        while l <= r:
            mid = (l + r) // 2
            if row[mid] == target:
                return True
            elif row[mid] < target:
                l = mid + 1
            else:
                r = mid - 1
        return False

    def searchColumn(self, column, target):
        l = 0
        r = len(column) - 1
        while l <= r:
            mid = (l + r) // 2
            if column[mid] == target:
                return -1
            if column[mid] < target:
                # The order for the following if..or statement could not be exchanged.
                # Otherwise, it might caused an IndexError: list index out of range.
                if mid == len(column) - 1 or column[mid + 1] > target:
                    return mid
                else:
                    l = mid + 1
            else:
                r = mid - 1
        return -2

    def column(self, matrix, i):
        return [row[i] for row in matrix]
