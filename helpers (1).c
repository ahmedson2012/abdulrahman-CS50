#include "helpers.h"
#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include <math.h>


static const int row[23] = {
    1, 22, 231, 1540, 7315, 26334,
    74613, 170544, 319770, 497420, 646646,
    705432, 646646, 497420, 319770, 170544,
    74613, 26334, 7315, 1540, 231, 22, 1
};


// المرحلة الأفقية
void horizontal(int height, int width,
                RGBTRIPLE image[height][width],
                RGBTRIPLE temp[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            long red = 0;
            long green = 0;
            long blue = 0;
            long count = 0;

            for(int k = j - 11; k <= j + 11; k++)
            {
                if(k >= 0 && k < width)
                {
                    int x = k - (j - 11);

                    red += image[i][k].rgbtRed * row[x];
                    green += image[i][k].rgbtGreen * row[x];
                    blue += image[i][k].rgbtBlue * row[x];

                    count += row[x];
                }
            }

            temp[i][j].rgbtRed = round((double) red / count);
            temp[i][j].rgbtGreen = round((double) green / count);
            temp[i][j].rgbtBlue = round((double) blue / count);
        }
    }
}


// المرحلة الرأسية
void vertical(int height, int width,
              RGBTRIPLE temp[height][width],
              RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            long red = 0;
            long green = 0;
            long blue = 0;
            long count = 0;

            for(int k = i - 11; k <= i + 11; k++)
            {
                if(k >= 0 && k < height)
                {
                    int x = k - (i - 11);

                    red += temp[k][j].rgbtRed * row[x];
                    green += temp[k][j].rgbtGreen * row[x];
                    blue += temp[k][j].rgbtBlue * row[x];

                    count += row[x];
                }
            }

            image[i][j].rgbtRed = round((double) red / count);
            image[i][j].rgbtGreen = round((double) green / count);
            image[i][j].rgbtBlue = round((double) blue / count);
        }
    }
}
// RGBTRIPLE average(int width, int height,RGBTRIPLE image[height][width],int width2, int height2)
// {
//     RGBTRIPLE average;

//     long red = 0;
//     long green = 0;
//     long blue = 0;
//     long count = 0;

//     int row[] = {
//         1, 22, 231, 1540, 7315, 26334,
//         74613, 170544, 319770, 497420, 646646,
//         705432, 646646, 497420, 319770, 170544,
//         74613, 26334, 7315, 1540, 231, 22, 1
//     };

//     for(int i = height2 - 11; i <= height2 + 11; i++)
//     {
//         for(int j = width2 - 11; j <= width2 + 11; j++)
//         {
//             if(i >= 0 && i < height && j >= 0 && j < width)
//             {
//                 int ki = i - (height2 - 11);
//                 int kj = j - (width2 - 11);

//                 long weight = (long) row[ki] * row[kj];

//                 red += image[i][j].rgbtRed * weight;
//                 green += image[i][j].rgbtGreen * weight;
//                 blue += image[i][j].rgbtBlue * weight;

//                 count += weight;
//             }
//         }
//     }

//     average.rgbtRed = round((double) red / count);
//     average.rgbtGreen = round((double) green / count);
//     average.rgbtBlue = round((double) blue / count);

//     return average;
// }
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float temp = 3;
    for(int height2 = 0; height2 < height; height2++){
        for(int width2 = 0; width2 < width; width2++){
            double average = (image[height2][width2].rgbtRed +
                image[height2][width2].rgbtGreen +
                image[height2][width2].rgbtBlue)/temp;

                image[height2][width2].rgbtRed = round(average);
                image[height2][width2].rgbtGreen = round(average);
                image[height2][width2].rgbtBlue = round(average);

        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE original;
    int16_t tempred = 0;
    int16_t tempgreen = 0;
    int16_t tempblue = 0;
        for(int height2 = 0; height2 < height; height2++){
            for(int width2 = 0; width2 < width; width2++){
                original = image[height2][width2];
                tempred = round((
                original.rgbtRed * 0.393 +
                original.rgbtGreen * 0.769 +
                original.rgbtBlue * 0.189));
                if(tempred > 255){
                    image[height2][width2].rgbtRed = 255;
                }else{
                    image[height2][width2].rgbtRed = tempred;
                }
                tempgreen = round((
                original.rgbtRed * 0.349 +
                original.rgbtGreen * 0.686 +
                original.rgbtBlue * 0.168));
                if(tempgreen > 255){
                    image[height2][width2].rgbtGreen = 255;
                }else{
                    image[height2][width2].rgbtGreen = tempgreen;
                }
                tempblue = round((
                original.rgbtRed * 0.272 +
                original.rgbtGreen * 0.534 +
                original.rgbtBlue * 0.131));
                if(tempblue > 255){
                    image[height2][width2].rgbtBlue = 255;
                }else{
                    image[height2][width2].rgbtBlue = tempblue;
                }
            }
        }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int xwidth;
    RGBTRIPLE temp;
        for(int height2 = 0; height2 < height; height2++){
            for(int width2 = 0; width2 < (width / 2); width2++){
                xwidth = width - (width2 + 1);
                temp = image[height2][width2];
                image[height2][width2] = image[height2][xwidth];
                image[height2][xwidth] = temp;
            }
        }

}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]){
    for(int pass = 0; pass < 4; pass++)
    {
        RGBTRIPLE temp[height][width];
        RGBTRIPLE original[height][width];

        // نسخة من الصورة الحالية
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                original[i][j] = image[i][j];
            }
        }

        // بلور أفقي
        horizontal(height, width, original, temp);

        // بلور رأسي
        vertical(height, width, temp, image);
    }
}
