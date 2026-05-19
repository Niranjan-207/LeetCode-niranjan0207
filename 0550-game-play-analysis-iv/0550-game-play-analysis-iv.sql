SELECT 
    ROUND(COUNT(a2.player_id)/(SELECT COUNT(DISTINCT player_id) FROM activity)
        ,2) AS fraction
FROM (
SELECT player_id,min(event_date) as cur
FROM Activity 
GROUP BY player_id)AS a1
JOIN Activity a2 ON a1.player_id=a2.player_id
AND DATEDIFF(a2.event_date,cur)=1;