SELECT Name AS 'Customers'
FROM Customers AS a
    LEFT JOIN Orders AS b ON a.Id = b.CustomerId
WHERE CustomerId IS NULL;
---
SELECT customers.name AS 'Customers'
FROM customers
WHERE customers.id NOT IN (
        SELECT customerid
        FROM orders
    );