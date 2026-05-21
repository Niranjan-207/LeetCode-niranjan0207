WITH monthly AS(
    SELECT DATE_FORMAT(trans_date,"%Y-%m") as month,
    country,
    state,
    amount,
    trans_date
    FROM Transactions
)
SELECT month,
      country,
      COUNT(*) as trans_count,
      SUM(CASE WHEN state="approved" THEN 1 ELSE 0 END) as approved_count,
      SUM(amount) AS trans_total_amount,
      SUM(CASE WHEN state="approved" THEN amount ELSE 0 END) as approved_total_amount
FROM monthly
GROUP BY month,country;