/**
 * Hao Ren
 * 4 November, 2022
 * 175. Combine Two Tables
 */

SELECT
    Person.firstName,
    Person.lastName,
    Address.city,
    Address.state
FROM
    Person
LEFT JOIN
    Address
ON
    Person.personId = Address.personId;
