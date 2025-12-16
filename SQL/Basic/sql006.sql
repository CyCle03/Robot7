DROP TABLE Person;

CREATE TABLE "Person" (
    "ID"    INTEGER NOT NULL,
    "Name"  TEXT NOT NULL,
    "Birthday"  TEXT,
    "Height"    INTEGER,
    "Weight"    INTEGER,
    PRIMARY KEY("ID" AUTOINCREMENT)
);

INSERT INTO Person VALUES
    (1, '혜리', '1994-06-09', NULL, 50),
    (2, '소진', '1986-05-21', 167, NULL),
    (3, '유라', '1992-11-06', 170.3, 54),
    (4, '민아', NULL, 164, 46);
    
SELECT * FROM Person;

SELECT Name, Birthday FROM Person;

SELECT Name AS "이름", Birthday AS "생일" FROM Person;

SELECT ID AS "아이디", Name AS "이름", Birthday AS "생일" FROM Person;

SELECT ID "아이디", Name "이름", Birthday "생일" FROM Person;

SELECT
	Name,
	Height,
	weight
FROM Person;

SELECT
	Name,
	Height,
	weight,
	weight / (Height * Height * 0.0001)
FROM Person;

SELECT
	Name,
	Height,
	weight,
	round(weight / (Height * Height * 0.0001), 2)
FROM Person;

SELECT
	Name,
	Height,
	weight,
	round(weight / (Height * Height * 0.0001), 2) AS BMI
FROM Person;

SELECT
	Name,
	Height,
	weight,
	round(weight / (Height * Height * 0.0001), 2) BMI
FROM Person;

SELECT
	Name AS "이름",
	Height AS "키",
	weight AS "몸무게",
	round(weight / (Height * Height * 0.0001), 2) AS BMI
FROM Person;

UPDATE Person SET Height=163 WHERE ID=1;
SELECT * FROM Person;

SELECT Height - 110 AS "적정몸무게" FROM Person;

SELECT 
	Name AS "이름",
	Height AS "키",
	Weight AS "몸무게",
	Height - 110 AS "적정몸무게"
FROM Person;

SELECT 
	substr('201225-1234567', 3, 4) AS "생일",
	substr('201225-1234567', 1, 2) AS "태어난 년도";

SELECT 
	Name,
	Birthday AS bdate,
	substr(Birthday, 1, 4) AS "YYYY",
	substr(Birthday, 6, 2) AS "MM",
	substr(Birthday, 9, 2) AS "DD"
FROM Person;

CREATE VIEW BirthdayView
AS
SELECT 
	Name,
	Birthday AS bdate,
	substr(Birthday, 1, 4) AS "YYYY",
	substr(Birthday, 6, 2) AS "MM",
	substr(Birthday, 9, 2) AS "DD"
FROM Person;

SELECT * FROM BirthdayView;

DROP VIEW BirthdayView;

CREATE VIEW ShowBMI
AS
SELECT 
	Name AS "이름",
	Height AS "키",
	Weight AS "몸무게",
	Height - 110 AS "적정몸무게"
FROM Person;

SELECT * FROM ShowBMI;

SELECT
    Name,
    bdate,
    MM,
    CASE
        WHEN MM = '01' THEN 'Jan.'
        WHEN MM = '02' THEN 'Feb.'
        WHEN MM = '03' THEN 'Mar.'
        WHEN MM = '04' THEN 'Apr.'
        WHEN MM = '05' THEN 'May.'
        WHEN MM = '06' THEN 'Jun.'
        WHEN MM = '07' THEN 'Jul.'      
        WHEN MM = '08' THEN 'Aug.'
        WHEN MM = '09' THEN 'Sep.'
        WHEN MM = '10' THEN 'Oct.'
        WHEN MM = '11' THEN 'Nov.'
        WHEN MM = '12' THEN 'Dec.'
    END Month
FROM BirthdayView;

SELECT
    Name,
    bdate,
    MM,
    CASE
        WHEN MM='01' THEN '1월'
		WHEN MM='02' THEN '2월'
		WHEN MM='03' THEN '3월'
		WHEN MM='04' THEN '4월'
		WHEN MM='05' THEN '5월'
		WHEN MM='06' THEN '6월'
		WHEN MM='07' THEN '7월'
		WHEN MM='08' THEN '8월'
		WHEN MM='09' THEN '9월'
		WHEN MM='10' THEN '10월'
		WHEN MM='11' THEN '11월'
		WHEN MM='12' THEN '12월'
    END AS '월'
FROM BirthdayView;

SELECT strftime('%Y-%m-%d %H:%M:%S', 'now', 'localtime') 현지시간;

SELECT strftime('%m/%d %H:%M', 'now', 'localtime') 현지시간;

SELECT 
	Name,
	Birthday AS 생일,
	strftime('%Y', 'now') - substr(Birthday, 1, 4) - 
	(strftime('%m-%d', 'now') < substr(Birthday, 6)) AS 만나이
FROM Person;

SELECT
	Name,
	Birthday,
	(CAST(strftime('%Y', 'now') AS INTEGER) -
	CAST(substr(Birthday, 1, 4) AS INTEGER)) AS '만나이'
FROM Person;

SELECT Height FROM Person;

SELECT count(Height) FROM Person;
SELECT max(Height) FROM Person;
SELECT min(Height) FROM Person;
SELECT avg(Height) FROM Person;
SELECT sum(Height) FROM Person;

SELECT
	count(Height), max(Height),
	min(Height), avg(Height), sum(Height)
FROM Person;
