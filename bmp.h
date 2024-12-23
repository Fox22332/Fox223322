// Типы данных BMP, основанные на собственных типах Microsoft

#include <stdint.h>

// Эти типы данных по сути являются псевдонимами для примитивных типов данных C/C++.
// Адаптировано из http://msdn.microsoft.com/en-us/library/cc230309.aspx  (вероятно, устарело).
// Дополнительная информация о библиотеке stdint.h: https://en.wikipedia.org/wiki/C_data_types#stdint.h.

typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
typedef uint16_t WORD;

// Структура BITMAPFILEHEADER содержит информацию о типе, размере 
// и структуре файла, который содержит DIB-изображение (независимое от устройства).
// Адаптировано из http://msdn.microsoft.com/en-us/library/dd183374(VS.85).aspx (вероятно, устарело).

typedef struct
{
  WORD  bfType;      // Тип файла (всегда "BM" для BMP)
  DWORD bfSize;      // Размер файла в байтах
  WORD  bfReserved1; // Зарезервировано
  WORD  bfReserved2; // Зарезервировано
  DWORD bfOffBits;   // Смещение от начала файла до пиксельных данных
} __attribute__((__packed__))
BITMAPFILEHEADER;

// Структура BITMAPINFOHEADER содержит информацию о размерах 
// и цветовом формате DIB-изображения (независимое от устройства).
// Адаптировано из http://msdn.microsoft.com/en-us/library/dd183376(VS.85).aspx (вероятно, устарело).

typedef struct
{
  DWORD biSize;       // Размер этой структуры
  LONG  biWidth;      // Ширина изображения в пикселях
  LONG  biHeight;     // Высота изображения в пикселях
  WORD  biPlanes;     // Число цветовых плоскостей (всегда 1)
  WORD  biBitCount;    // Количество бит на пиксель (например, 24 для 24-битного цвета)
  DWORD biCompression; // Тип сжатия (обычно BI_RGB для несжатого)
  DWORD biSizeImage;   // Размер изображения в байтах
  LONG  biXPelsPerMeter; // Разрешение по горизонтали
  LONG  biYPelsPerMeter; // Разрешение по вертикали
  DWORD biClrUsed;    // Количество используемых цветов в палитре
  DWORD biClrImportant;// Количество важных цветов
} __attribute__((__packed__))
BITMAPINFOHEADER;

// Структура RGBTRIPLE описывает цвет, состоящий из относительных интенсивностей
// красного, зеленого и синего цветов. 
// Адаптировано из http://msdn.microsoft.com/en-us/library/aa922590.aspx (вероятно, устарело).

typedef struct
{
  BYTE  rgbtBlue;  // Синяя компонента
  BYTE  rgbtGreen; // Зеленая компонента
  BYTE  rgbtRed;   // Красная компонента
} __attribute__((__packed__))
RGBTRIPLE;