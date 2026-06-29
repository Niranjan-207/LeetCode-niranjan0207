# Write your MySQL query statement below
SELECT cur.id
FROM Weather cur
JOIN Weather pre ON cur.recordDate=DATE_ADD(pre.recordDAte,INTERVAL 1 DAY)
WHERE cur.temperature>pre.temperature;
