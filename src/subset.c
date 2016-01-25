/*
 * sunaarashi -  noise.
 *
 * subset.c
 *
 * Copyright (c) 2016 sasairc
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar.HocevarHocevar See the COPYING file or http://www.wtfpl.net/
 * for more details.
 */

#include "./sunaarashi.h"
#include "./subset.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <jpeglib.h>
#include <sys/time.h>

int create_rand(int max)
{
    int     ret;
    struct  timeval lo_timeval;

    gettimeofday(&lo_timeval, NULL);    /* get localtime */

    /* 
     * # setting factor for pseudo-random number
     * current microseconds * PID
     */
    srand((unsigned)(
        lo_timeval.tv_usec * getpid()
    ));

    ret = (int)(rand()%(max+1));        /* create pseudo-random number */

    return ret;
}

int create_image(FILE* fp, sand_t* st)
{
    int         x   = 0,
                y   = 0;

    JSAMPARRAY  img = NULL;

    struct  jpeg_compress_struct    cinfo;
    struct  jpeg_error_mgr          jerr;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);

    jpeg_stdio_dest(&cinfo, fp);

    cinfo.image_width = st->warg;
    cinfo.image_height = st->harg;
    cinfo.input_components = 3;
    cinfo.in_color_space = JCS_RGB;

    jpeg_set_defaults(&cinfo);
    jpeg_set_quality(&cinfo, 100, TRUE);
    jpeg_start_compress(&cinfo, TRUE);

    if ((img = (JSAMPARRAY)malloc(sizeof(JSAMPROW) * st->harg)) == NULL)
        return 2;

    while (y < st->harg) {
        x = 0;
        img[y] = (JSAMPROW)malloc(sizeof(JSAMPLE) * 3 * st->warg);
        while (x < st->warg) {
            img[y][x * 3 + 0] = create_rand(st->rarg);  /* R */
            img[y][x * 3 + 1] = create_rand(st->garg);  /* G */
            img[y][x * 3 + 2] = create_rand(st->barg);  /* B */
            x++;
        }
        y++;
    }
    y--;

    jpeg_write_scanlines(&cinfo, img, st->harg);
    jpeg_finish_compress(&cinfo);
    jpeg_destroy_compress(&cinfo);

    while (y != 0) {
        free(img[y]);
        y--;
    }
    free(img);

    return 0;
}

int strisdigit_with_maxvalue(char* arg, int max)
{
    int i = 0;

    while (i < strlen(arg)) {
        if (!isdigit(*(arg + i)))
            return -1;
        i++;
    }
    if (max < atoi(arg))
        return -2;

    return 0;
}
