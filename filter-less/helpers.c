#include "helpers.h"
#include <math.h>
#include <stdbool.h>



// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for (int l = 0; l < width; l++) {

            float green = image[i][l].rgbtGreen ;
            float red = image[i][l].rgbtRed ;
            float blue = image[i][l].rgbtBlue ;

            int med = round((green + red + blue)/3);

            image[i][l].rgbtBlue =  image[i][l].rgbtRed = image[i][l].rgbtGreen = med;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for (int l = 0; l < width; l++) {


            float green = image[i][l].rgbtGreen ;
            float red = image[i][l].rgbtRed ;
            float blue = image[i][l].rgbtBlue ;

            int sepiaRed = round(0.393*red+0.769*green+0.189*blue);

            int sepiaGreen = round(0.349*red+0.686*green+0.168*blue);

            int sepiaBlue = round(0.272*red+0.534*green+0.131*blue);


            if(sepiaRed > 255){
                sepiaRed = 255;
            }
            if(sepiaGreen > 255){
                sepiaGreen = 255;
            }
            if(sepiaBlue > 255){
                sepiaBlue = 255;
            }

            image[i][l].rgbtGreen = sepiaGreen ;
            image[i][l].rgbtRed = sepiaRed;
            image[i][l].rgbtBlue = sepiaBlue;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for(int i = 0; i < height; i++){
        for (int l = 0; l < width / 2; l++) {
             RGBTRIPLE virtualImage = image[i][l];
            image[i][l] = image[i][width - (l+1)];
            image[i][width - (l+1)] =  virtualImage;
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