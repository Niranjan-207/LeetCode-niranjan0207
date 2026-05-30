WITH temp AS(
    SELECT SUM(income<20000) AS "Low_Salary",SUM(income>=20000 AND income<=50000) AS "Average_Salary",SUM(income>50000) AS "High_Salary"
    FROM Accounts
)
SELECT 'Low Salary' AS category,low_Salary AS accounts_count FROM temp
UNION ALL
SELECT 'Average Salary' AS category,Average_Salary AS accounts_count FROM temp
UNION ALL
SELECT 'High Salary' AS category,High_Salary AS accounts_count FROM temp