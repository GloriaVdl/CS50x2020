# Program that prints Mario's pyramid with a space in the middle
# Author: Gloria Videloup
# CS50x2020

from cs50 import get_int

def main():
    while True:
        # Prompt the user to type the pyramid's height
        height = get_int("Height: ")
        width = height
        # Verify if the height is correct (positive number) otherwise break
        if height >= 0 and height <= 23:
            break

    for i in range(1, height + 1):
        num_hashes = i
        num_spaces = width - num_hashes
        # Start building the pyramid
        print(" " * num_spaces, end="")
        print("#" * num_hashes, end="")

        print("  ", end="")

        print("#" * num_hashes)


if __name__ == "__main__":
    main()
