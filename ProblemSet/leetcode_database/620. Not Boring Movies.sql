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