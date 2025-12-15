CREATE TABLE "Ramyeon"(
	"product_id"	INTEGER NOT NULL,
	"product_name"	TEXT NOT NULL,
	"date"			TEXT,
	"price"			INTEGER NOT NULL,
	"company"		TEXT NOT NULL,
	"weight"		INTEGER,
	"factory"		TEXT,
	PRIMARY KEY("product_id" AUTOINCREMENT)
);
SELECT * FROM Ramyeon;

INSERT INTO Ramyeon(product_name, price, company)
VALUES ("진라면", 800, "오뚜기");
INSERT INTO Ramyeon(product_name, price, company)
VALUES ("신라면", 1200, "농심");
INSERT INTO Ramyeon(product_name, price, company)
VALUES ("삼양라면", 1000, "삼양");

SELECT * FROM Ramyeon;

UPDATE Ramyeon SET date = "2025-12-15" WHERE product_id = 2;
SELECT * FROM Ramyeon;

SELECT 1;
SELECT '안녕하세요';
SELECT 2 * 3;
SELECT date('now');
