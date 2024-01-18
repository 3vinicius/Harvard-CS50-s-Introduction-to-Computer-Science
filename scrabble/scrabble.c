#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner

    if (score1 != score2)
    {
        printf("Player ");
        if (score1 > score2)
        {
            printf("1 ");
        }
        if (score2 > score1)
        {
            printf("2 ");
        }
        printf("wins!\n");
        return 0;
    }
    else
    {
        printf("Tie!\n");
    }


}

int compute_score(string word)
{
    int qtdChards = strlen(word);
    string newString = word;
    int sum = 0;
    for (int i = 0; i < qtdChards; i++)
    {
        if (newString[i] > 96 && newString[i] < 123)
        {
            newString[i] = newString[i] - 32;
        }
        if (newString[i] > 64 && newString[i] < 91)
        {
            sum += POINTS[newString[i] - 65];
        }
    }

    return sum;
}

