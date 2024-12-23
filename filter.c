#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

int main(int argc, char *argv[])
{
    // Определяем допустимые фильтры
    char *filters = "bgrs";

    // Получаем флаг фильтра и проверяем его корректность
    char filter = getopt(argc, argv, filters);
    if (filter == '?')
    {
        printf("Недопустимый фильтр.\n");
        return 1;
    }

    // Убеждаемся, что используется только один фильтр
    if (getopt(argc, argv, filters) != -1)
    {
        printf("Разрешен только один фильтр.\n");
        return 2;
    }

    // Убеждаемся в правильном использовании
    if (argc != optind + 2)
    {
        printf("Использование: ./filter [flag] infile outfile\n");
        return 3;
    }

    // Запоминаем имена файлов
    char *infile = argv[optind];
    char *outfile = argv[optind + 1];

    // Открываем входной файл
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Не удалось открыть %s.\n", infile);
        return 4;
    }

    // Открываем выходной файл
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf("Не удалось создать %s.\n", outfile);
        return 5;
    }

    // Читаем BITMAPFILEHEADER входного файла
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // Читаем BITMAPINFOHEADER входного файла
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // Убеждаемся, что входной файл является (вероятно) 24-битным несжатым BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        printf("Неподдерживаемый формат файла.\n");
        return 6;
    }

    // Получаем размеры изображения
    int height = abs(bi.biHeight);
    int width = bi.biWidth;

    // Выделяем память для изображения
    RGBTRIPLE(*image)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (image == NULL)
    {
        printf("Недостаточно памяти для хранения изображения.\n");
        fclose(outptr);
        fclose(inptr);
        return 7;
    }

    // Определяем заполнение для сканирующих строк
    int padding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;

    // Проходим в цикле по сканирующим строкам входного файла
    for (int i = 0; i < height; i++)
    {
        // Читаем строку в массив пикселей
        fread(image[i], sizeof(RGBTRIPLE), width, inptr);

        // Пропускаем заполнение
        fseek(inptr, padding, SEEK_CUR);
    }

    // Фильтруем изображение
    switch (filter)
    {
        // Размытие
        case 'b':
            blur(height, width, image);
            break;

        // Оттенки серого
        case 'g':
            grayscale(height, width, image);
            break;

        // Отражение
        case 'r':
            reflect(height, width, image);
            break;

        // Сепия
        case 's':
            sepia(height, width, image);
            break;
    }

    // Записываем BITMAPFILEHEADER выходного файла
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // Записываем BITMAPINFOHEADER выходного файла
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // Записываем новые пиксели в выходной файл
    for (int i = 0; i < height; i++)
    {
        // Записываем строку в выходной файл
        fwrite(image[i], sizeof(RGBTRIPLE), width, outptr);

        // Записываем заполнение в конце строки
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // Освобождаем память для изображения
    free(image);

    // Закрываем файлы
    fclose(inptr);
    fclose(outptr);
    return 0;
}