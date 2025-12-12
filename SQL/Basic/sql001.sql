--TABLE 생성
CREATE TABLE "Person" (
	"ID"	INTEGER NOT NULL,
	"Name"	TEXT NOT NULL,
	"Birthday"	TEXT,
	PRIMARY KEY("ID" AUTOINCREMENT)
);

--데이터 삽입
INSERT INTO Person (ID, Name, Birthday)
VALUES (1, '이혜리', '1994-06-09');

INSERT INTO Person
VALUES (1, '이혜리', '1994-06-09');

INSERT INTO Person
VALUES (2, '강호동', '2000-08-08');

--데이터 조회
SELECT * FROM Person;

INSERT INTO Person (ID, Name, Birthday)
VALUES (3, '유재석', '1999-01-01');

SELECT * FROM Person;

SELECT Name, ID FROM Person;

SELECT ID, Birthday FROM Person;

SELECT Name, Birthday FROM Person;

SELECT Name, Birthday FROM Person
ORDER BY Name ASC;

SELECT Name, Birthday FROM Person
ORDER BY Name DESC;

SELECT Name, Birthday FROM Person
ORDER BY Birthday;

--데이터 삭제

DELETE FROM Person
WHERE ID = 1;

--WHERE 없이 하면 모든 테이블의 데이터 삭제

SELECT * FROM Person

DELETE FROM Person;

SELECT * FROM Person;

INSERT INTO Person
VALUES (1, '이혜리', '1994-06-09');

INSERT INTO Person
VALUES (2, '강호동', '2000-08-08');

INSERT INTO Person (ID, Name, Birthday)
VALUES (3, '유재석', '1999-01-01');

SELECT * FROM Person;

--데이터 수정

UPDATE Person SET Name = '김해리'
WHERE Name = '이해리';

SELECT * FROM Person
