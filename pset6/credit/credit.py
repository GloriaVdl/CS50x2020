# Program that prompts the user for a credit card number and reports which type it is.
# Author: Gloria Videloup
# CS50x2020

from cs50 import get_int
from math import floor


def main():
    # Let us initialize our variables
    digit1 = 0
    digit2 = 0
    num_digits = 0
    sum_of_double_odds = 0
    sum_of_evens = 0

    # Prompt the user for the credit card number
    card_number = get_int("Number: ")

    while card_number > 0:
        digit2 = digit1
        digit1 = card_number % 10

        if num_digits % 2 == 0:
            sum_of_evens += digit1
        else:
            multiple = 2 * digit1
            sum_of_double_odds += (multiple // 10) + (multiple % 10)

        card_number //= 10
        num_digits += 1

    is_valid = (sum_of_evens + sum_of_double_odds) % 10 == 0
    # Let us analyze the first two digits
    first_two_digits = (digit1 * 10) + digit2

    # If the digits are valid, print the name of the Credit card.
    if digit1 == 4 and num_digits >= 13 and num_digits <= 16 and is_valid:
        print("VISA\n")
    elif first_two_digits >= 51 and first_two_digits <= 55 and num_digits == 16 and is_valid:
        print("MASTERCARD\n")
    elif (first_two_digits == 34 or first_two_digits == 37) and num_digits == 15 and is_valid:
        print("AMEX\n")
    # Otherwise print an error message
    else:
        print("INVALID\n")


if __name__ == "__main__":
    main()
