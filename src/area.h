//
// Created by joachimp on 2016-01-25.
//

#ifndef PTMUD_NEXT_AREA_H
#define PTMUD_NEXT_AREA_H

struct area_load_data
{
    enum
    {
        LOAD_ZON,
        LOAD_WLD,
        LOAD_MOB,
        LOAD_OBJ,
        LOAD_SHP
    } type;

    // TODO: Conditions?

    char                  *path;
    struct area_load_data *next;
};

struct area_data
{
    area_vnum area_number;
    char     *name;
    char     *author_name;
    char     *author_email;

    struct area_load_data *loads;
};

void load_area(FILE *fl, char *areaname);

extern struct area_data *areas;

#endif //PTMUD_NEXT_AREA_H
