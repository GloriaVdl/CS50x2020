# Program that evaluates the grade level of a text
# Author: Gloria Videloup
# CS50x2020

from cs50 import get_string
# Let us initialize the variables
letter = 0
sentence = 0
word = 1
# Let us get input from the user
text = get_string("Text: ")
# Let us get the lenght of the text
n = len(text)
# Let us put conditions
for i in range(n):
    if text[i].isalnum() == True:
        letter = letter + 1
for i in range(n):
    if text[i].isspace() and text[i + 1].isalnum() == True:
        word = word + 1
for i in range(n):
    if text[i] == "?" or text[i] == "." or text[i] == "!" or text[i] == ":":
        sentence = sentence + 1
# Coleman-Liau index formula : 0.0588 * L - 0.296 * S - 15.8
grade = (0.0588 * ((100 * letter) / word) - 0.296 * ((100 * sentence) / word) - 15.8)
# Finally let us verify the correctness of the grade.
if grade < 1:
    print("Before Grade 1")
elif grade < 16:
    print(f"Grade {round(grade)}")
else:
    print("Grade 16+")
