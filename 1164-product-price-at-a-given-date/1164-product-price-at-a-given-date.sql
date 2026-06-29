# Write your MySQL query statement below
SELECT product_id,10 AS price
FROM Products
GROUP BY product_id
HAVING MIN(change_date)>"2019-08-16"

UNION

SELECT p.product_id,p.new_price
FROM Products p
WHERE p.change_date=(
    SELECT MAX(c.change_date)
    FROM Products c
    WHERE p.product_id=c.product_id
    AND change_date<="2019-08-16"
    
)
