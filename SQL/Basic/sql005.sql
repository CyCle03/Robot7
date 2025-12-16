CREATE TABLE "pets" (
	"ID"	INTEGER NOT NULL,
	"Name"	TEXT NOT NULL,
	"Animal"	TEXT NOT NULL,
	PRIMARY KEY("ID")
);

Insert Into pets (Name, Animal)
VALUES ('뽀삐', '강아지'), ('나나', '고양이'), ('푸우', '곰');
SELECT * FROM pets;

SELECT * FROM pets
ORDER BY ID DESC;

SELECT * FROM pets ORDER BY Name;

DESC pets;
PRAGMA table_info(pets);

INSERT INTO pets (Name, Animal) VALUES ('후우', '곰');
SELECT * FROM pets;

DELETE FROM pets WHERE Name='후우';
SELECT * FROM pets;

UPDATE pets SET Name='푸푸'
WHERE ID=3;
SELECT * FROM pets;

DELETE FROM pets;
SELECT * FROM pets;

DELETE FROM pets WHERE ID IS NOT NULL;

INSERT INTO pets (Name, Animal)
VALUES ('DR. Harris Bonkers', 'Rabbit'), ('Moon', 'Dog'),
('Ripley', 'Cat'), ('Tom', 'Cat');
SELECT * FROM pets;

DROP TABLE pets;
