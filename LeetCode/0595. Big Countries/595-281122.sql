/**
 * Hao Ren
 * 28 Novemeber, 2022
 * 595. Big Countries
 */

SELECT name, population, area
FROM World
WHERE (area >= 3000000 OR population >= 25000000);
