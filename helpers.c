#include "helpers.h"
#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include <math.h>
RGBTRIPLE average(int width, int height,  RGBTRIPLE image[height][width], int width2, int height2){
    float count = 0;
    RGBTRIPLE average;
    int red = 0;
    int green = 0;
    int blue = 0;
    for(int i = height2 - 1; i <= height2 + 1; i++){
        for(int j = width2 - 1; j <= width2 + 1; j++){
            if(i >= 0 && i < height && j >= 0 && j < width){
                red += image[i][j].rgbtRed;
                green += image[i][j].rgbtGreen;
                blue += image[i][j].rgbtBlue;
                count++;
            }

        }
    }
    average.rgbtRed = round(red / count);
    average.rgbtGreen = round(green / count);
    average.rgbtBlue = round(blue / count);
    return average;
}
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

    if(width %2 == 0){
        for(int height2 = 0; height2 < height; height2++){
            for(int width2 = 0; width2 < (width / 2); width2++){
                xwidth = width - (width2 + 1);
                temp = image[height2][width2];
                image[height2][width2] = image[height2][xwidth];
                image[height2][xwidth] = temp;
            }
        }
    }else{
            for(int height2 = 0; height2 < height; height2++){
                for(int width2 = 0; width2 <= (width / 2); width2++){
                    xwidth = width - (width2 + 1);
                    temp = image[height2][width2];
                    image[height2][width2] = image[height2][xwidth];
                    image[height2][xwidth] = temp;
                }
            }
         }

}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]){
    RGBTRIPLE original[height][width];
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            original[i][j] = image[i][j];
        }
    }
    for(int height2 = 0; height2 < height; height2++){
        for(int width2 = 0; width2 < width; width2++){
            image[height2][width2].rgbtRed = average(width, height, original, width2, height2).rgbtRed;
            image[height2][width2].rgbtGreen = average(width, height, original, width2, height2).rgbtGreen;
            image[height2][width2].rgbtBlue = average(width, height,  original, width2, height2).rgbtBlue;
        }
    }
}
