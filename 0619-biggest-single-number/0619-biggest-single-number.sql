# Write your MySQL query statement below
SELECT max(num) AS num
FROM 
(SELECT num,COUNT(*)
FROM MyNumbers
GROUP BY num
HAVING COUNT(*)=1) as t;