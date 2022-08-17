#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            float red = image[i][j].rgbtRed;

            int average = round((blue + green + red) / 3);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalBlue, totalGreen, totalRed;
            totalBlue = totalGreen = totalRed = 0;
            float counter = 0.00;

            // Get neighbouring pixels
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    // Check if neighbouring pixel is valid
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    // Get image value
                    totalBlue += image[currentX][currentY].rgbtBlue;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalRed += image[currentX][currentY].rgbtRed;

                    counter++;
                }
                // Calculate average of neighbouring pixels
                temp[i][j].rgbtBlue = round(totalBlue / counter);
                temp[i][j].rgbtGreen = round(totalGreen / counter);
                temp[i][j].rgbtRed = round(totalRed / counter);
            }
        }
    }

    //Copy new pixels into original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blueX, greenX, redX, blueY, greenY, redY;
            blueX = greenX = redX = blueY = greenY = redY = 0;

            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (i - 1 + x < 0 || i - 1 + x > height - 1 || j - 1 + y < 0 || j - 1 + y > width - 1)
                    {
                        continue;
                    }

                    blueX += image[i - 1 + x][j - 1 + y].rgbtBlue * gx[x][y];
                    greenX += image[i - 1 + x][j - 1 + y].rgbtGreen * gx[x][y];
                    redX += image[i - 1 + x][j - 1 + y].rgbtRed * gx[x][y];

                    blueY += image[i - 1 + x][j - 1 + y].rgbtBlue * gy[x][y];
                    greenY += image[i - 1 + x][j - 1 + y].rgbtGreen * gy[x][y];
                    redY += image[i - 1 + x][j - 1 + y].rgbtRed * gy[x][y];
                }
            }

            int blue = round(sqrt((blueX * blueX) + (blueY * blueY)));
            int green = round(sqrt((greenX * greenX) + (greenY * greenY)));
            int red = round(sqrt((redX * redX) + (redY * redY)));

            if (blue > 255)
            {
                blue = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (red > 255)
            {
                red = 255;
            }

            temp[i][j].rgbtBlue = blue;
            temp[i][j].rgbtGreen = green;
            temp[i][j].rgbtRed = red;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
    return;
}
