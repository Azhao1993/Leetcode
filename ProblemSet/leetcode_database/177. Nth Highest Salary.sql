-- 177. 第N高的薪水
DROP TABLE Employee 
CREATE TABLE Employee (
Id INT ,
Salary INT
);
INSERT INTO Employee  
VALUES
	(1,100),
	(2,200),
	(3,300);
-- Employee 表，n = 2 时，
-- 应返回第二高的薪水 200。
-- 如果不存在第 n 高的薪水，那么查询应返回 null。
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
-- -----------------------------------------
	-- if(count>=n,0-n行中最小的,null)
	SELECT (
	IF(
		(SELECT COUNT(*) 
		FROM (
			SELECT DISTINCT e1.Salary 
			FROM Employee e1
		     ) e2
		)>=N,
	(
		SELECT MIN(e4.Salary) 
		FROM (
			SELECT DISTINCT e3.Salary 
			FROM Employee e3 
			ORDER BY e3.Salary DESC 
			LIMIT N
		     ) e4
	), NULL))
-- ----------------------------------------------------
  );
END
