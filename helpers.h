#include "bmp.h"

// Преобразовать изображение в оттенки серого
void grayscale(int height, int width, RGBTRIPLE image[height][width]);

// Преобразовать изображение в сепию
void sepia(int height, int width, RGBTRIPLE image[height][width]);

// Отразить изображение горизонтально
void reflect(int height, int width, RGBTRIPLE image[height][width]);

// Размыть изображение
void blur(int height, int width, RGBTRIPLE image[height][width]);