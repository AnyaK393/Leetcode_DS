-- Query 1: Get the latest price change on or before 2019-08-16
SELECT 
    product_id, 
    new_price AS price
FROM Products
WHERE (product_id, change_date) IN (
    SELECT 
        product_id, 
        MAX(change_date)
    FROM Products
    WHERE change_date <= '2019-08-16'
    GROUP BY product_id
)

UNION ALL

-- Query 2: Get products with no price changes on or before 2019-08-16 (default price 10)
SELECT 
    product_id, 
    10 AS price
FROM Products
GROUP BY product_id
HAVING MIN(change_date) > '2019-08-16';