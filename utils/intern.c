#include "../utils/utils.h"

#define SIZE 1000

void *init_info(int nr_planes) {
    void *info = malloc(SIZE * sizeof(char));
    void *idx = info;

    for (int i = 0; i < nr_planes; i++) {
        unsigned short x = 0, y = 0;
        unsigned int v = 0;
        unsigned char dir = 0, cod[4];

        scanf("%hu %hu %c", &x, &y, &dir);
        scanf("%s", cod);
        scanf("%u", &v);

        *(unsigned short*)idx = x;
        idx += sizeof(unsigned short);

        *(unsigned short*)idx = y;
        idx += sizeof(unsigned short);

        *(unsigned char*)idx = dir;
        idx += sizeof(unsigned char);

        memcpy(idx, cod, 4 * sizeof(unsigned char));
        idx += 4 * sizeof(unsigned char);

        *(unsigned int*)idx = v;
        idx += sizeof(unsigned int);
    }

    return info;
}

int *init_vector(int N) {
    int *vect = (int *) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &vect[i]);
    }

    return vect;
}

void *read_obstacles(int **x, int **y, int nr_obstacole) {
    *x = calloc(nr_obstacole, sizeof(int));
    *y = calloc(nr_obstacole, sizeof(int));

    for (int i = 0; i < nr_obstacole; i++) {
        scanf("%d %d", *x + i, *y + i);
    }
}

char** init_mat(int N) {
    char **mat = calloc(N, sizeof(char*));

    for (int i = 0; i < N; i++) {
        mat[i] = calloc(N, sizeof(char));

        for (int j = 0; j < N; j++) {
            mat[i][j] = '.';
        }
    }

    return mat;
}

void free_mat(char **mat, int N) {
    for (int i = 0; i < N; i++) {
        free(mat[i]);
    }
    free(mat);
}

void Task1() {
    void *info = NULL;
    int nr_planes = 0;

    scanf("%d", &nr_planes);
    info = init_info(nr_planes);

    SolveTask1(info, nr_planes);
    free(info);
}

void Task2() {
    void *info = NULL;
    int nr_planes = 0;
    int N = 0;
    char **mat = NULL;

    scanf("%d", &nr_planes);
    info = init_info(nr_planes);
    scanf("%d", &N);
    mat = init_mat(N);

    SolveTask2(info, nr_planes, N, mat);
    free(info);
    free_mat(mat, N);
}

void Task3() {
    void *info = NULL;
    int nr_planes = 0;

    scanf("%d", &nr_planes);
    info = init_info(nr_planes);

    SolveTask3(info, nr_planes);
    free(info);
}

void Task4() {
    void *info = NULL;
    int nr_planes = 0;
    int nr_obstacole = 0;
    int *x = NULL, *y = NULL;
    int N = 0;

    scanf("%d", &nr_planes);
    info = init_info(nr_planes);
    scanf("%d", &nr_obstacole);

    read_obstacles(&x, &y, nr_obstacole);

    scanf("%d", &N);

    SolveTask4(info, nr_planes, nr_obstacole, x, y, N);
    free(info);
    free(x);
    free(y);
}
