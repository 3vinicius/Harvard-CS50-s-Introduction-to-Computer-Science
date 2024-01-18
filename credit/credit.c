#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define typeof(var) _Generic( (var),\
char: "Char",\
int: "Integer",\
float: "Float",\
char *: "String",\
void *: "Pointer",\
default: "Undefined")

int main(void)
{
    // Declarations
    int imp, par, result;
    long numCard = 0;
    char strNumCard[20];

    //Input
    numCard = get_long("Number: ");
    sprintf(strNumCard, "%ld", numCard);
    /* while(strlen(strNumCard) < 16){
        numCard = get_long("Number: ");
        sprintf(strNumCard, "%ld",numCard );
    } */

    /*     int val =  atoi(strNumCard); */

    //Algoritme
    imp = 0;
    par = 0;
    result = 0;
    int count = 0;
    for (int i = (strlen(strNumCard) - 1); i >= 0 ; i--)
    {
        count ++;
        if (count % 2 != 0)
        {
            int current = strNumCard[i] - '0';
            imp += current;
        }
        if (count % 2 == 0)
        {
            int current = strNumCard[i] - '0';
            current = (current * 2);
            if (current >= 10)
            {
                par += 1 + (current - 10);
            }
            else
            {
                par += current;
            }

        }

        result = imp + par;
    }

    /* 4062901840 */

    // Conditions cards

    if (result % 10 != 0)
    {
        printf("INVALID\n");
        exit(0);
    }


    if ((strNumCard[0] - '0') == 4)
    {
        if (strlen(strNumCard) == 13 || strlen(strNumCard) == 16)
        {
            printf("VISA\n");
            exit(0);
        }

    }
    if (strlen(strNumCard) == 15)
    {
        if ((strNumCard[0] - '0') == 3 && (strNumCard[1] - '0') == 4)
        {
            printf("AMEX\n");
            exit(0);
        }
        if ((strNumCard[0] - '0') == 3 && (strNumCard[1] - '0') == 7)
        {
            printf("AMEX\n");
            exit(0);
        }
    }
    if (strlen(strNumCard) == 16)
    {
        if ((strNumCard[0] - '0') == 5 && (strNumCard[1] - '0') == 1)
        {
            printf("MASTERCARD\n");
            exit(0);
        }
        if ((strNumCard[0] - '0') == 5 && (strNumCard[1] - '0') == 2)
        {
            printf("MASTERCARD\n");
            exit(0);
        }
        if ((strNumCard[0] - '0') == 5 && (strNumCard[1] - '0') == 3)
        {
            printf("MASTERCARD");
            exit(0);
        }
        if ((strNumCard[0] - '0') == 5 && (strNumCard[1] - '0') == 4)
        {
            printf("MASTERCARD\n");
            exit(0);
        }
        if ((strNumCard[0] - '0') == 5 && (strNumCard[1] - '0') == 5)
        {
            printf("MASTERCARD\n");
            exit(0);
        }
    }

    printf("INVALID\n");
    exit(0);


}