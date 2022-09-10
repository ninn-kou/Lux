/**
 * Hao Ren
 * 17 April, 2022
 * 1757. Recyclable and Low Fat Products
 */

SELECT
    product_id
FROM
    Products
WHERE
    low_fats = 'Y'
    AND recyclable = 'Y'
