#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Запросить начальный баланс и проверить его корректность
    float start_balance;
    do
    {
        start_balance = get_float("начальный баланс: ");
    } while (start_balance <= 0);

    // Запросить процентную ставку и проверить её корректность
    float interest_rate;
    do
    {
        interest_rate = get_float("процентная ставка: ");
    } while (interest_rate <= 0);

    // Запросить ежегодное пополнение и проверить его корректность
    float yearly_deposit;
    do
    {
        yearly_deposit = get_float("ежегодное пополнение: ");
    } while (yearly_deposit < 0);

    // Запросить целевой баланс и проверить его корректность
    float target_balance;
    do
    {
        target_balance = get_float("целевой баланс: ");
    } while (target_balance < start_balance);

    // Вычислить количество лет, необходимых для хранения целевого баланса
    if (target_balance == start_balance)
    {
        printf("Лет: 0\n");
        return 0;
    }

    int years = 0;
    float current_balance = start_balance;

    while (current_balance < target_balance)
    {
        current_balance += current_balance * (interest_rate / 100);
        current_balance += yearly_deposit;
        years++;
    }

    // Вывести результат
    printf("Лет: %d\n", years);
    return 0;
}
