BEGIN;

/* ============================= Orders ============================= */

CREATE TABLE Orders (
    OrderID integer,
    CustomerID integer,
    EmployeeID integer,
    OrderDate date,
    ShipperID integer
);

INSERT INTO Orders VALUES (10248, 90, 5, 1996-07-04, 3);
INSERT INTO Orders VALUES (10249, 81, 6, 1996-07-05, 1);
INSERT INTO Orders VALUES (10250, 34, 4, 1996-07-08, 2);
INSERT INTO Orders VALUES (10251, 84, 6, 1996-07-05, 1);

/* ============================= Shippers ============================= */

CREATE TABLE Shippers (
    ShipperID integer,
    ShipperName varchar(20)
);

INSERT INTO Shippers VALUES (1, 'Speedy Express');
INSERT INTO Shippers VALUES (2, 'United Package');
INSERT INTO Shippers VALUES (3, 'Federal Shipping');

/* ============================= Employees ============================= */

CREATE TABLE Employees (
    EmployeeID integer,
    LastName varchar(20),
    FirstName varchar(20),
    BirthDate date,
    Photo varchar(20),
    Notes varchar(20)
);

INSERT INTO Employees VALUES (4, 'Davolio',   'Nancy',  1968-12-08, 'EmpID1.pic',  'Education includes a BA....');
INSERT INTO Employees VALUES (5, 'Fuller',    'Andrew', 1952-02-19, 'EmpID2.pic',  'Andrew received his BTS....');
INSERT INTO Employees VALUES (6, 'Leverling', 'Janet',  1963-08-30, 'EmpID3.pic',  'Janet has a BS degree....');

COMMIT;
