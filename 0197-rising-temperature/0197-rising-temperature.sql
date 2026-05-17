SELECT cur.id
FROM Weather cur
JOIN Weather pre on cur.recordDate=DATE_ADD(pre.recordDate,INTERVAL 1 DAY)
WHERE cur.temperature>pre.temperature;