from cs50 import SQL
import csv
import sys

db = SQL("sqlite:///students.db")

def main():
    if len(sys.argv) != 2:
        print("Usage: python import.py database.db")
    with open (sys.argv[1],"r") as studs:
        reader = csv.DictReader(studs)
        for row in reader:
            splitnames = row["name"].split(" ")
            if len(splitnames) == 2:
                db.execute("INSERT INTO students (first,last,house,birth) VALUES(?, ?, ?, ?)", splitnames[0], splitnames[1],row["house"],row["birth"])
            if len(splitnames) == 3:
                db.execute("INSERT INTO students (first,middle,last,house,birth) VALUES(?, ?, ?, ?, ?)", splitnames[0], splitnames[1],splitnames[2],row["house"],row["birth"])

if(__name__) == "__main__":
    main()