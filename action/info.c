#include "../utils/utils.h"

void PlaneTask1(void *info) {
    // determine the information about planes
    
    unsigned short *short_info = info;
    unsigned short Line = 0, Column = 0;
    Line = *short_info;
    Column = *(short_info + 1);
    printf("(%hu, %hu)\n", Line, Column);

    unsigned char *char_info = info;
    unsigned char dir = 0;
    dir = *(char_info + OFFSET_CHAR - 1);
    printf("%c\n", dir);

    unsigned char cod[COD_SIZE];
    for (int i = 0; i < COD_SIZE - 1; i++) {
        cod[i] = *(char_info + OFFSET_CHAR + i);
    }
    cod[COD_SIZE - 1] = '\0';
    printf("%s\n", cod);

    unsigned int *int_info = info + OFFSET_INT;
    unsigned int v = *int_info;
    printf("%d\n", v);
}

void SolveTask1(void *info, int nr_avioane) {
    unsigned char * c = info;

    for (int i = 0; i < nr_avioane; i++) {
        PlaneTask1(info + i * PLANE_SIZE);
        printf("\n");
    }
}
