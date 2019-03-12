-- 595.大的国家
-- SQL架构
CREATE TABLE IF NOT EXISTS World (NAME VARCHAR(255), continent VARCHAR(255), AREA INT, population INT, gdp INT);
TRUNCATE TABLE World;
INSERT INTO World (NAME, continent, AREA, population, gdp) VALUES ('Afghanistan', 'Asia', '652230', '25500100', '20343000000');
INSERT INTO World (NAME, continent, AREA, population, gdp) VALUES ('Albania', 'Europe', '28748', '2831741', '12960000000');
INSERT INTO World (NAME, continent, AREA, population, gdp) VALUES ('Algeria', 'Africa', '2381741', '37100000', '188681000000');
INSERT INTO World (NAME, continent, AREA, population, gdp) VALUES ('Andorra', 'Europe', '468', '78115', '3712000000');
INSERT INTO World (NAME, continent, AREA, population, gdp) VALUES ('Angola', 'Africa', '1246700', '20609294', '100990000000');
-- sloution
SELECT NAME,population,AREA
FROM world
WHERE population>25000000
	OR AREA>3000000;
-- 182. 查找重复的电子邮箱
-- SQL架构
CREATE TABLE IF NOT EXISTS Person (Id INT, Email VARCHAR(255));
TRUNCATE TABLE Person;
INSERT INTO Person (Id, Email) VALUES ('1', 'a@b.com');
INSERT INTO Person (Id, Email) VALUES ('2', 'c@d.com');
INSERT INTO Person (Id, Email) VALUES ('3', 'a@b.com');
-- sloution
SELECT email
FROM person
GROUP BY email
HAVING COUNT(email)>1;

-- 620.有趣的电影
-- SQL架构
CREATE TABLE IF NOT EXISTS cinema (id INT, movie VARCHAR(255), description VARCHAR(255), rating FLOAT(2, 1));
TRUNCATE TABLE cinema;
INSERT INTO cinema (id, movie, description, rating) VALUES ('1', 'War', 'great 3D', '8.9');
INSERT INTO cinema (id, movie, description, rating) VALUES ('2', 'Science', 'fiction', '8.5');
INSERT INTO cinema (id, movie, description, rating) VALUES ('3', 'irish', 'boring', '6.2');
INSERT INTO cinema (id, movie, description, rating) VALUES ('4', 'Ice song', 'Fantacy', '8.6');
INSERT INTO cinema (id, movie, description, rating) VALUES ('5', 'House card', 'Interesting', '9.1');
-- sloution
-- 所有影片描述为非 boring (不无聊) 的
-- 并且 id 为奇数 的影片，
-- 结果请按等级 rating 排列。
SELECT id,movie,description,rating
FROM cinema
WHERE description!='boring' AND id%2=1
GROUP BY rating DESC;
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
SELECT p.FirstName,p.LastName,a.city,a.state
FROM address a, person p,(SELECT PERSONID FROM person) p1
WHERE p1.personid=a.PersonId ;
