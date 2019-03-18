-- 596. 超过5名学生的课
CREATE TABLE IF NOT EXISTS courses (student VARCHAR(255), class VARCHAR(255));
TRUNCATE TABLE courses;
INSERT INTO courses (student, class) VALUES ('A', 'Math');
INSERT INTO courses (student, class) VALUES ('B', 'English');
INSERT INTO courses (student, class) VALUES ('C', 'Math');
INSERT INTO courses (student, class) VALUES ('D', 'Biology');
INSERT INTO courses (student, class) VALUES ('E', 'Math');
INSERT INTO courses (student, class) VALUES ('F', 'Computer');
INSERT INTO courses (student, class) VALUES ('G', 'Math');
INSERT INTO courses (student, class) VALUES ('H', 'Math');
INSERT INTO courses (student, class) VALUES ('I', 'Math');
-- 有一个courses 表 ，有: student (学生) 和 class (课程)。
-- 请列出所有超过或等于5名学生的课。
-- 学生在每个课中不应被重复计算(存在重复数据)。

SELECT c.class
FROM (SELECT COUNT(DISTINCT student) num,class
FROM courses
GROUP BY class
HAVING num>=5) c
