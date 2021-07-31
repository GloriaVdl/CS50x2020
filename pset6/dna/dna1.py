# Program that reads DNA sequences

# DNA name types, AGAT, AATG, TATG

# The program should require the name of a CSV file containing the STR counts for a list of individuals and should require as its
# second command-line argument the name of a text file containing the DNA sequence.
# So something such as : "python dna.py databases/large.csv sequences/5.txt"
# Author: Gloria Videloup
# CS50x2020


from csv import reader, DictReader
from sys import argv

# Let us define a standard error message in case of bad use
if len(argv) < 3:
    print("Usage: python dna.py data.csv sequence.txt\n")
    exit()

# Let us open the file and read inside it

with open(argv[2]) as dnafile:
    dnareader = reader(dnafile)
    for row in dnareader:
        dnalist = row

# Let us store the information in a string

dna = dnalist[0]
# And let's create a dictionary in which the sequences will be counted
sequences = {}

# Take the sequences and add them to a list
with open(argv[1]) as peoplefile:
    people = reader(peoplefile)
    for row in people:
        dnaSequences = row
        dnaSequences.pop(0)
        break

# Then we take the list and copy it into a dictionary that contains the genes as keys
for item in dnaSequences:
    sequences[item] = 1

# Search through the sequence : if there are repetitions, count them
for key in sequences:
    L = len(key)
    tempMax = 0
    temp = 0
    for i in range (len(dna)):
        # after counting, skip to the end and avoid counting twice
        while temp > 0:
            temp -= 1
            continue

        # Otherwise count again
        if dna[i: i + L] == key:
            while dna[i - L: i] == dna[i: i + L]:
                temp += 1
                i += L
            # We compare the value to the previous longest sequence and override it if it's longer
            if temp > tempMax:
                tempMax = temp

    # Finally we store the sequence in the Dictionary by using the right key
    sequences[key] += tempMax

with open(argv[1], newline='') as peoplefile:
    people = DictReader(peoplefile)
    for person in people:
        match = 0
        # compares the sequences to every person and prints name before leaving the program if there is a match
        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                match += 1

        if match == len(sequences):
            print(person['name'])
            exit()

    print("No match")
