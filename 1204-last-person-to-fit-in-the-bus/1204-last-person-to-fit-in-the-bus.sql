# Write your MySQL query statement below
WITH CTE AS(
    SELECT person_name,
        SUM(weight) OVER(ORDER BY turn ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW) as csum
    FROM Queue
)
SELECT person_name
FROM CTE
WHERE csum<=1000
ORDER BY csum DESC
LIMIT 1;