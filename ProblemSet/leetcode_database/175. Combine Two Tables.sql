-- 175. 组合两个表
-- SQL架构
DROP TABLE person;
DROP TABLE Address;
CREATE TABLE Person (PersonId INT, FirstName VARCHAR(255), LastName VARCHAR(255));
CREATE TABLE Address (AddressId INT, PersonId INT, City VARCHAR(255), State VARCHAR(255));
TRUNCATE TABLE Person;
INSERT INTO Person (PersonId, LastName, FirstName) VALUES ('1', 'Wang', 'Allen');
TRUNCATE TABLE Address;
INSERT INTO Address (AddressId, PersonId, City, State) VALUES ('1', '2', 'New York City', 'New York');
-- 无论 person 是否有地址信息，
-- 都需要基于上述两表提供 person 的以下信息：
-- FirstName, LastName, City, State
SELECT 
	FirstName,
	LastName,
	city,
	state
FROM 
	person p
	LEFT JOIN address a
	ON p.PersonId=a.personid;
	