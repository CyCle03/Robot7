CREATE TABLE "Person" (
	"ID"	INTEGER NOT NULL,
	"Name"	TEXT NOT NULL,
	"Birthday"	TEXT,
	PRIMARY KEY("ID" AUTOINCREMENT)
);

CREATE TABLE "Student" (
	"SN"	INTEGER NOT NULL,
	"NAME"	TEXT NOT NULL,
	"ADDRESS"	TEXT NOT NULL,
	PRIMARY KEY("SN" AUTOINCREMENT)
);

INSERT INTO Person (Name, Birthday)
VALUES ('유재석', '1970-01-01')

SELECT * FROM Person

SELECT ID, name FROM Person

INSERT INTO Person (Name, Birthday)
VALUES ('강호동', '1965-12-01');

INSERT INTO Person (Name, Birthday)
VALUES ('신동엽', '1960-09-30');

SELECT * FROM Person

SELECT name FROM Person

SELECT Name FROM Person ORDER BY Name;

SELECT Name FROM Person ORDER BY Name DESC;

select * from Person;

UPDATE Person SET Name = '강감찬' WHERE ID=2;

SELECT * FROM Person

DELETE FROM Person WHERE Name='신동엽';

SELECT * FROM Person;
