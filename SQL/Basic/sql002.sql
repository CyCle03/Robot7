CREATE TABLE "Addressbook"(
	"ID" INTEGER NOT NULL,
	"Name" TEXT,
	"Pnumber" TEXT,
	PRIMARY KEY("ID" AUTOINCREMENT)
);

INSERT INTO Addressbook
VALUES (10, '홍길동', '010-1111-1111'),
(20, '이순신', '010-2222-2222'),
(30, '강감찬', '010-3333-3333');

SELECT * FROM Addressbook

UPDATE Addressbook SET ID = 50, Name = '김길동'
WHERE Name = '홍길동';

SELECT * FROM Addressbook

DELETE FROM Addressbook
WHERE ID = 30;

SELECT * FROM Addressbook
