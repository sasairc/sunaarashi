/*
 * sunaarashi -  noise.
 *
 * info.c
 *
 * Copyright (c) 2016 sasairc
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar.HocevarHocevar See the COPYING file or http://www.wtfpl.net/
 * for more details.
 */

#include "./config.h"
#include "./info.h"
#include <stdio.h>
#include <stdlib.h>

void print_version(void)
{
    fprintf(stdout, "%s %d.%d.%d%s (%s)\n",
            PROGNAME, VERSION, PATCHLEVEL, SUBLEVEL, EXTRAVERSION, ARCH);

    exit(0);
}

void print_usage(void)
{
    fprintf(stdout, "\
%s %d.%d.%d%s, generate random noise\n\
Usage: clangsay [OPTION]...\n\
\n\
Mandatory arguments to long options are mandatory for short options too.\n\
\n\
  -o,  --output=FILE         output filename [DEFAULT: out.jpg]\n\
  -q,  --quality=INT         jpeg compress quality\n\
  -w,  --width=PIXEL         output image size (width)\n\
  -h,  --height=PIXEL        output image size (height)\n\
  -r,  --red=[0-255]         manually specifies max-color R\n\
  -g,  --green=[0-255]       manually specifies max-color G\n\
  -b,  --blue=[0-255]        manually specifies max-color B\n\
\n\
       --help                display this help and exit\n\
       --version             optput version infomation and exit\n\
\n\
Report %s bugs to %s <%s>\n\
",
        PROGNAME, VERSION, PATCHLEVEL, SUBLEVEL, EXTRAVERSION,
        PROGNAME, AUTHOR, MAIL_TO);

    exit(0);
}
