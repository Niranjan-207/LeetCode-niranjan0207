# Write your MySQL query statement below
WITH CTE as(
    SELECT num,
    LAG(num,1) OVER(ORDER BY id) AS pre,
    LEAD(num,1) OVER(ORDER BY id) AS nex
    FROM Logs
)
SELECT DISTINCT(num) AS ConsecutiveNums
FROM CTE
WHERE num=pre AND num=nex;