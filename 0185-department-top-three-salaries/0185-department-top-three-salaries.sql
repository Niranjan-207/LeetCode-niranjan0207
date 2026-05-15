SELECT dep.name AS Department,
        emp.name AS Employee,
        emp.salary AS salary
FROM Employee emp
JOIN Department dep on emp.departmentId=dep.id
WHERE (
    SELECT COUNT(DISTINCT e2.salary)
    FROM Employee e2
    WHERE e2.departmentId=emp.departmentId
        AND e2.salary>emp.salary
)<3;