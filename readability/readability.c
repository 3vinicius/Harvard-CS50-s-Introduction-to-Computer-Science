#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_text(string text, int array[]);
int colemanLiau(float l, float s);

int main(void)
{


    string text = get_string("Text: ");

    int arrayNumbersOfText[3];
    int arr = count_text(text, arrayNumbersOfText);


    float leterrPerWords = 100 * ((float) arrayNumbersOfText[2] / (float) arrayNumbersOfText[1]);
    float wrodsPerSentences = 100 * ((float) arrayNumbersOfText[0] / (float)arrayNumbersOfText[1]);

    /* Printfs */
    //printf("%d letters\n", arrayNumbersOfText[2]);
    //printf("%d words\n", arrayNumbersOfText[1]);
    //printf("%d sentences\n", arrayNumbersOfText[0]);

    int colemanValue = colemanLiau(leterrPerWords, wrodsPerSentences);

    if (colemanValue >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (colemanValue < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", colemanValue);
    }

}

int count_text(string text, int array[])
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            //ADD sentences
            array[0] += 1;
        }
        if (text[i] == 32)
        {
            //ADD words
            array[1] += 1;
        }
        if ((text[i] > 64 && text[i] < 91) || (text[i] > 96 && text[i] < 123))
        {
            //ADD letters
            array[2] += 1;
        }


    }
    array[1] += 1;
    return 0;
}

int colemanLiau(float l, float s)
{
    float index;



    index = (0.0588 * l) - (0.296 * s) - 15.8;

    index = round(index);
    return index;
}
