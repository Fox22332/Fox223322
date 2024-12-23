#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    int num_rounds = get_int("Enter number of rounds: ");

    int score1 = 0;
    int score2 = 0;

    for (int round = 1; round <= num_rounds; round++)
    {
        printf("Round %d\n", round);

        string word1 = get_string("Player 1: ");
        string word2 = get_string("Player 2: ");

        int score_round1 = compute_score(word1);
        int score_round2 = compute_score(word2);

        if (score_round1 > score_round2)
        {
            printf("Player 1 wins!\n");
        }
        else if (score_round2 > score_round1)
        {
            printf("Player 2 wins!\n");
        }
        else
        {
            printf("Tie!\n");
        }

        score1 += score_round1;
        score2 += score_round2;
    }

    printf("Final score:\n");
    printf("Player 1: %d points\n", score1);
    printf("Player 2: %d points\n", score2);

    if (score1 > score2)
    {
        printf("Player 1 is the champion!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 is the champion!\n");
    }
    else
    {
        printf("Tie in the game!\n");
    }
}

int compute_score(string word)
{
    int score = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        char c = tolower(word[i]);

        if (isalpha(c))
        {
            int index = c - 'a';
            score += POINTS[index];
        }
    }

    return score;
}
