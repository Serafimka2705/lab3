/**
 * filter.c -- программа для наложения фильтров на 
 * изображение в формате BMP
 *
 * Copyright (c) 2009, Student Name <student@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
double pixel_array2[10000000];
void sharpen(bmp_image image, double *pixel_array2);

int main(int argc, char *argv[])
{
    bmp_image image;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s sourcefile destfile\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    image = bmp_read(argv[1]);

    /* bmp_gray(image); */
    sharpen(image, pixel_array2);
    bmp_write(argv[2], image, pixel_array2);

    return 0;
}
