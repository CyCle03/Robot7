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

SELECT * FROM Person WHERE Birthday LIKE '1970%';

SELECT * FROM Person WHERE Name LIKE '강%';

SELECT * FROM Person WHERE Name LIKE '%찬%';

SELECT * FROM Person WHERE Name LIKE '%찬';

INSERT INTO Person (Name, Birthday) VALUES ('지선', '1989-10-17');
SELECT * FROM Person;

INSERT INTO Person (Name, Birthday) VALUES ('지선', '1989-10-17');
INSERT INTO Person (Name, Birthday) VALUES ('지인', '1992-3-13');
SELECT * FROM Person;

ALTER TABLE Person ADD COLUMN New INTEGER;

SELECT * FROM Person;

PRAGMA table_info(person); --SQLite
DESC Person;

UPDATE Person SET New = 175 WHERE ID = 1;
UPDATE Person SET NEW = 160 WHERE Name = '지선';
SELECT * FROM Person;

UPDATE Person SET New = 164 WHERE Birthday like '1992%';
UPDATE Person SET NEW = 180 WHERE Name = '강감찬';
SELECT * FROM Person;

ALTER TABLE Person RENAME COLUMN New TO Height;
SELECT * FROM Person;
SELECT name FROM Person

SELECT Name FROM Person ORDER BY Name;

SELECT Name FROM Person ORDER BY Name DESC;

select * from Person;

UPDATE Person SET Name = '강감찬' WHERE ID=2;

SELECT * FROM Person

DELETE FROM Person WHERE Name='신동엽';

SELECT * FROM Person;

