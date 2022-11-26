/**
 * Hao Ren
 * 17 April, 2022
 * 1350. Students With Invalid Departments
 */

SELECT id, name
FROM Students
WHERE department_id
    NOT IN (SELECT id FROM Departments);
