-- 184. 部门工资最高的员工
DROP TABLE Employee
CREATE TABLE IF NOT EXISTS Employee (Id INT, NAME VARCHAR(255), Salary INT, DepartmentId INT);
CREATE TABLE IF NOT EXISTS Department (Id INT, NAME VARCHAR(255));
TRUNCATE TABLE Employee;
INSERT INTO Employee (Id, NAME, Salary, DepartmentId) VALUES ('1', 'Joe', '70000', '1');
INSERT INTO Employee (Id, NAME, Salary, DepartmentId) VALUES ('2', 'Henry', '80000', '2');
INSERT INTO Employee (Id, NAME, Salary, DepartmentId) VALUES ('3', 'Sam', '60000', '2');
INSERT INTO Employee (Id, NAME, Salary, DepartmentId) VALUES ('4', 'Max', '90000', '1');
TRUNCATE TABLE Department;
INSERT INTO Department (Id, NAME) VALUES ('1', 'IT');
INSERT INTO Department (Id, NAME) VALUES ('2', 'Sales');
-- Employee 表包含所有员工信息，每个员工有其对应的 Id, salary 和 department Id。
-- Department 表包含公司所有部门的信息。
-- 编写一个 SQL 查询，找出每个部门工资最高的员工。
-- 例如，根据上述给定的表格，Max 在 IT 部门有最高工资，Henry 在 Sales 部门有最高工资。
SELECT d.name Department , e.name Employee , MAX(e.Salary) Salary
FROM Employee e JOIN Department d
ON e.departmentid = d.id
grup BY d.name
-- 
SELECT d.name Department ,e.name Employee, MAX(e.salary) Salary
FROM Employee e	JOIN  Department d
ON e.departmentid = d.id
GROUP BY e.DepartmentId
-- 
SELECT (DISTINCT m.name) Department ,e1.name Employee, m.salary Salary
FROM (SELECT  MAX(e.salary) Salary,d.name,d.id pid
FROM employee e JOIN Department d
ON  e.departmentid = d.id
GROUP BY e.departmentid ) m JOIN Employee e1 
ON m.salary = e1.Salary
AND m.pid= e1.departmentid

--
SELECT  MAX(e.salary) Salary,d.name,d.id pid
FROM employee e JOIN Department d
ON  e.departmentid = d.id
GROUP BY e.departmentid
-- 
-- 连接查询Department和Employee
-- 找到工资等于部门最高的员工的名字和薪水
SELECT d.Name AS Department, e.Name AS Employee, e.Salary 
FROM Department d 
	INNER JOIN Employee e 
	ON d.Id = e.DepartmentId 
	AND e.Salary = (
		SELECT MAX(Salary) 
		FROM Employee 
		WHERE DepartmentId = d.id
	)