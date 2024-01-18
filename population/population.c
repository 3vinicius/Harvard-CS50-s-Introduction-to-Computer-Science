#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startSize = 0;
    while (startSize  < 9)
    {
        startSize = get_int("Start size: ");
    }


    // TODO: Prompt for end size
    int endSize = 0;
    while (startSize > endSize)
    {
        endSize = get_int("End size: ");
    }

    // TODO: Calculate number of years until we reach threshold
    int temp = 0;
    int result = startSize;
    while (result < endSize)
    {
        result = result + (result / 3) - (result / 4);
        temp++;
    }

    // TODO: Print number of years
    printf("Years: %d\n", temp);
}

