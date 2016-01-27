/* ************************************************************************
*   File: area.c                                       Part of PTMUD-next *
*  Usage: Handling or areas, including loading                            *
*                                                                         *
*  All rights reserved.  See license.doc for complete information.        *
*                                                                         *
*  Copyright (C) 2016 by Joachim Pileborg                                 *
*  PTMUD-next is based on CircleMUD, Copyright (C) 1993, 1994.            *
*  CircleMUD is based on DikuMUD, Copyright (C) 1990, 1991.               *
************************************************************************ */

#include "conf.h"
#include "sysdep.h"
#include "structs.h"
#include "utils.h"
#include "area.h"
#include "interpreter.h"

struct area_data *areas = NULL;

/* ********************************************************************* */

static int count_commands(FILE *fl);
static int load_header(FILE *fl, char *areaname, struct area_data *area);
static int load_commands(FILE *fl, char *areaname, struct area_data *area, int line_num);

/* ********************************************************************* */

void load_area(FILE *fl, char *areaname)
{
    static area_rnum rarea = 0;

    int commands = count_commands(fl);

    struct area_data *area = &areas[rarea];

    int line_num = load_header(fl, areaname, area);

    if (commands == 0)
    {
        log("WARNING: Area %s is empty", areaname);
    }
    else
    {
        area->loads = malloc(commands * sizeof(struct area_load_data));
        if (area->loads == NULL)
        {
            log("SYSERR: Could not create commands for area %s!", areaname);
            exit(1);
        }

        load_commands(fl, areaname, area, line_num);
    }
}

/* ********************************************************************* */

static int count_commands(FILE *fl)
{
    char buf[READ_SIZE];

    // Skip the header lines
    for (int i = 0; i < 4; ++i)
        get_line(fl, buf);

    int commands = 0;

    while (get_line(fl, buf))
    {
        char *ptr = buf;
        skip_spaces(&ptr);
        if (ptr[0] == 'L' &&
            (ptr[1] == 'M' || ptr[1] == 'O' || ptr[1] == 'S' || ptr[1] == 'W' || ptr[1] == 'Z'))
        {
            ++commands;
        }
    }

    rewind(fl);

    return commands;
}

static int load_header(FILE *fl, char *areaname, struct area_data *area)
{
    char buf[READ_SIZE];
    int line_num = 0;
    char *ptr;

    // Get area virtual numver
    line_num += get_line(fl, buf);
    if (sscanf(buf, "#%lld", &area->area_number) != 1)
    {
        log("SYSERR: Format error in area %s, line %d", areaname, line_num);
        exit(1);
    }

    // Get area name
    line_num += get_line(fl, buf);
    if ((ptr = strchr(buf, '~')) != NULL)
    {
        ptr[0] = '\0';
    }
    area->name = strdup(buf);

    // Get area author name
    line_num += get_line(fl, buf);
    if ((ptr = strchr(buf, '~')) != NULL)
    {
        ptr[0] = '\0';
    }
    area->author_name = strdup(buf);

    // Get area author email address
    line_num += get_line(fl, buf);
    if ((ptr = strchr(buf, '~')) != NULL)
    {
        ptr[0] = '\0';
    }
    area->author_email = strdup(buf);

    return line_num;
}

static int load_commands(FILE *fl, char *areaname, struct area_data *area, int line_num)
{
    char buf[READ_SIZE];
    int tmp;

    for (int cmd = 0; ; ++cmd)
    {
        if ((tmp = get_line(fl, buf)) == 0)
        {
            log("SYSERR: Unexpected end of file at line %d for area #%lld \"%s\"", line_num, area->area_number, area->name);
        }

        line_num += tmp;

        char *ptr = buf;
        skip_spaces(&ptr);

        if (ptr[0] == '*')
        {
            continue;
        }

        if (ptr[0] == 'S' || ptr[0] == '$')
        {
            break;
        }

        if (ptr[1] == 'M' || ptr[1] == 'O' || ptr[1] == 'S' || ptr[1] == 'W' || ptr[1] == 'Z')
        {
            area->loads[cmd].type = ptr[1];

            ptr += 2;

            char buf2[READ_SIZE];
            if (sscanf(ptr, "%s", buf2) != 1)
            {
                log("SYSERR: Could not read path on line %d for area #%lld \"%s\"", line_num, area->area_number, area->name);
                exit(1);
            }

            area->loads[cmd].path = strdup(buf2);
        }
        else
        {
            log("SYSERR: Illegal area command on line %d for area #%lld \"%s\"", line_num, area->area_number, area->name);
            exit(1);
        }
    }

    return line_num;
}

/* ********************************************************************* */
