# Write your MySQL query statement below
SELECT c.name as Customers
FROM Customers c
WHERE NOT EXISTS(
    SELECT CustomerId 
    FROM Orders o
    WHERE c.id=o.customerId
);