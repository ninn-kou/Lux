/**
 * Hao Ren
 * 30 November, 2022
 * 177. Nth Highest Salary
 */
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    DECLARE M INT;
    SET M = N - 1;
    RETURN (
        SELECT salary FROM Employee
        GROUP BY salary
        ORDER BY salary DESC
        LIMIT 1 OFFSET M
    );
END
