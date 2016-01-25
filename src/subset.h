/*
 * sunaarashi -  noise.
 *
 * subset.h
 *
 * Copyright (c) 2016 sasairc
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar.HocevarHocevar See the COPYING file or http://www.wtfpl.net/
 * for more details.
 */

#ifndef SUBSET_H
#define SUBSET_H

#include <stdio.h>
#include "./sunaarashi.h"

extern int create_rand(int max);
extern int create_image(FILE* fp, sand_t* st);
extern int strisdigit_with_maxvalue(char* arg, int max);

#endif
