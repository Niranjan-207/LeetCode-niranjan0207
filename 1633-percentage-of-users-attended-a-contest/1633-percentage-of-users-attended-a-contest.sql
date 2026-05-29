WITH cte AS(
    SELECT COUNT(*) as cnt FROM Users 
)
SELECT contest_id,ROUND((COUNT(*)/(SELECT cnt FROM cte))*100.00,2) as percentage
FROM Register
GROUP BY contest_id
ORDER BY percentage desc,contest_id;