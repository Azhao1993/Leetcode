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