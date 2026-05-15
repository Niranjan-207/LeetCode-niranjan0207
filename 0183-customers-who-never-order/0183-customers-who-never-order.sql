SELECT name as Customers
FROM Customers c
WHERE NOT EXISTS(
    SELECT CustomerID 
    FROM Orders o
    WHERE c.id=o.CustomerID
);
