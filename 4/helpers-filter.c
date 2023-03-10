#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //calculate the average
            float average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;

            //round average to the nearest integer
            int rounded = round(average);

            //set pixel colors
            image[i][j].rgbtBlue = rounded;
            image[i][j].rgbtGreen = rounded;
            image[i][j].rgbtRed = rounded;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }


            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image2[height][width];

    for (int i = 0; i < height; i++)
    {
        int l = width - 1;
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE k = image[i][l];
            image2[i][j] =  k;
            l--;
        }
        for (int j = 0; j < width; j++)
        {
            image[i][j] =  image2[i][j];
        }
    }



    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image2[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image2[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //basic pixells
            float counter = 0.0;

            int b = image2[i][j].rgbtBlue;
            int g = image2[i][j].rgbtGreen;
            int r = image2[i][j].rgbtRed;

            counter++;

            //pixel on the left
            if (j - 1 >= 0)
            {
                b = b + image2[i][j - 1].rgbtBlue;
                g = g + image2[i][j - 1].rgbtGreen;
                r = r + image2[i][j - 1].rgbtRed;

                counter++;
            }

            //pixel on the right
            if (j + 1 < width)
            {
                b = b + image2[i][j + 1].rgbtBlue;
                g = g + image2[i][j + 1].rgbtGreen;
                r = r + image2[i][j + 1].rgbtRed;

                counter++;
            }

            //upper row, same pixel
            if (i - 1 >= 0)
            {
                b = b + image2[i - 1][j].rgbtBlue;
                g = g + image2[i - 1][j].rgbtGreen;
                r = r + image2[i - 1][j].rgbtRed;

                counter++;
            }

            //upper row, pixel on the left
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                b = b + image2[i - 1][j - 1].rgbtBlue;
                g = g + image2[i - 1][j - 1].rgbtGreen;
                r = r + image2[i - 1][j - 1].rgbtRed;

                counter++;
            }

            //upper row, pixel on the right
            if (i - 1 >= 0 && j + 1 < width)
            {
                b = b + image2[i - 1][j + 1].rgbtBlue;
                g = g + image2[i - 1][j + 1].rgbtGreen;
                r = r + image2[i - 1][j + 1].rgbtRed;

                counter++;
            }

            //lower row, same pixel
            if (i + 1 < height)
            {
                b = b + image2[i + 1][j].rgbtBlue;
                g = g + image2[i + 1][j].rgbtGreen;
                r = r + image2[i + 1][j].rgbtRed;

                counter++;
            }

            //lower row, pixel on the left
            if (i + 1 < height && j - 1 >= 0)
            {
                b = b + image2[i + 1][j - 1].rgbtBlue;
                g = g + image2[i + 1][j - 1].rgbtGreen;
                r = r + image2[i + 1][j - 1].rgbtRed;

                counter++;
            }

            //lower row, pixel on the right
            if (i + 1 < height && j + 1 < width)
            {
                b = b + image2[i + 1][j + 1].rgbtBlue;
                g = g + image2[i + 1][j + 1].rgbtGreen;
                r = r + image2[i + 1][j + 1].rgbtRed;

                counter++;
            }



            int averageRed = (round(r / counter));
            int averageGreen = (round(g / counter));
            int averageBlue = (round(b / counter));

            image[i][j].rgbtRed = averageRed;
            image[i][j].rgbtGreen = averageGreen;
            image[i][j].rgbtBlue = averageBlue;


        }
    }
    return;
}
//Sławek