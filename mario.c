#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("Высота пирамиды: ");
    }
    while (height <= 0);

    for (int i = 1; i <= height; i++)
    {
        for(int j = height - i; j > 0; j--)
        {
            printf("");
        }

        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}
