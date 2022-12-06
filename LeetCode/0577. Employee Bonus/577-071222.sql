/**
 * Hao Ren
 * 7 December, 2022
 * 577. Employee Bonus
 */
SELECT
    Employee.name, Bonus.bonus
FROM
    Employee
        LEFT OUTER JOIN
    Bonus
        ON Employee.empID = Bonus.empID
WHERE
    Bonus.bonus < 1000 OR Bonus.bonus IS NULL;
