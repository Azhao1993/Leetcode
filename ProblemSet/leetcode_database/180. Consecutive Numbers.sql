-- 180. 连续出现的数字
-- SQL架构
CREATE TABLE IF NOT EXISTS LOGS (Id INT, Num INT);
TRUNCATE TABLE LOGS;
INSERT INTO LOGS (Id, Num) VALUES ('1', '1');
INSERT INTO LOGS (Id, Num) VALUES ('2', '1');
INSERT INTO LOGS (Id, Num) VALUES ('3', '1');
INSERT INTO LOGS (Id, Num) VALUES ('4', '2');
INSERT INTO LOGS (Id, Num) VALUES ('5', '1');
INSERT INTO LOGS (Id, Num) VALUES ('6', '2');
INSERT INTO LOGS (Id, Num) VALUES ('7', '2');
-- 查找所有至少连续出现三次的数字
SELECT
    DISTINCT L1.num ConsecutiveNums
FROM
    LOGS L1,
    LOGS L2,
    LOGS L3
WHERE 
	L1.id = l2.id - 1 
    AND L2.id = L3.id - 1
    AND L1.num = L2.num
    AND l2.num = l3.num;