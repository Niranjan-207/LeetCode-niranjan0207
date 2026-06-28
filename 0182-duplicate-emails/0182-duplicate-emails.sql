# Write your MySQL query statement below
select email
FROM Person
GROUP BY email
HAVING COUNT(*)>1;