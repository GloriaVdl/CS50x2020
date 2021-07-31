# Program that says how many coins should be used to give back change.
# Author: Gloria Videloup
# CS50x2020


from cs50 import get_float
from math import floor


def main():
    while True:
        # Prompt the user with the amount owed
        dollars_owed = get_float("Change owed: ")
        cents_owed = floor(dollars_owed * 100)
        # If it doesn't correspond to a valid number, break
        if cents_owed > 0:
            break
    # Otherwise, let's apply the calculations
    quarters = cents_owed // 25
    dimes = (cents_owed % 25) // 10
    nickels = ((cents_owed % 25) % 10) // 5
    pennies = ((cents_owed % 25) % 10) % 5
    # And print it back to the user
    print(f"{quarters + dimes + nickels + pennies}")


if __name__ == "__main__":
    main()

