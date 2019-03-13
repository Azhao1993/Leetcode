-- 627. 交换工资
-- SQL架构
CREATE TABLE IF NOT EXISTS salary(id INT, NAME VARCHAR(100), sex CHAR(1), salary INT);
TRUNCATE TABLE salary;
INSERT INTO salary (id, NAME, sex, salary) VALUES ('1', 'A', 'm', '2500');
INSERT INTO salary (id, NAME, sex, salary) VALUES ('2', 'B', 'f', '1500');
INSERT INTO salary (id, NAME, sex, salary) VALUES ('3', 'C', 'm', '5500');
INSERT INTO salary (id, NAME, sex, salary) VALUES ('4', 'D', 'f', '500');
-- 给定一个 salary 表，如下所示，有 m=男性 和 f=女性 的值 。
-- 交换所有的 f 和 m 值（例如，将所有 f 值更改为 m，反之亦然）。
-- 要求使用一个更新（Update）语句，并且没有中间临时表。
-- 请注意，你必须编写一个 Update 语句，不要编写任何 Select 语句。
UPDATE salary
SET sex = 
CHAR(
ASCII(sex)^ASCII('m')^ASCII('f')
);

 