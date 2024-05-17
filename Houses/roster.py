from cs50 import SQL
import sys

db = SQL("sqlite:///students.db")

def main():
    if len(sys.argv) != 2:
        sys.exit("Usage: python import.py house")
    studlist = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last,first",sys.argv[1])
    s = " "
    c = ", born "
    for row in studlist:
        if not row["middle"]:
            print(row["first"]+s+row["last"]+c+str(row["birth"]))
        else:
            print(row["first"]+s+row["middle"]+s+row["last"]+c+str(row["birth"]))

if(__name__) == "__main__":
    main()