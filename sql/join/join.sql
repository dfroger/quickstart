/* no join */
SELECT o.OrderID, c.CustomerName, o.OrderDate
FROM Customers AS c, Orders AS o;

SELECT '---------------';

/* no join, filter on 1 customer */
SELECT o.OrderID, c.CustomerName, o.OrderDate
FROM Customers AS c, Orders AS o
WHERE c.CustomerName="Bar" AND c.CustomerID=o.CustomerID;

SELECT '---------------';

/*
INNER JOIN
All rows when there is at least one match in BOTH tables
*/
SELECT Orders.OrderID, Customers.CustomerName, Orders.OrderDate
FROM Orders
INNER JOIN Customers
ON Orders.CustomerID=Customers.CustomerID;
/* INNER JOIN == JOIN */

SELECT '---------------';

/*
LEFT OUTER JOIN
All rows from the left table, and the matched rows from the right table
*/
SELECT Orders.OrderID, Customers.CustomerName, Orders.OrderDate
FROM Orders
LEFT OUTER JOIN Customers
ON Orders.CustomerID=Customers.CustomerID;
/* LEFT OUTER JOIN == LEFT JOIN */

/*
RIGHT OUTER JOIN
All rows from the right table, and the matched rows from the left table
*/
/* not supported */

/*
FULL OUTER JOIN
All rows when there is a match in ONE of the tables
*/
/* not supported */
