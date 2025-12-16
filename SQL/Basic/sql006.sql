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
