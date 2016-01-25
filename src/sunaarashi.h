/*
 * sunaarashi -  noise.
 *
 * sunaarashi.h
 *
 * Copyright (c) 2016 sasairc
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar.HocevarHocevar See the COPYING file or http://www.wtfpl.net/
 * for more details.
 */

#ifndef SUNAARASHI_H
#define SUNAARASHI_H

typedef struct  {
    short   oflag;  /* output filename */
    short   qflag;  /* quality */
    short   wflag;  /* width */
    short   hflag;  /* height */
    short   rflag;  /* R */
    short   gflag;  /* G */
    short   bflag;  /* B */
    int     qarg;
    int     rarg;
    int     garg;
    int     barg;
    int     warg;
    int     harg;
    char*   oarg;
} sand_t;

#endif
