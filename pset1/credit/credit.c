/* 
* Author: Gloria Videloup 
* CS50x2020
*/

#include <stdio.h>
#include <cs50.h>

int dcount(long dcount);

int main(void)
{
    //First we declare our variables.

    long card = get_long("Number: ");
    long count = card;
    int digit;
    int array[17];
    int i = dcount(count);

    //We create a first for loop that will establish the correctness of the calculations.
    for (int a = i; a > 0; a--)
    {
        digit = card % 10;
        card = card / 10;
        array[a] = digit;
    }

    //We create a validation process
    if (i < 17 && i > 12)
    {
        //We declare the variables we are going to use
        int sum;
        int sumsum;
        int mod;
        int modsum;

        //We add a for loop to validate the different conditions
        for (int even = i; even > 0; even--)
        {
            //If the number is a 13 or 15 digit number, we validate.
            if (i == 13 || i == 15)
            {
                if (even % 2 == 0)
                {
                    sum = array[even] * 2;
                    while (sum > 0)
                    {
                        //We establish a singular condition through which the program should work
                        mod = sum % 10;
                        modsum = modsum + mod;
                        sum = sum / 10;

                    }
                }
                if (even % 2 != 0)
                {
                    sum = array[even];
                    while (sum > 0)
                    {
                        //We establish another singular condition which set the parameters.
                        sumsum = sumsum + sum;
                        sum = sum / 10;
                    }
                }
            }
            //If we have a 16 digit number, we validate.
            else
            {
                if (even % 2 != 0)
                {
                    sum = array[even] * 2;
                    while (sum > 0)
                    {
                        //same as line 56 is done here
                        mod = sum % 10;
                        modsum = modsum + mod;
                        sum = sum / 10;

                    }
                }
                if (even % 2 == 0)
                {
                    sum = array[even];
                    while (sum > 0)
                    {
                        //same as line 56 and 70 is done here
                        sumsum = sumsum + sum;
                        sum = sum / 10;
                    }
                }
            }
        }
        //Here we verify that the conditions are met to prompt the valid kind of card to the user.
        int valid = modsum + sumsum;

        valid = valid % 10;

        //if the first character of the array is 4, we prompt VISA.
        if (valid == 0 && array[1] == 4)
        {
            printf("VISA\n");
        }
        //otherwise, if the first character of the array is 3 and the second character is 4 or 7, we prompt AMEX.
        else if (valid == 0 && array[1] == 3 && (array[2] == 4 || array[2] == 7))
        {
            printf("AMEX\n");
        }
        //In another case, if the first character of the array is 5 and the second character is 1, or 2, or 3, or 4, or 5, we prompt MASTERCARD.
        else if (valid == 0 && array[1] == 5 && (array[2] == 1 || array[2] == 2 || array[2] == 3 || array[2] == 4 || array[2] == 5))
        {
            printf("MASTERCARD\n");
        }
        //And if the digit doesn't match the requirements, we consider it invalid input.
        else
        {
            printf("INVALID\n");
        }
    }
    //If we don't meet the conditions, we prompt INVALID to the user.
    else
    {
        printf("INVALID\n");
    }
}


//In this final part we count how many digits are present.
int dcount(long dcount)
{
    int c = 0;
    if (dcount > 0)
    {
        while (dcount > 0)
        {
            dcount = dcount / 10;
            c++;
        }
        //If the requirements are met, we continue.
        return c;
    }
    //Otherwise, we stop.
    else
    {
        return false;
    }
}
