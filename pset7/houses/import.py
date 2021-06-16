# Program that imports data from a csv file
from cs50 import SQL
from csv import reader
from sys import argv

# First let us open the database in a variable which we will use later
db = SQL("sqlite:///students.db")

# Let us check for errors. Otherwise let's prompt an error message
if len(argv) < 2:
    print("Usage error, import.py characters.csv")
    exit()

# Let us open the CSV file and copy its content to a list
with open(argv[1], newline='') as charactersFile:
    characters = reader(charactersFile)
    for character in characters:
        if character[0] == 'name':
            # We use continue to avoid unlimited indentation
            continue

        # Let us split the full name into the first last and middle name if there is one
        fullName = character[0].split()

        # Then we instert the name in the database which will not show a middle name if there isn't one
        if len(fullName) < 3:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?,?,?,?,?)", fullName[0], None, fullName[1], character[1], character[2])

        else:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?,?,?,?,?)", fullName[0], fullName[1], fullName[2], character[1], character[2])