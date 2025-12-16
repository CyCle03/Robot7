import sqlite3

dbPath = "/mnt/c/Users/User/databases/addressbook.db"


class Person:
    def __init__(self, id=None, name="", pnumber=""):
        self.id = id
        self.name = name
        self.pnumber = pnumber

    def __str__(self):
        return f"Person(id={self.id}, name={self.name}, pnumber={self.pnumber})"


class PersonRepository:
    def __init__(self, dbPath: str):
        self.dbPath = dbPath

    def getConnection(self):
        return sqlite3.connect(self.dbPath)

    def createTable(self):
        conn = self.getConnection()
        cur = conn.cursor()

        sql = """
        CREATE TABLE IF NOT EXISTS Person (
            ID INTEGER PRIMARY KEY AUTOINCREMENT,
            Name TEXT NOT NULL,
            Pnumber TEXT NOT NULL
        );
        """

        cur.execute(sql)
        conn.commit()
        conn.close()

    def insert(self, person: Person):
        conn = self.getConnection()
        cur = conn.cursor()

        sql = """
        INSERT INTO Person (Name, Pnumber)
        VALUES (?, ?);
        """

        cur.execute(sql, (person.name, person.pnumber))
        conn.commit()

        person.id = cur.lastrowid
        conn.close()

    def findAll(self):
        conn = self.getConnection()
        cur = conn.cursor()

        sql = "SELECT ID, Name, Pnumber FROM Person ORDER BY ID;"
        cur.execute(sql)

        persons = []
        for row in cur:  # (ID, Name, Pnumber)
            persons.append(Person(row[0], row[1], row[2]))

        conn.close()
        return persons
    
    def findID(self, id):
        conn = self.getConnection()
        cur = conn.cursor()

        sql = "SELECT ID, Name, Pnumber FROM Person WHERE ID = ?;"
        cur.execute(sql, (id,))

        row = cur.fetchone()

        conn.close()
        if row:
            return Person(row[0], row[1], row[2])
        return None
    
    def update(self, person: Person):
        conn = self.getConnection()
        cur = conn.cursor()

        sql = """
        Update Person SET Name = (?), Pnumber = (?) WHERE ID = (?);
        """

        cur.execute(sql, (person.name, person.pnumber, person.id))
        conn.commit()

        conn.close()

    def delete(self, id):
        conn = self.getConnection()
        cur = conn.cursor()

        sql = """
        Delete FROM Person WHERE ID = (?);
        """

        cur.execute(sql, (id,))
        conn.commit()

        conn.close()


def main():
    repo = PersonRepository(dbPath)
    repo.createTable()

    while True:
        print("\n=== Person Address Book ===")
        print("1. 사람 추가")
        print("2. 전체 조회")
        print("3. 수정")
        print("4. 삭제")
        print("0. 종료")

        choice = input("선택: ").strip()

        match choice:
            case "1":
                name = input("이름: ").strip()
                pnumber = input("전화번호: ").strip()

                person = Person(name=name, pnumber=pnumber)
                repo.insert(person)

                print("저장 완료:", person)

            case "2":
                persons = repo.findAll()
                print("\n--- 전체 목록 ---")
                for p in persons:
                    print(p)
            
            case "3":
                print("입력된 정보 수정")
                id = input("수정할 ID: ").strip()

                person = repo.findID(id)
                if not person:
                    print("잘못 입력된 아이디 입니다.")
                    continue

                name = input("수정할 이름: ").strip()
                pnumber = input("수정할 전화번호: ").strip()
                person = Person(id = id, name = name, pnumber = pnumber)
                repo.update(person)

                print("수정 완료", person)

            case "4":
                print("입력된 정보 삭제")
                id = input("삭제할 ID: ").strip()

                repo.delete(id)

            case "0":
                print("프로그램 종료")
                break

            case _:
                print("잘못된 입력입니다.")


if __name__ == "__main__":
    main()
