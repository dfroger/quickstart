SELECT o.OrderID, o.OrderDate, c.CustomerName
FROM Customers AS c, Orders AS o;

SELECT '---------------';

SELECT o.OrderID, o.OrderDate, c.CustomerName
FROM Customers AS c, Orders AS o
WHERE c.CustomerName="Bar" AND c.CustomerID=o.CustomerID;
