
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_expenses(int day_count, float daily_expenses[], char output);

int main(void)
{
    int days;
    do
    {
        days = get_int("Количество дней вашей поездки: ");
    }
    while (days < 1);

    float daily_expenses[days];
    for (int i = 0; i < days; i++)
    {
        daily_expenses[i] = get_float("Расходы за день %i: ", i);
    }

    char output;
    do
    {
        output = toupper(
            get_char("Введите T для общей суммы расходов, A для средних расходов за день: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f\n", calc_expenses(days, daily_expenses, output));
}

// Функция для вычисления расходов
float calc_expenses(int day_count, float daily_expenses[], char output)
{
    float total_expenses = 0.0;

    // Считаем общую сумму расходов
    for (int i = 0; i < day_count; i++)
    {
        total_expenses += daily_expenses[i];
    }

    // Возвращаем либо общую сумму, либо среднее значение
    if (output == 'T')
    {
        return total_expenses; // Общая сумма
    }
    else // output == 'A'
    {
        return total_expenses / day_count; // Среднее значение
    }
}
