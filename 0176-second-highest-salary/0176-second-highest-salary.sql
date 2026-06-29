# Write your MySQL query statement below
SELECT (SELECT salary
        FROM (
            SELECT Distinct salary,
            DENSE_RANK() OVER(ORDER BY salary DESC) as rnk
            FROM Employee
        ) as t
        WHERE rnk=2
) AS SecondHighestSalary;
