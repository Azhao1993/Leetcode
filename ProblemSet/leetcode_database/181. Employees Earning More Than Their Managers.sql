-- 181. 超过经理收入的员工
-- SQL架构
DROP TABLE employee;
CREATE TABLE IF NOT EXISTS Employee (Id INT, NAME VARCHAR(255), Salary INT, ManagerId INT);
TRUNCATE TABLE Employee;
INSERT INTO Employee (Id, NAME, Salary, ManagerId) VALUES ('1', 'Joe', '70000', '3');
INSERT INTO Employee (Id, NAME, Salary, ManagerId) VALUES ('2', 'Henry', '80000', '4');
INSERT INTO Employee (Id, NAME, Salary, ManagerId) VALUES ('3', 'Sam', '60000', 'None');
INSERT INTO Employee (Id, NAME, Salary, ManagerId) VALUES ('4', 'Max', '90000', 'None');
-- 给定 Employee 表，编写一个 SQL 查询，
-- 该查询可以获取收入超过他们经理的员工的姓名。:自连接
-- 在上面的表格中，Joe 是唯一一个收入超过他的经理的员工。
SELECT Employee
FROM(
SELECT e1.NAME Employee,e1.salary es,e2.salary ms
FROM employee e1,employee e2
WHERE e1.managerid = e2.id
) p
WHERE p.es>p.ms;


SELECT
    E1.NAME AS Employee
FROM
    Employee E1
    INNER JOIN Employee E2
    ON E1.ManagerId = E2.Id
    AND E1.Salary > E2.Salary;
