//
// Created by joachimp on 2016-01-25.
//

#ifndef PTMUD_NEXT_AREA_H
#define PTMUD_NEXT_AREA_H

struct area_load_data
{
    // TODO: Conditions?

    char  type;  // Type of file to load
    char *path;
};

struct area_data
{
    area_vnum area_number;
    char     *name;             // Short name of the area
    char     *long_name;        // Long name of the area
    char     *author_name;      // Author MUD name
    char     *author_real_name; // Author real name (may be empty)
    char     *author_email;     // Author email address (may be empty)

    struct area_load_data *loads;
    size_t                 load_count;  // Number of entries in loads
};

#define AREA_HEADER_LINES   6       // 6 lines of header fields

void load_area(FILE *fl, char *areaname);

extern struct area_data *areas;

#endif //PTMUD_NEXT_AREA_H
