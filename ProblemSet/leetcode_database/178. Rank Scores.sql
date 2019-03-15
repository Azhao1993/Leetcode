-- 178. 分数排名
-- SQL架构
CREATE TABLE IF NOT EXISTS Scores (Id INT, Score DECIMAL(3,2));
TRUNCATE TABLE Scores;
INSERT INTO Scores (Id, Score) VALUES ('1', '3.5');
INSERT INTO Scores (Id, Score) VALUES ('2', '3.65');
INSERT INTO Scores (Id, Score) VALUES ('3', '4.0');
INSERT INTO Scores (Id, Score) VALUES ('4', '3.85');
INSERT INTO Scores (Id, Score) VALUES ('5', '4.0');
INSERT INTO Scores (Id, Score) VALUES ('6', '3.65');
-- 查询应该返回（按分数从高到低排列）
-- 名次之间不应该有“间隔”

-- 名次用count()统计
-- 用id分组 保证分数不去重

SELECT
    S1.score,
    COUNT( DISTINCT S2.score ) Rank
FROM
    Scores S1
    INNER JOIN Scores S2
    ON S1.score <= S2.score
GROUP BY
    S1.id
ORDER BY
    S1.score DESC;
-- 连接查询
SELECT
  Score,
  (SELECT COUNT(DISTINCT Score) FROM Scores WHERE Score >= s.Score) Rank
FROM Scores s
ORDER BY Score desc