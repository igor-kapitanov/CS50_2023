#include "helpers.h"
#include <cs50.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int average = round((pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int new_red = 0, new_green = 0, new_blue = 0;
    RGBTRIPLE new_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            new_red = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            new_green = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            new_blue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));
            if (new_red < 0)
            {
                new_red = 0;
            }
            else if (new_red > 255)
            {
                new_red = 255;
            }
            if (new_green < 0)
            {
                new_green = 0;
            }
            else if (new_green > 255)
            {
                new_green = 255;
            }
            if (new_blue < 0)
            {
                new_blue = 0;
            }
            else if (new_blue > 255)
            {
                new_blue = 255;
            }
            new_image[i][j].rgbtRed = new_red;
            new_image[i][j].rgbtGreen = new_green;
            new_image[i][j].rgbtBlue = new_blue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_image[i][j];
        }
    }
    return;
}

void swap(RGBTRIPLE *pixel1, RGBTRIPLE *pixel2)
{
    RGBTRIPLE temp = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 = temp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            swap(&image[i][j], &image[i][width - 1 - j]);
        }
    }
    return;
}

bool is_valid_pixel(int i, int j, int height, int width)
{
    return (i >= 0 && i < height && j >= 0 && j < width);
}

RGBTRIPLE blur_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int red_comp, green_comp, blue_comp;
    red_comp = green_comp = blue_comp = 0;
    int numOfValidPixel = 0;

    for (int temp_i = -1; temp_i <= 1; temp_i++)
    {
        for (int temp_j = -1; temp_j <= 1; temp_j++)
        {
            int new_i = i + temp_i;
            int new_j = j + temp_j;
            if (is_valid_pixel(new_i, new_j, height, width))
            {
                numOfValidPixel++;
                red_comp += image[new_i][new_j].rgbtRed;
                green_comp += image[new_i][new_j].rgbtGreen;
                blue_comp += image[new_i][new_j].rgbtBlue;
            }
        }
    }
    RGBTRIPLE blurred_pixel;
    blurred_pixel.rgbtRed = round((float)red_comp / numOfValidPixel);
    blurred_pixel.rgbtGreen = round((float)green_comp / numOfValidPixel);
    blurred_pixel.rgbtBlue = round((float)blue_comp / numOfValidPixel);
    return blurred_pixel;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            new_image[i][j] = blur_pixel(i, j, height, width, image);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_image[i][j];
        }
    }
    return;
}