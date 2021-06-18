#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
// 四捨五入をしてあげる
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE tmp;
    double color;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            color = ((double)(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)) / 3.0;
            tmp = (BYTE)(color + 0.5);
            image[i][j].rgbtBlue = tmp;
            image[i][j].rgbtGreen = tmp;
            image[i][j].rgbtRed = tmp;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE rtmp;
    BYTE gtmp;
    BYTE btmp;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            rtmp = image[i][j].rgbtRed;
            gtmp = image[i][j].rgbtGreen;
            btmp = image[i][j].rgbtBlue;
            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            image[i][width - 1 - j].rgbtRed = rtmp;
            image[i][width - 1 - j].rgbtGreen = gtmp;
            image[i][width - 1 - j].rgbtBlue = btmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy_image[i][j].rgbtRed = image[i][j].rgbtRed;
            copy_image[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy_image[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    float rtmp;
    float gtmp;
    float btmp;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int counter;
            rtmp = btmp = gtmp = counter = 0;
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }
                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    rtmp += copy_image[i + k][j + l].rgbtRed;
                    btmp += copy_image[i + k][j + l].rgbtBlue;
                    gtmp += copy_image[i + k][j + l].rgbtGreen;
                    counter++;
                }
            }
            image[i][j].rgbtRed = round(rtmp / counter);
            image[i][j].rgbtGreen = round(gtmp / counter);
            image[i][j].rgbtBlue = round(btmp / counter);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    float Gx_red;
    float Gx_blue;
    float Gx_green;
    float Gy_red;
    float Gy_blue;
    float Gy_green;
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            Gx_red = Gx_blue = Gx_green = Gy_red = Gy_blue = Gy_green = 0;
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }
                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    Gx_red += tmp[i + k][j + l].rgbtRed * Gx[k + 1][l + 1];
                    Gx_green += tmp[i + k][j + l].rgbtGreen * Gx[k + 1][l + 1];
                    Gx_blue += tmp[i + k][j + l].rgbtBlue * Gx[k + 1][l + 1];
                    Gy_red += tmp[i + k][j + l].rgbtRed * Gy[k + 1][l + 1];
                    Gy_green += tmp[i + k][j + l].rgbtGreen * Gy[k + 1][l + 1];
                    Gy_blue += tmp[i + k][j + l].rgbtBlue * Gy[k + 1][l + 1];
                }
            }
            int red = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
            int green = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
            int blue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));

            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}
