SELECT uni.unique_id,
        emp.name
FROM Employees emp
LEFT JOIN EmployeeUNI as uni ON emp.id=uni.id;