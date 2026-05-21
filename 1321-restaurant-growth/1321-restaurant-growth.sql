WITH daily_sum AS(
SELECT visited_on,
    sum(amount) AS amount
FROM Customer
GROUP BY visited_on),
rolling_sum AS(
    SELECT visited_on,
    amount,
    SUM(amount) OVER(
        ORDER BY visited_on
        ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
    )AS running_sum, 
    ROW_NUMBER() OVER(ORDER BY visited_on) as rnk
    FROM daily_sum
)
SELECT visited_on,
    running_sum AS amount,
    ROUND(running_sum/7,2) as average_amount
    FROM rolling_sum
    WHERE rnk>6;
