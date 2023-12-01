#include "../utils/utils.h"


/* Struct for plane */
struct Plane {
    unsigned short line;
    unsigned short column;
    unsigned char dir;
    unsigned char airport[COD_SIZE];
    unsigned int v;
};

void detPlane(void *info, struct Plane *p) {
    unsigned short *short_info = info;
    p->line = *short_info;
    p->column = *(short_info + 1);

    unsigned char *char_info = info;
    p->dir = *(char_info + OFFSET_CHAR - 1);

    for (int i = 0; i < COD_SIZE - 1; i++) {
        p->airport[i] = *(char_info + OFFSET_CHAR + i);
    }
    p->airport[COD_SIZE-1] = '\0';

    unsigned int *int_info = info + OFFSET_INT;
    p->v = *int_info;
}


/* Comparing function for qsort */
int comparePlanes(const void *plane1, const void *plane2) {
    unsigned char type1 = ((struct Plane *)plane1)->airport[0];
    unsigned char type2 = ((struct Plane *)plane2)->airport[0];
    unsigned char cod1[4], cod2[4];
    cod1[0] = ((struct Plane *)plane1)->airport[1];
    cod1[1] = ((struct Plane *)plane1)->airport[2];
    cod1[2] = ((struct Plane *)plane1)->airport[3];
    cod1[3] = '\0';
    cod2[0] = ((struct Plane *)plane2)->airport[1];
    cod2[1] = ((struct Plane *)plane2)->airport[2];
    cod2[2] = ((struct Plane *)plane2)->airport[3];
    cod2[3] = '\0';
    unsigned int spd1 = ((struct Plane *)plane1)->v;
    unsigned int spd2 = ((struct Plane *)plane2)->v;

    if (type1 < type2) {
        return -1;
    } else if (type1 > type2) {
        return 1;
    }

    if (type1 == type2 && strcmp(cod1, cod2) > 0) {
        return -1;
    } else if (type1 == type2 && strcmp(cod1, cod2) < 0) {
        return 1;
    }

    if (type1 == type2 && strcmp(cod1, cod2) == 0 && spd1 < spd2) {
        return -1;
    } else if (type1 == type2 && strcmp(cod1, cod2) == 0 && spd1 > spd2) {
        return 1;
    } else {
        return 0;
    }
}

void print_plane(struct Plane *p) {
    printf("(%hu, %hu)\n", p->line, p->column);
    printf("%c\n", p->dir);
    for (int i = 0; i < COD_SIZE - 1; i++) {
        printf("%c", p->airport[i]);
    }
    printf("\n");
    printf("%d\n", p->v);
}

void SolveTask3(void *info, int nr_avioane) {
    // array of plane structs
    struct Plane p[nr_avioane];
    for (int i = 0; i < nr_avioane; i++) {
        // assigning info about a plane in the matching struct from array
        detPlane(info + i * PLANE_SIZE, &p[i]);
    }

    qsort((void *)p, nr_avioane, sizeof(p[0]), comparePlanes);
    for (int i = 0; i < nr_avioane; i++) {
        print_plane(&p[i]);
        printf("\n");
    }
}
