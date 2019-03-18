-- 185. 部门工资前三高的员工
DROP TABLE Employee;
CREATE TABLE IF NOT EXISTS Employee (Id INT, NAME VARCHAR(255), Salary INT, DepartmentId INT);
DROP TABLE Department;
CREATE TABLE IF NOT EXISTS Department (Id INT, NAME VARCHAR(255));
TRUNCATE TABLE Employee;
INSERT INTO Employee (Id, NAME, Salary, DepartmentId) VALUES ('1', 'Joe', '70000', '1');
INSERT INTO Employee (Id, NAME, Salary, DepartmentId) VALUES ('2', 'Henry', '80000', '2');
INSERT INTO Employee (Id, NAME, Salary, DepartmentId) VALUES ('3', 'Sam', '60000', '2');
INSERT INTO Employee (Id, NAME, Salary, DepartmentId) VALUES ('4', 'Max', '90000', '1');
INSERT INTO Employee (Id, NAME, Salary, DepartmentId) VALUES ('5'  ,'Janet'  ,'69000'  ,'1');
INSERT INTO Employee (Id, NAME, Salary, DepartmentId) VALUES (| '6'  ,' Randy'  ,'85000'  ,'1')  ;
TRUNCATE TABLE Department;
INSERT INTO Department (Id, NAME) VALUES ('1', 'IT');
INSERT INTO Department (Id, NAME) VALUES ('2', 'Sales');
-- 找出每个部门工资前三高的员工
SELECT d.name AS Department,e.name AS Employee,e.salary AS Salary 
FROM employee AS e 
	INNER JOIN department AS d 
	ON e.DepartmentId=d.id
WHERE (
	SELECT COUNT( DISTINCT salary) 
	FROM employee 
	WHERE salary>e.salary 
	AND departmentid=e.DepartmentId )<3 
ORDER BY e.departmentid,Salary DESC
--
SELECT P2.Name AS Department,P3.Name AS Employee,P3.Salary AS Salary
FROM Employee AS P3
	INNER JOIN Department AS P2
	ON P2.Id = P3.DepartmentId 
WHERE (
    SELECT COUNT(DISTINCT Salary)
    FROM Employee AS P4
    WHERE P3.DepartmentId = P4.DepartmentId
    AND P4.Salary >= P3.Salary
) <= 3
ORDER BY DepartmentId,Salary DESC