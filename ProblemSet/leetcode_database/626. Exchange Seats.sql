-- 626. 换座位
-- SQL架构
CREATE TABLE IF NOT EXISTS seat(id INT, student VARCHAR(255));
TRUNCATE TABLE seat;
INSERT INTO seat (id, student) VALUES ('1', 'Abbot');
INSERT INTO seat (id, student) VALUES ('2', 'Doris');
INSERT INTO seat (id, student) VALUES ('3', 'Emerson');
INSERT INTO seat (id, student) VALUES ('4', 'Green');
INSERT INTO seat (id, student) VALUES ('5', 'Jeames');
-- 有一张 seat 座位表，
-- 平时用来储存学生名字和与他们相对应的座位 id
-- 其中纵列的 id 是连续递增的
-- 改变相邻俩学生的座位。

-- 将偶数id-1调整为奇数id 
SELECT
    s1.id - 1 AS id,
    s1.student
FROM
    seat s1
WHERE
    s1.id MOD 2 = 0 UNION
-- 将奇数id + 1调整为偶数id
-- 最后一个id除外
SELECT
    s2.id + 1 AS id,
    s2.student
FROM
    seat s2
WHERE
    s2.id MOD 2 = 1
    AND s2.id != ( SELECT MAX( s3.id ) FROM seat s3 ) UNION
-- 添加最后一名奇数同学
-- 将全部同学id升序排列
SELECT
    s4.id AS id,
    s4.student
FROM
    seat s4
WHERE
    s4.id MOD 2 = 1
    AND s4.id = ( SELECT MAX( s5.id ) FROM seat s5 )
ORDER BY
    id;