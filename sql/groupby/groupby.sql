/*
The GROUP BY statement is used in conjunction with the aggregate functions to
group the result-set by one or more columns.

SELECT col, aggfunc(col)
FROM table
WHERE col op value
GROUP BY col;
*/

SELECT Shippers.ShipperName, COUNT(Orders.OrderID) AS NumberOfOrders
FROM Orders
LEFT JOIN Shippers
ON Orders.ShipperID=Shippers.ShipperID
GROUP BY ShipperName;

SELECT '---------------';

SELECT Shippers.ShipperName, Employees.LastName, COUNT(Orders.OrderID) AS NumberOfOrders
FROM Orders
INNER JOIN Shippers
ON Orders.ShipperID=Shippers.ShipperID
INNER JOIN Employees
ON Orders.EmployeeID=Employees.EmployeeID
GROUP BY ShipperName, LastName;

SELECT '---------------';

SELECT Shippers.ShipperName, Employees.LastName
FROM Orders
INNER JOIN Shippers
ON Orders.ShipperID=Shippers.ShipperID
INNER JOIN Employees
ON Orders.EmployeeID=Employees.EmployeeID;

/*
SELECT Shippers.ShipperName, COUNT(Orders.OrderID) AS NumberOfOrders
FROM Shippers
LEFT JOIN Orders
ON Orders.ShipperID=Shippers.ShipperID
GROUP BY ShipperName;
*/
