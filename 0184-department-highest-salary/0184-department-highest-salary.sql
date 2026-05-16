SELECT Department,Employee,Salary
FROM
(SELECT dep.name as Department,emp.name as Employee,Salary,
    DENSE_RANK() OVER(PARTITION BY emp.departmentID ORDER BY emp.Salary DESC) as rnk
FROM Employee emp
JOIN Department dep ON emp.departmentId=dep.id) as t
WHERE rnk=1;