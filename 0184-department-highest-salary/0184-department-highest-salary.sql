SELECT dep.name AS Department,
    emp.name AS Employee,
    emp.salary AS Salary
FROM Employee emp
JOIN Department dep 
    ON emp.departmentID=dep.id
WHERE emp.salary=(
    SELECT MAX(salary)
    FROM Employee
    WHERE departmentID=emp.departmentID
);