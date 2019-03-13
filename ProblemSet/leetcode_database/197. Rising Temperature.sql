-- 197. 上升的温度
-- SQL 架构
CREATE TABLE IF NOT EXISTS Weather (Id INT, RecordDate DATE, Temperature INT);
TRUNCATE TABLE Weather;
INSERT INTO Weather (Id, RecordDate, Temperature) VALUES ('1', '2015-01-01', '10');
INSERT INTO Weather (Id, RecordDate, Temperature) VALUES ('2', '2015-01-02', '25');
INSERT INTO Weather (Id, RecordDate, Temperature) VALUES ('3', '2015-01-03', '20');
INSERT INTO Weather (Id, RecordDate, Temperature) VALUES ('4', '2015-01-04', '30');
-- 查找与之前（昨天的）日期相比温度更高的所有日期的 Id
SELECT w1.id
FROM weather w1,weather w2
WHERE w1.RecordDate = DATE_ADD(w2.RecordDate,INTERVAL 1 DAY)
    AND w1.temperature > w2.temperature
