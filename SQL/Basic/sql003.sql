INSERT INTO Person (Name, Birthday)
VALUES ('박소진', '1986-05-21'), ('김아영', '1992-11-06');

INSERT INTO Person (Name) VALUES ('민아');

SELECT Name FROM Person;

SELECT Name FROM Person ORDER BY Name;

SELECT * FROM Person ORDER BY Name;

SELECT * FROM Person
WHERE Birthday IS NOT NULL

UPDATE Person SET Name = '소진' WHERE Name = '박소진';

SELECT * FROM Person WHERE Birthday LIKE '1986%';
