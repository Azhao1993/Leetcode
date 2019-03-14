-- 196. 删除重复的电子邮箱
-- SQL架构
CREATE TABLE IF NOT EXISTS Person(
	id INT,
	Email VARCHAR(50));
TRUNCATE TABLE person;
INSERT INTO person(id,email)
VALUE(1,'john@example.com');

INSERT INTO person(id,email)
VALUE(2,'bob@example.com');

INSERT INTO person(id,email)
VALUE(3,'john@example.com');
-- 连接查询（笛卡尔积）并用相同email筛选
SELECT p1.*
FROM Person p1,Person p2
WHERE
    p1.Email = p2.Email
-- 剔除 不重复的
SELECT p1.*
FROM Person p1,
    Person p2
WHERE
    p1.Email = p2.Email 
    AND p1.Id > p2.Id;
-- 删除上面的选项
DELETE p1.*
FROM person p1,
    person p2
WHERE 
   p1.email = p2.Email
   AND p1.id > p2.id