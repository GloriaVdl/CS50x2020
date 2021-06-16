#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


//First we declare the variables
int letter;
int word;
int sentence;


int main(void)
{

//We prompt the user for the Text.

    string article = get_string("Text: ");

//We then analyze the lenght of the text.

    int n = strlen(article);

// We add +1 if the article starts with an alphanumeric character.

    if (isalnum(article[0]))
    {
        word = 1;
    }

// We count the words.

    for (int i = 0; i < strlen(article);  i++)
    {
        //Then we establish the condition that counts letters

        if ((article[i] >= 'a' && article[i] <= 'z') || (article[i] >= 'A' && article[i] <= 'Z'))
        {
            letter++;
        }

        //We count the words formed with the letters.

        else if (article[i] == ' ')
        {
            word++;
        }

        //Then we count sentences.

        if (i > 0 && (article[i] == '!' || article[i] == '?' || article[i] == '.') && isalnum(article[i - 1]))
        {
            sentence++;
        }

    }

// We then integrate the Coleman-Liau index with a float, whilst minding our parameters.

    float grade = 0.0588 * (100 * (float)letter / (float)word) - 0.296 * (100 * (float)sentence / (float)word) - 15.8;


// And we print the result with an if,else if, else loop.
    if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade < 16)
    {
        printf("Grade %.i\n", (int) round(grade));
    }
    else
    {
        printf("Grade 16+\n");
    }
}