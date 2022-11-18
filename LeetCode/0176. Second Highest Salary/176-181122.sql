/**
 * Hao Ren
 * 18 November, 2022
 * 176. Second Highest Salary
 */
SELECT (
    SELECT salary FROM Employee
    GROUP BY salary
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1
) AS SecondHighestSalary
