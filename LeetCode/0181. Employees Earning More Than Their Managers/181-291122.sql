/**
 * Hao Ren
 * 29 Novemeber, 2022
 * 181. Employees Earning More Than Their Managers
 */


-- Solution 1: Using WHERE
SELECT
    employees.name AS Employee
FROM
    Employee AS employees,
    Employee AS managers
WHERE (
    employees.managerId = managers.id
    AND
    employees.salary > managers.salary
);

-- Solution 2: Using JOIN
SELECT
    employees.name AS Employee
FROM
    Employee AS employees
JOIN
    Employee AS managers
ON (
    employees.managerId = managers.id
    AND
    employees.salary > managers.salary
);
