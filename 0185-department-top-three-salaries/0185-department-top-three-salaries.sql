# Write your MySQL query statement below
WITH CTE AS(
    SELECT id,name,salary,departmentId,
    DENSE_RANK() OVER(PARTITION BY departmentId ORDER BY salary DESC) as rnk
    FROM Employee
)
SELECT d.name as Department,t.name as Employee,t.salary as Salary
FROM CTE t
LEFT JOIN Department d ON d.id=t.departmentId
WHERE t.rnk<=3;