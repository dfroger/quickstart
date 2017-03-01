SELECT o.OrderID, c.CustomerName, o.OrderDate
FROM Customers AS c, Orders AS o;

SELECT '---------------';

SELECT o.OrderID, c.CustomerName, o.OrderDate
FROM Customers AS c, Orders AS o
WHERE c.CustomerName="Bar" AND c.CustomerID=o.CustomerID;

SELECT '---------------';

SELECT Orders.OrderID, Customers.CustomerName, Orders.OrderDate
FROM Orders
INNER JOIN Customers
ON Orders.CustomerID=Customers.CustomerID;
