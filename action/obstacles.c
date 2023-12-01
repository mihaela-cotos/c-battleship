#include "../utils/utils.h"

void SolveTask4(void *info, int nr_planes, int nr_obstacole, int *x, int *y, int N) {
    // making a new matrix
    char **new_mat = calloc(N, sizeof(char*));
    for (int i = 0; i < N; i++) {
        new_mat[i] = calloc(N, sizeof(char));
        for (int j = 0; j < N; j++) {
            new_mat[i][j] = '.';
        }
    }

    int safe_planes = 0;
    safe_planes = nr_planes;
    unsigned short Line = 0, Column = 0;
    unsigned char d = 0, t = 0;


    // drawing planes
    for (int i = 0; i < nr_planes; i++) {
        readPlanes(info + i * PLANE_SIZE, &Line, &Column, &d, &t);
        if (t == '1' && d == 'N') {
            DrawPlane_1N(Line, Column, new_mat);
        }
        if (t == '1' && d == 'S') {
            DrawPlane_1S(Line, Column, new_mat);
        }
        if (t == '1' && d == 'E') {
            DrawPlane_1E(Line, Column, new_mat);
        }
        if (t == '1' && d == 'W') {
            DrawPlane_1W(Line, Column, new_mat);
        }
        if (t == '2' && d == 'N') {
            DrawPlane_2N(Line, Column, new_mat);
        }
        if (t == '2' && d == 'S') {
            DrawPlane_2S(Line, Column, new_mat);
        }
        if (t == '2' && d == 'E') {
            DrawPlane_2E(Line, Column, new_mat);
        }
        if (t == '2' && d == 'W') {
            DrawPlane_2W(Line, Column, new_mat);
        }
    }

    // drawing obstacles
    for (int i = 0; i < nr_obstacole; i++) {
        new_mat[x[i]][y[i]] = '@';
    }


    // checking if a plane collides with an obstacle
    for (int i = 0; i < nr_planes; i++) {
        readPlanes(info + i * PLANE_SIZE, &Line, &Column, &d, &t);
        if (d == 'N') {
            if (t == '1') {
                Radar_N1(new_mat, N, Line, Column, &safe_planes);
            }
            if (t == '2') {
                Radar_N2(new_mat, N, Line, Column, &safe_planes);
            }
        }

        if (d == 'S') {
            if (t == '1') {
                Radar_S1(new_mat, N, Line, Column, &safe_planes);
            }
            if (t == '2') {
                Radar_S2(new_mat, N, Line, Column, &safe_planes);
            }
        }

        if (d == 'E') {
            if (t == '1') {
                Radar_E1(new_mat, N, Line, Column, &safe_planes);
            }
            if (t == '2') {
                Radar_E2(new_mat, N, Line, Column, &safe_planes);
            }
        }

        if (d == 'W') {
            if (t == '1') {
                Radar_W1(new_mat, N, Line, Column, &safe_planes);
            }
            if (t == '2') {
                Radar_W2(new_mat, N, Line, Column, &safe_planes);
            }
        }
    }
    printf("%d\n", safe_planes);

    for (int i = 0; i < N; i++) {
        free(new_mat[i]);
    }
    free(new_mat);
}
