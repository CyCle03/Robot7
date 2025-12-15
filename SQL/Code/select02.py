import sqlite3

path = '/mnt/c/Users/User/databases/'
db_file = path + "test3.db"

conn = sqlite3.connect(db_file)
conn.row_factory = sqlite3.Row
cur = conn.cursor()

cur.execute("SELECT id, name, pnumber FROM person;")

for row in cur:
    print(row["id"], row["name"], row["pnumber"])

conn.close()

