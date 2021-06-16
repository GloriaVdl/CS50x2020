#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage ./caesar key\n");
        return 1;
    }

    //We declare the key.
    int key = atoi(argv[1]);

    //We make sure the key is a positive integer.
    if (key < 0)
    {
        printf("Key must be positive.\n");
        return 1;
    }

    //We declare the string.
    string plaintext = get_string("Plaintext: ");
    printf("ciphertext:");

//Let's not forget the Formula : C = (plaintext[i] -'a'+ key) % 26 + a

    //Let's declare the variable that will represent the result of our formula.
    int C;
    //We verify the plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        //If it's lowercase, then prompt it as lowercase to the user.
        if (islower(plaintext[i]))
        {
            printf("%c", C = (plaintext[i] - 'a' + key) % 26 + 'a');
        }
        //If it's uppercase, then prompt it as an uppercase to the user.
        else if (isupper(plaintext[i]))
        {
            printf("%c", C = (plaintext[i] - 'A' + key) % 26 + 'A');
        }

        else
        {
            printf("%c", plaintext[i]);
        }


    }
    printf("\n");
    return 0;
}
