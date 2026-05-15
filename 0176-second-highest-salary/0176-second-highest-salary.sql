SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE salary<(SELECT MAX(Salary) FROM Employee);