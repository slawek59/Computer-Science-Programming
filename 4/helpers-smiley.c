#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int j = 0; j < width; j++)
    {
        for (int i = 0; i < height; i++)
        {
            if (image[i][j].rgbtRed == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtBlue == 0x00)
            {
                image[i][j].rgbtRed = 0x89;
                image[i][j].rgbtGreen = 0x33;
                image[i][j].rgbtBlue = 0x80;
            }
        }
    }
}
//Sławek