/*
 * sunaarashi -  noise.
 *
 * sunaarashi.c
 *
 * Copyright (c) 2016 sasairc
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar.HocevarHocevar See the COPYING file or http://www.wtfpl.net/
 * for more details.
 */

#include "./config.h"
#include "./sunaarashi.h"
#include "./subset.h"
#include "./info.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <getopt.h>

int main(int argc, char* argv[])
{
    int     i       = 0,
            res     = 0,
            index   = 0;
    FILE*   fp      = NULL;

    sand_t  st      = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL,
    };

    struct option   opts[] = {
        {"quality", required_argument,  NULL,   'q'},
        {"width",   required_argument,  NULL,   'w'},
        {"height",  required_argument,  NULL,   'h'},
        {"red",     required_argument,  NULL,   'r'},
        {"green",   required_argument,  NULL,   'g'},
        {"blue",    required_argument,  NULL,   'b'},
        {"help",    no_argument,        NULL,    0 },
        {"version", no_argument,        NULL,    1 },
        {0, 0, 0, 0},
    };

    while ((res = getopt_long(argc, argv, "q:w:h:r:g:b:", opts, &index)) != -1) {
        switch (res) {
            case    'q':
                if (strisdigit_with_maxvalue(optarg, 100) < 0) {
                    fprintf(stderr, "%s: %s: invalid quality value\n",
                            PROGNAME, optarg);

                    return -1;
                }
                break;
            case    'w':
                for (i = 0; i < strlen(optarg); i++) {
                    if (!isdigit(*(optarg + 1))) {
                        fprintf(stderr, "%s: %s: invalid width value\n",
                                PROGNAME, optarg);

                        return -1;
                    }
                }
                st.warg = atoi(optarg);
                st.wflag = 1;
                break;
            case    'h':
                for (i = 0; i < strlen(optarg); i++) {
                    if (!isdigit(*(optarg + 1))) {
                        fprintf(stderr, "%s: %s: invalid height value\n",
                                PROGNAME, optarg);

                        return -1;
                    }
                }
                st.harg = atoi(optarg);
                st.hflag = 1;
                break;
            case    'r':
                if (strisdigit_with_maxvalue(optarg, 255) < 0) {
                    fprintf(stderr, "%s: %s: invalid RGB value\n",
                            PROGNAME, optarg);

                    return -1;
                }
                st.rarg = atoi(optarg);
                st.rflag = 1;
                break;
            case    'g':
                if (strisdigit_with_maxvalue(optarg, 255) < 0) {
                    fprintf(stderr, "%s: %s: invalid RGB value\n",
                            PROGNAME, optarg);

                    return -1;
                }
                st.garg = atoi(optarg);
                st.gflag = 1;
                break;
            case    'b':
                if (strisdigit_with_maxvalue(optarg, 255) < 0) {
                    fprintf(stderr, "%s: %s: invalid RGB value\n",
                            PROGNAME, optarg);

                    return -1;
                }
                st.barg = atoi(optarg);
                st.bflag = 1;
                break;
            case    0:
                print_usage();
            case    1:
                print_version();
            case    '?':
                return -1;
        }
    }

    if (optind == argc) {
        fprintf(stderr, "%s: missing file operand\n",
                PROGNAME);

        return 1;
    } else {
        st.oarg = argv[optind];
    }
    if (st.qflag == 0)
        st.qarg = DEFAULT_QUAL;
    if (st.wflag == 0)
        st.warg = DEFAULT_WIDTH;
    if (st.hflag == 0)
        st.harg = DEFAULT_HEIGHT;
    if (st.rflag == 0)
        st.rarg = DEFAULT_RGB;
    if (st.gflag == 0)
        st.garg = DEFAULT_RGB;
    if (st.bflag == 0)
        st.barg = DEFAULT_RGB;

    if ((fp = fopen(st.oarg, "wb")) == NULL) {
        perror("fopen");

        return 1;
    }
    create_image(fp, &st);
    fclose(fp);

    return 0;
}
