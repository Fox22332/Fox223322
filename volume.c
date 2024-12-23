#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define HEADER_SIZE 44  // Размер заголовка WAV

int main(int argc, char *argv[])
{
    // Проверить наличие аргументов командной строки
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Открытие файлов и определение масштабирующего коэффициента
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open input file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL)
    {
        printf("Could not open output file.\n");
        fclose(input);
        return 1;
    }

    // Преобразовать коэффициент из строки в число с плавающей запятой
    float factor = atof(argv[3]);

    // Копирование заголовка из входного файла в выходной файл
    uint8_t header[HEADER_SIZE];
    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    // Создать буфер для одного сэмпла
    int16_t buffer;

    // Считать один сэмпл с входного файла в буфер, пока не останется сэмплов для чтения
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        // Обновить громкость сэмпла
        buffer *= factor;

        // Записать обновлённый сэмпл в новый файл
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Закрытие файлов
    fclose(input);
    fclose(output);

    return 0;
}
