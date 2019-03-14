-- 183. 从不订购的客户
-- SQL架构
CREATE TABLE IF NOT EXISTS Customers (Id INT, NAME VARCHAR(255));
CREATE TABLE IF NOT EXISTS Orders (Id INT, CustomerId INT);
TRUNCATE TABLE Customers;
INSERT INTO Customers (Id, NAME) VALUES ('1', 'Joe');
INSERT INTO Customers (Id, NAME) VALUES ('2', 'Henry');
INSERT INTO Customers (Id, NAME) VALUES ('3', 'Sam');
INSERT INTO Customers (Id, NAME) VALUES ('4', 'Max');
TRUNCATE TABLE Orders;
INSERT INTO Orders (Id, CustomerId) VALUES ('1', '3');
INSERT INTO Orders (Id, CustomerId) VALUES ('2', '1');
-- 某网站包含两个表，Customers 表和 Orders 表。
-- 编写一个 SQL 查询，找出所有从不订购任何东西的客户。

-- 左外连接
SELECT
    C.Name AS Customers
FROM
    Customers C
    LEFT JOIN Orders O
    ON C.Id = O.CustomerId
WHERE
    O.CustomerId IS NULL;
-- 子查询
SELECT
    NAME AS Customers
FROM
    Customers
WHERE
    Id NOT IN ( SELECT CustomerId FROM Orders );