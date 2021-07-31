# Program that prints half of Mario's pyramid
# Author: Gloria Videloup
# CS50x2020

from cs50 import get_int

while True:
    # Prompt the user for the pyramid's height
    height = get_int("height:")
    width = height
# Needs to be a positive integer between 1 and 8
# If it's smaller or equal to 0, reprompt.
    if height <= 0:
        height = get_int("height:")
    # If it's true, generate the pyramid
    elif height < 9:
        for i in range(height):
            num_hashes = i + 1
            num_spaces = width - num_hashes

            print(" " * num_spaces, end="")
            print("#" * num_hashes)
        break
