#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Declaration variables
    int height;
    int i, j, k;

    //input
    printf("\n");
    height = get_int("Height: ");



    //Verification
    while (height < 1 || height > 8)
    {
        printf("\n");
        printf("Value undefined \n");
        printf("input a positive integer between 1 and 8 \n");
        printf("\n");
        height = get_int("Height: ");
    }


    //Algorimo constructor blocks
    printf("\n");
    for (i = 1; i <= height; i++)
    {
        for (j = height; j > i; j--)
        {
            printf(" ");
        }
        for (k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }

}