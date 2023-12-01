#include "../utils/utils.h"

void SolveTask2(void *info, int nr_planes, int N, char **mat) {
    unsigned short Line = 0, Column = 0;
    unsigned char d = 0, t = 0;

    for (int i = 0; i < nr_planes; i++) {
        readPlanes(info + i * PLANE_SIZE, &Line, &Column, &d, &t);
        if (t == '1' && d == 'N') {
            // drawing planes
            DrawPlane_1N(Line, Column, mat);
        }
        if (t == '1' && d == 'S') {
            DrawPlane_1S(Line, Column, mat);
        }
        if (t == '1' && d == 'E') {
            DrawPlane_1E(Line, Column, mat);
        }
        if (t == '1' && d == 'W') {
            DrawPlane_1W(Line, Column, mat);
        }
        if (t == '2' && d == 'N') {
            DrawPlane_2N(Line, Column, mat);
        }
        if (t == '2' && d == 'S') {
            DrawPlane_2S(Line, Column, mat);
        }
        if (t == '2' && d == 'E') {
            DrawPlane_2E(Line, Column, mat);
        }
        if (t == '2' && d == 'W') {
            DrawPlane_2W(Line, Column, mat);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}
