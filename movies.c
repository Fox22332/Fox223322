#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 15

typedef struct movie
{
    char title[100];
    float rating;
} movie;

// TODO: Реализовать функцию сортировки
void sort_movies(movie movies[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (movies[j].rating < movies[j + 1].rating)
            {
                movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    // Создаем массив фильмов
    movie movies[MAX_MOVIES] = {{"The Lord of the Rings: The Return of the King", 8.9},
                                {"The Shawshank Redemption", 9.3},
                                {"Transformers", 7.0},
                                {"The Godfather", 9.2},
                                {"Jumanji", 7.3},
                                {"Inside Out", 8.1},
                                {"A Quiet Place: Day One", 6.3},
                                {"Schindler's List", 9.0},
                                {"Groundhog Day", 8.0},
                                {"Inception", 8.8},
                                {"The Empire Strikes Back", 8.7},
                                {"La La Land", 8.3},
                                {"Spider-Man: Into the Spider-Verse", 8.4},
                                {"Sonic the Hedgehog 2", 6.5},
                                {"Back to the Future", 8.5}};

    // Сортируем фильмы по рейтингу
    sort_movies(movies, MAX_MOVIES);

    // Выводим отсортированный список
    printf("Список фильмов, отсортированных по рейтингу\n\n");
    for (int i = 0; i < MAX_MOVIES; i++)
    {
        printf("%s: %.1f\n", movies[i].title, movies[i].rating);
    }

    return 0;
}
