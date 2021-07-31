/*
* Author: Gloria Videloup
* CS50x2020
*/

#include "helpers.h"
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //As this is basically a graphic work, we are going to use a Float.
    float rgbGray;


    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            //Here we use round to average the number to the nearest integer when assigning our values to a pixel value. This helps us being more precise when we wish the colors to become gray.
            rgbGray = round((image[j][i].rgbtBlue + image[j][i].rgbtGreen + image[j][i].rgbtRed) / 3.000);
            image[j][i].rgbtRed = rgbGray;
            image[j][i].rgbtGreen = rgbGray;
            image[j][i].rgbtBlue = rgbGray;

        }
    }
}

//We need a security case which will prevent our stack from overflowing.
//For that, we declare a limit which takes RGB as parameter and sets its limit to 255.

int limit(int RGB)
{
    if (RGB >= 255)
    {
        RGB = 255;
    }
    return RGB;

}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //As seen in the 4th lecture, we are going to use a temporary array to swap the values we are going to use.
    int temp[3];
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width / 2; i++)
        {
            temp[0] = image[j][i].rgbtBlue;
            temp[1] = image[j][i].rgbtGreen;
            temp[2] = image[j][i].rgbtRed;

            //We use this swapping technique to change the pixels of place, so that the image ends up reflected.
            image[j][i].rgbtBlue = image[j][width - i - 1].rgbtBlue;
            image[j][i].rgbtGreen = image[j][width - i - 1].rgbtGreen;
            image[j][i].rgbtRed = image[j][width - i - 1].rgbtRed;

            image[j][width - i - 1].rgbtBlue = temp[0];
            image[j][width - i - 1].rgbtGreen = temp[1];
            image[j][width - i - 1].rgbtRed = temp[2];

        }

    }

}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    //We declare our variables.
    int sumRed;
    int sumBlue;
    int sumGreen;
    float counter;

    //As seen in the 4th lecture, we will use a temporary table to handle the information.
    RGBTRIPLE temp[height][width];

    //And we add a for loop that will verify the correctness of the blur.
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            //We initialize our variables.
            sumRed = 0;
            sumGreen = 0;
            sumBlue = 0;
            counter = 0.00;

            //And we go on with the verification of the pixels in the height of the picture.
            for (int k = -1; k < 2; k++)
            {
                //We establish the condition
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;

                }

                //And we go on with the verification of the pixels in the width of the picture.
                for (int l = -1; l < 2; l++)
                {
                    if (i + l < 0 || i + l > width - 1)
                    {
                        continue;

                    }

                    sumRed += image[j + k][ i + l].rgbtRed;
                    sumGreen += image[j + k][i + l].rgbtGreen;
                    sumBlue += image[j + k][i + l].rgbtBlue;
                    counter++;

                }

            }

            //Finally here we average the sum to intensify the bluriness of the picture.
            temp[j][i].rgbtRed = round(sumRed / counter);
            temp[j][i].rgbtGreen = round(sumGreen / counter);
            temp[j][i].rgbtBlue = round(sumBlue / counter);

        }

    }

    //And to finish, we copy the values in the temporary table.
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;

        }

    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //We create temporary variables to store the calculations.
    float sumBlueY;
    float sumGreenY;
    float sumRedY;
    float sumBlueX;
    float sumGreenX;
    float sumRedX;
    float modifierX;
    float modifierY;

    //We create a temporary table of colors to not alter the calculations
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            //We reset the values for every pixel
            sumBlueY = 0.0;
            sumGreenY = 0.0;
            sumRedY = 0.0;
            sumBlueX = 0.0;
            sumGreenX = 0.0;
            sumRedX = 0.0;

            //Here we sum the values of the pixel and 8 neighboring ones after applying a modifier,
            //then we skip iteration if it goes outside the image.
            for (int k = -1; k < 2; k++)
            {
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;
                }

                for (int h = -1; h < 2; h++)
                {
                    if (i + h < 0 || i + h > width - 1)
                    {
                        continue;
                    }

                    //This part calculates modifiers for vertical and horizantal borders
                    modifierX = (k + 1 * k - k * abs(h));
                    modifierY = (h + 1 * h - h * abs(k));

                    sumBlueX += image[j + k][i + h].rgbtBlue * modifierX;
                    sumGreenX += image[j + k][i + h].rgbtGreen * modifierX;
                    sumRedX += image[j + k][i + h].rgbtRed * modifierX;

                    sumBlueY += image[j + k][i + h].rgbtBlue * modifierY;
                    sumGreenY += image[j + k][i + h].rgbtGreen * modifierY;
                    sumRedY += image[j + k][i + h].rgbtRed * modifierY;
                }
            }

            //This part obtains the final values of the pixels combining X and Y calculations
            temp[j][i].rgbtBlue = limit(round(sqrt(sumBlueX * sumBlueX + sumBlueY * sumBlueY)));
            temp[j][i].rgbtGreen = limit(round(sqrt(sumGreenX * sumGreenX + sumGreenY * sumGreenY)));
            temp[j][i].rgbtRed = limit(round(sqrt(sumRedX * sumRedX + sumRedY * sumRedY)));
        }
    }

    //An finally we copy the values from the temporary table
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }
}
