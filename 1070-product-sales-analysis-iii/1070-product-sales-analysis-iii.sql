-- SELECT product_id,
--         min(year) AS first_year,
--         SUM(WHEN year=first_year THEN quantity END) as quantity,
--         SUM(WHEN year=first_year THEN price END) as price
-- FROM Sales
-- GROUP BY product_id;

-- WITH CTE AS(
--     SELECT product_id,min(year)
--     FROM SALES
--     GROUP BY product_id
-- )
-- SELECT s.product_id,my.year AS year,

-- SELECT CTE AS(
    SELECT product_id,year AS first_year,
            quantity,price
            FROM(
                SELECT *,DENSE_RANK() OVER(PARTITION BY product_id ORDER BY year )as fyear
                FROM Sales  
            )as t
    WHERE fyear=1;
-- )
-- SELECT *,DENSE_RANK() OVER(PARTITION BY product_id ORDER BY year) as fyear FROM Sales ;