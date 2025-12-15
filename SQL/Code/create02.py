import sqlite3

#1. 연결객체를 만들어라. DBMS회사가 driver와 api를 제공한다.
# Server/Client -- FTP(web hard)/Message Service/Mail...

path = '/mnt/c/Users/User/databases/'
conn = sqlite3.connect(path + 'test3.db')
cur = conn.cursor() #SQL 사용 가능한 객체

#SQL 실행
query = '''
CREATE TABLE "Person" (
	"ID"	INTEGER NOT NULL,
	"Name"	TEXT NOT NULL,
	"Pnumber"	TEXT NOT NULL,
	PRIMARY KEY("ID" AUTOINCREMENT)
);
'''

cur.execute(query)

#SQLite는 commit을 연결객체에서 한다.
conn.commit() #save 단, save 후에는 변경 불가.
conn.close()

print('person 테이블이 생성되었습니다.')
