/*
* Author: Gloria Videloup
* CS50x2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//This is a copy paste of a boolean expression used to validate the key.
bool validate(string key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        //We declare our string.
        string key = argv[1];

        //And run a condition to validate the key. It will be true, if :
        if (validate(key) == true)
        {

            string plaintext = get_string("plaintext: ");
            int charcount = strlen(plaintext);
            char ciphertext[charcount];

            //We decladre the string Alphabet
            string alphabet = "abcdefghijklmnopqrstuvwxyz";

            //We add a for loop that verifies the existence of the uppercases and lowercases.
            for (int i = 0; i < charcount; i++)
            {
                //We verify that the plaintext is uppercases and unequal to zero
                if (isupper(plaintext[i]) != 0)
                {
                    //And run a "for loop" for both.
                    for (int j = 0; j < 26; j++)
                    {
                        if (alphabet[j] == tolower(plaintext[i]))
                        {
                            ciphertext[i] = toupper(key[j]);
                            break;
                        }
                    }
                }
                //We verify that the plaintext is lowercases and unequal do zero
                else if (islower(plaintext[i]) != 0)
                {
                    //We add another "for loop"
                    for (int j = 0; j < 26; j++)
                    {
                        if (alphabet[j] == plaintext[i])
                        {
                            ciphertext[i] = tolower(key[j]);
                            break;
                        }
                    }
                }
                else
                {
                    ciphertext[i] = plaintext[i];
                }

            }
            printf("ciphertext: %s\n", ciphertext);
            return 0;
        }

        //If the key isn't valid, we should prompt an error message.
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }

    //Same thing if the user doesn't type a key at all
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

//Then we add a boolean expression which will validate the key string by verifying if the conditions are met.
bool validate(string key)
{
    int matches = 0;
    if (strlen(key) == 26)
    {
        for (char c = 'a'; c <= 'z'; c++)
        {
            for (int i = 0; i < 26; i++)
            {
                if (tolower(key[i]) == c)
                {
                    matches++;
                    break;
                }
            }
        }
        if (matches == 26)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
