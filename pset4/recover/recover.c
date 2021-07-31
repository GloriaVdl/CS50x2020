/*
* Author: Gloria Videloup
* CS50x2020
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


//We define our block size and set it to 512 bytes.
#define BLOCK_SIZE 512

//Then we define the type
typedef uint8_t BYTE;

//And start our program
int main(int argc, char *argv[])
{
    //This first "if" condition ensures that the user is typing the right input.
    if (argc != 2)
    {
        //If he isn't, this error message will be prompted to him.
        fprintf(stderr, "Usage: recover infile\n");
        return 1;
    }

    //Here we wish to remember the filenames
    char *infile = argv[1];

    //Here we open the input file
    FILE *inptr = fopen(infile, "r");
    //And we add an error message if the file couldn't be open.
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    //We create a buffer with 512 bytes
    BYTE buffer[512];
    int imageCount = 0;

    char filename[8];
    FILE *outptr = NULL;

    // and here we begin the operations to make.
    while (true)
    {
        ///Here we read the memory card
        size_t bytesRead = fread(buffer, sizeof(BYTE), BLOCK_SIZE, inptr);

        // We break out of the loop when we reach the end of the card image
        if (bytesRead == 0 && feof(inptr))
        {
            break;
        }

        //We check with a boolean expression if we have found a jpeg
        //Let's remember the following :
        //Beginning of jpeg file: 0xff, 0xd8, 0xff, 0xef.
        //End of jpeg file: 0xe0, 0xe2, […], 0xef. //
        bool containsJpegHeader = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;

        //Here we establish the condition that says that if we run into another jpeg,
        //we must close the last one.
        if (containsJpegHeader && outptr != NULL)
        {
            fclose(outptr);
            imageCount++;
        }

        //If we find a Jpeg, we open the file and write it
        if (containsJpegHeader)
        {
            sprintf(filename, "%03i.jpg", imageCount);
            outptr = fopen(filename, "w");
        }

        //And we write into the file
        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(BYTE), bytesRead, outptr);
        }
    }

    //We keep closing the last jpeg
    fclose(outptr);

    //We close the infile
    fclose(inptr);

    //and finish the program with success
    return 0;
}
