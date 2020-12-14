#include "bmp.h"
#include<stdlib.h>
/*double pixel_array2[10000000];*/

/*
 * Фильтр sharpen
 * 
*/
void sharpen(bmp_image image, double *pixel_array2)
{
    unsigned int i, j;

    /* Получаем линейные размеры изображения */
    unsigned int w = image.header.width;
    unsigned int h = image.header.height;

    /* Для всех строк пикселей */

    int m[3][3] = { {-1, -1, -1}, {-1, 9, -1}, {-1, -1, -1} };
    int x, y, l;
    double s;
    for (l = 0; l < 3; l++)
        for (i = 1; i < h - 1; i++)
            for (j = 1; j < w - 1; j++) {
                s = 0;
                for (x = 0; x < 3; x++)
                    for (y = 0; y < 3; y++) {
                        s += m[x][y] * image.pixel_array[l * h * w +
                                                         (i + x - 1) * w +
                                                         j + y - 1];



                    }
                if (s > 1) {
                    pixel_array2[l * h * w + (i - 1) * w + j - 1] = 1;
                } else {
                    pixel_array2[l * h * w + (i - 1) * w + j - 1] = s;
                }
            }




}
