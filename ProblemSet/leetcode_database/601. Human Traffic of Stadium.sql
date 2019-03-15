-- 601. 体育馆的人流量
CREATE TABLE IF NOT EXISTS stadium (id INT, visit_date DATE NULL, people INT);
TRUNCATE TABLE stadium;
INSERT INTO stadium (id, visit_date, people) VALUES ('1', '2017-01-01', '10');
INSERT INTO stadium (id, visit_date, people) VALUES ('2', '2017-01-02', '109');
INSERT INTO stadium (id, visit_date, people) VALUES ('3', '2017-01-03', '150');
INSERT INTO stadium (id, visit_date, people) VALUES ('4', '2017-01-04', '99');
INSERT INTO stadium (id, visit_date, people) VALUES ('5', '2017-01-05', '145');
INSERT INTO stadium (id, visit_date, people) VALUES ('6', '2017-01-06', '1455');
INSERT INTO stadium (id, visit_date, people) VALUES ('7', '2017-01-07', '199');
INSERT INTO stadium (id, visit_date, people) VALUES ('8', '2017-01-08', '188');
-- 序号 (id)、日期 (date)、 人流量 (people)
-- 找出高峰期时段，要求连续三天及以上，并且每天人流量均不少于100。

SELECT DISTINCT a.* 
FROM stadium a,stadium b,stadium c
WHERE 
	a.people>=100 
    AND b.people>=100 
    AND c.people>=100
    AND (
	-- abc		
	(a.id = b.id-1 AND b.id = c.id -1) OR
	-- cab
	(a.id = b.id-1 AND a.id = c.id +1) OR
	-- cba
	(a.id = b.id+1 AND b.id = c.id +1)
	) 
ORDER BY a.id

