# Program that prompts a list of students for a given house in alphabetical order
# Author: Gloria Videloup
# CS50x2020

from cs50 import SQL
from sys import argv

# Let us check for errors
if len(argv) < 2:
    print("Usage error, roster.py houseName")
    exit()

# Now let's look into the database and query the list of people from a given house (which we don't know yet)
db = SQL("sqlite:///students.db")
students = db.execute("SELECT * FROM students WHERE house = (?) ORDER BY last", argv[1])

# Once this is done we print each person whilst respecting the established order
for student in students:
    # If the student has NO middle name, we print the following:
    if student['middle'] != None:
        print(f"{student['first']} {student['middle']} {student['last']}, born {student['birth']}")
    # Otherwise :
    else:
        print(f"{student['first']} {student['last']}, born {student['birth']}")
