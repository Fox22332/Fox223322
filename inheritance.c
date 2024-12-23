// Имитация генетических закономерностей определения группы крови

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// У каждого человека два родителя и два гена, определяющих группу крови (аллеля)
typedef struct person
{
    struct person *parents[2]; // Массив указателей на двух родителей
    char alleles[2]; // Массив из двух символов, представляющих аллели
} person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Инициализация генератора случайных чисел
    srand(time(0));

    // Создать новую семью с тремя поколениями
    person *p = create_family(GENERATIONS);

    // Распечатать семейное древо групп крови
    print_family(p, 0);

    // Освободить память
    free_family(p);
}

// Создать нового человека с `generations` поколений
person *create_family(int generations)
{
    // Выделить память для нового человека
    person *new_person = malloc(sizeof(person));
    if (new_person == NULL)
    {
        fprintf(stderr, "Failed to allocate memory.\n");
        exit(1);
    }

    // Если есть поколения для создания, рекурсивно создать родителей
    if (generations > 1)
    {
        // Создать двух новых родителей для текущего человека
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        // Установить указатели на родителей для текущего человека
        new_person->parents[0] = parent0;
        new_person->parents[1] = parent1;

        // Случайно назначить аллели текущего человека на основе аллелей его родителей
        new_person->alleles[0] = parent0->alleles[rand() % 2];
        new_person->alleles[1] = parent1->alleles[rand() % 2];
    }
    else
    {
        // Установить указатели на родителей в NULL (для начального поколения)
        new_person->parents[0] = NULL;
        new_person->parents[1] = NULL;

        // Случайно назначить аллели
        new_person->alleles[0] = random_allele();
        new_person->alleles[1] = random_allele();
    }

    // Вернуть вновь созданного человека
    return new_person;
}

// Освободить память для `p` и всех его предков
void free_family(person *p)
{
    // Базовый случай: если `p` равен NULL, то ничего освобождать не нужно
    if (p == NULL)
    {
        return;
    }

    // Рекурсивно освободить память для родителей
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // Освободить память для текущего человека
    free(p);
}

// Распечатать каждого члена семьи и его аллели
void print_family(person *p, int generation)
{
    // Обработать базовый случай
    if (p == NULL)
    {
        return;
    }

    // Распечатать отступ
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Распечатать информацию о человеке в зависимости от поколения
    if (generation == 0)
    {
        printf("Ребенок (Поколение %i): группа крови %c%c\n", generation, p->alleles[0],
               p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Родитель (Поколение %i): группа крови %c%c\n", generation, p->alleles[0],
               p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Пра-");
        }
        printf("Дедушка/Бабушка (Поколение %i): группа крови %c%c\n", generation, p->alleles[0],
               p->alleles[1]);
    }

    // Рекурсивно распечатать родителей
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Случайно выбрать аллель группы крови
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
