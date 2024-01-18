#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for(int i = 0; i < height; i++){
        for (int l = 0; l < width; l++) {
            if(image[i][l].rgbtRed == 0x00 && image[i][l].rgbtGreen == 0x00 && image[i][l].rgbtBlue == 0x00){
                image[i][l].rgbtGreen = 0xff;
            } else {
                image[i][l].rgbtRed = 0xff;
            }

        }
    }
}
