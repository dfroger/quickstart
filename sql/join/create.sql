BEGIN;

CREATE TABLE Orders (OrderID integer, CustomerID integer, OrderDate date);

INSERT INTO Orders VALUES (0, 7, '2016-03-12');
INSERT INTO Orders VALUES (1, 3, '2016-04-01');
INSERT INTO Orders VALUES (2, 9, '2016-04-05');
INSERT INTO Orders VALUES (3, 42, '2016-04-08');

CREATE TABLE Customers (CustomerID integer,
                        CustomerName varchar(20),
                        ContactName varchar(20),
                        Country varchar(20));

INSERT INTO Customers VALUES (3, 'Foo', 'Alice', 'France');
INSERT INTO Customers VALUES (7, 'Bar', 'Bob', 'Italy');
INSERT INTO Customers VALUES (9, 'Baz', 'Charlie', 'Italy');
INSERT INTO Customers VALUES (23, 'Boo', 'David', 'France');

COMMIT;
