-- 262. 行程和用户
-- SQL架构
CREATE TABLE IF NOT EXISTS Trips (
	Id INT, 
	Client_Id INT, 
	Driver_Id INT, 
	City_Id INT, 
	STATUS ENUM('completed', 'cancelled_by_driver', 'cancelled_by_client'), 
	Request_at VARCHAR(50)
);
CREATE TABLE IF NOT EXISTS trips (
	Users_Id INT, 
	Banned VARCHAR(50), 
	Role ENUM('client', 'driver', 'partner')
);
TRUNCATE TABLE Trips;
INSERT INTO Trips (Id, Client_Id, Driver_Id, City_Id, STATUS, Request_at) VALUES ('1', '1', '10', '1', 'completed', '2013-10-01');
INSERT INTO Trips (Id, Client_Id, Driver_Id, City_Id, STATUS, Request_at) VALUES ('2', '2', '11', '1', 'cancelled_by_driver', '2013-10-01');
INSERT INTO Trips (Id, Client_Id, Driver_Id, City_Id, STATUS, Request_at) VALUES ('3', '3', '12', '6', 'completed', '2013-10-01');
INSERT INTO Trips (Id, Client_Id, Driver_Id, City_Id, STATUS, Request_at) VALUES ('4', '4', '13', '6', 'cancelled_by_client', '2013-10-01');
INSERT INTO Trips (Id, Client_Id, Driver_Id, City_Id, STATUS, Request_at) VALUES ('5', '1', '10', '1', 'completed', '2013-10-02');
INSERT INTO Trips (Id, Client_Id, Driver_Id, City_Id, STATUS, Request_at) VALUES ('6', '2', '11', '6', 'completed', '2013-10-02');
INSERT INTO Trips (Id, Client_Id, Driver_Id, City_Id, STATUS, Request_at) VALUES ('7', '3', '12', '6', 'completed', '2013-10-02');
INSERT INTO Trips (Id, Client_Id, Driver_Id, City_Id, STATUS, Request_at) VALUES ('8', '2', '12', '12', 'completed', '2013-10-03');
INSERT INTO Trips (Id, Client_Id, Driver_Id, City_Id, STATUS, Request_at) VALUES ('9', '3', '10', '12', 'completed', '2013-10-03');
INSERT INTO Trips (Id, Client_Id, Driver_Id, City_Id, STATUS, Request_at) VALUES ('10', '4', '13', '12', 'cancelled_by_driver', '2013-10-03');
TRUNCATE TABLE Users;
INSERT INTO Users (Users_Id, Banned, Role) VALUES ('1', 'No', 'client');
INSERT INTO Users (Users_Id, Banned, Role) VALUES ('2', 'Yes', 'client');
INSERT INTO Users (Users_Id, Banned, Role) VALUES ('3', 'No', 'client');
INSERT INTO Users (Users_Id, Banned, Role) VALUES ('4', 'No', 'client');
INSERT INTO Users (Users_Id, Banned, Role) VALUES ('10', 'No', 'driver');
INSERT INTO Users (Users_Id, Banned, Role) VALUES ('11', 'No', 'driver');
INSERT INTO Users (Users_Id, Banned, Role) VALUES ('12', 'No', 'driver');
-- 查出 2013年10月1日 至 2013年10月3日 期间
-- 非禁止用户的取消率。
-- 取消率（Cancellation Rate）保留两位小数。

-- 非禁止用户在2013年10月1日 至 2013年10月3日 期间的使用情况
SELECT sss1.day,FORMAT (IFNULL(sss2.sum2,0)/sss1.sum1,2 )  CancellationRate
FROM(
SELECT p.Day,COUNT(p.day) AS SUM1
FROM (SELECT t.status st,t.request_at DAY 
	FROM trips t , users u 
	WHERE t.client_id = u.users_id 
		AND  u.banned ='no') p
GROUP BY p.day) sss1 LEFT JOIN 
(SELECT p.Day,COUNT(p.st) AS SUM2
FROM (SELECT t.status st,t.request_at DAY 
	FROM trips t , users u 
	WHERE t.client_id = u.users_id 
		AND  u.banned ='no') p
WHERE p.st!='completed'
GROUP BY p.day,p.st) sss2
ON sss1.day=sss2.day
-- 题目好像有人问题

	