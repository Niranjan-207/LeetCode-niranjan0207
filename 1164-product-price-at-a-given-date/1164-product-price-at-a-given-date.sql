(SELECT product_id,10 as price
FROM Products
GROUP BY product_id
HAVING MIN(change_date)>"2019-08-16")
UNION ALL
(SELECT p1.product_id,p1.new_price as price
FROM Products p1
WHERE change_date=(
    SELECT max(p2.change_date) as change_date
    FROM Products p2
    WHERE p1.product_id=p2.product_id
    AND p2.change_date<="2019-08-16"
))