SELECT su.user_id,
    ROUND(
        IFNULL(SUM(c.action='confirmed')/COUNT(c.action),0),
    2) 
    as confirmation_rate
FROM Signups AS su
LEFT JOIN Confirmations c ON su.user_id=c.user_id
GROUP BY su.user_id;