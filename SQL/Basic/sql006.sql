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
