SELECT DISTINCT num as ConsecutiveNums FROM
(SELECT num,
    LAG (num,1) OVER(ORDER BY id) as l1,
    LEAD (num,1) OVER(ORDER BY id) as l2
FROM Logs) as t
WHERE l1=num AND l2=num;