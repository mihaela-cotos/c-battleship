#include "../utils/utils.h"

void readPlanes(void *info, unsigned short *a, unsigned short *b,
                            unsigned char *d, unsigned char *t) {
                                
    unsigned short *short_info = info;
    *a = *short_info;
    *b = *(short_info + 1);

    unsigned char *char_info = info;
    *d = *(char_info + OFFSET_CHAR - 1);

    unsigned char cod[COD_SIZE];
    for (int i = 0; i < COD_SIZE - 1; i++) {
        cod[i] = *(char_info + OFFSET_CHAR + i);
    }
    cod[COD_SIZE - 1] = '\0';
    *t = cod[0];
}

void DrawPlane_1N(unsigned short Line, unsigned short Column, char **mat) {
    unsigned short i = Line;
    unsigned short j = Column;
    mat[Line][Column] = '*';

    i++;
    for (j = Column - 2; j <= Column + 2; j++) {
        mat[i][j] = '*';
    }

    i++;
    j = Column;
    mat[i][j] = '*';

    i++;
    for (j = Column - 1; j <= Column + 1; j++) {
        mat[i][j] = '*';
    }
}

void DrawPlane_1S(unsigned short Line, unsigned short Column, char **mat) {
    int i = (int)Line;
    int j = (int)Column;
    mat[i][j] = '*';

    i--;
    for (j = Column - 2; j <= Column + 2; j++) {
        mat[i][j] = '*';
    }

    i--;
    j = Column;
    mat[i][j] = '*';

    i--;
    for (j = Column - 1; j <= Column + 1; j++) {
        mat[i][j] = '*';
    }
}

void DrawPlane_1E(unsigned short Line, unsigned short Column, char **mat) {
    int i = (int) Line;
    int j = (int) Column;
    mat[i][j] = '*';

    j--;
    for (i = Line - 2; i <= Line + 2; i++) {
        mat[i][j] = '*';
    }

    j--;
    i = Line;
    mat[i][j] = '*';

    j--;
    for (i = Line - 1; i <= Line + 1; i++) {
        mat[i][j] = '*';
    }
}

void DrawPlane_1W(unsigned short Line, unsigned short Column, char **mat) {
    int i = (int) Line;
    int j = (int) Column;
    mat[i][j] = '*';

    j++;
    for (i = Line - 2; i <= Line + 2; i++) {
        mat[i][j] = '*';
    }

    j++;
    i = Line;
    mat[i][j] = '*';

    j++;
    for (i = Line - 1; i <= Line + 1; i++) {
        mat[i][j] = '*';
    }
}

void DrawPlane_2N(unsigned short Line, unsigned short Column, char **mat) {
    int i = (int) Line;
    int j = (int) Column;
    mat[i][j] = '*';

    i++;
    for (j = Column - 1; j <= Column + 1; j++) {
        mat[i][j] = '*';
    }

    i++;
    for (j = Column - 3; j <= Column + 3; j++) {
        mat[i][j] = '*';
    }

    i++;
    j = Column;
    mat[i][j] = '*';

    i++;
    for (j = Column - 2; j <= Column + 2; j++) {
        mat[i][j] = '*';
    }
}

void DrawPlane_2S(unsigned short Line, unsigned short Column, char **mat) {
    int i = (int) Line;
    int j = (int) Column;
    mat[i][j] = '*';

    i--;
    for (j = Column - 1; j <= Column + 1; j++) {
        mat[i][j] = '*';
    }

    i--;
    for (j = Column - 3; j <= Column + 3; j++) {
        mat[i][j] = '*';
    }

    i--;
    j = Column;
    mat[i][j] = '*';

    i--;
    for (j = Column - 2; j <= Column + 2; j++) {
        mat[i][j] = '*';
    }
}

void DrawPlane_2E(unsigned short Line, unsigned short Column, char **mat) {
    int i = (int) Line;
    int j = (int) Column;
    mat[i][j] = '*';

    j--;
    for (i = Line - 1; i <= Line + 1; i++) {
        mat[i][j] = '*';
    }

    j--;
    for (i = Line - 3; i <= Line + 3; i++) {
        mat[i][j] = '*';
    }

    j--;
    i = Line;
    mat[i][j] = '*';

    j--;
    for (i = Line - 2; i <= Line + 2; i++) {
        mat[i][j] = '*';
    }
}

void DrawPlane_2W(unsigned short Line, unsigned short Column, char **mat) {
    int i = (int) Line;
    int j = (int) Column;
    mat[i][j] = '*';

    j++;
    for (i = Line - 1; i <= Line + 1; i++) {
        mat[i][j] = '*';
    }

    j++;
    for (i = Line - 3; i <= Line + 3; i++) {
        mat[i][j] = '*';
    }

    j++;
    i = Line;
    mat[i][j] = '*';

    j++;
    for (i = Line - 2; i <= Line + 2; i++) {
        mat[i][j] = '*';
    }
}

void Radar_N1(char **new_mat, int N, unsigned short L,
    unsigned short C, int *P) {
    int obs = 0;
    unsigned short i = 0, j = 0;
    for (i = 0; i <= L + 1; i++) {  // partea din fata
        for (j = C - 2; j <= C + 2; j++) {
            if (new_mat[i][j] == '@') {
                obs = 1;
            }
        }
    }
    for (i = L + 2; i <= L + 3; i++) {  // partea din spate
        for (j = C - 1; j <= C + 1; j++) {
            if (new_mat[i][j] == '@') {
                obs = 1;
            }
        }
    }
    if (obs == 1) {
        (*P)--;
    }
}

void Radar_N2(char **new_mat, int N, unsigned short L,
    unsigned short C, int *P) {
    int obs = 0;
    unsigned short i = 0, j = 0;
    for (i = 0; i <= L + 2; i++) {
        for (j = C - 3; j <= C + 3; j++) {
            if (new_mat[i][j] == '@') {
                obs = 1;
            }
        }
    }
    for (i = L + 3; i <= L + 4; i++) {
        for (j = C - 2; j <= C + 2; j++) {
            if (new_mat[i][j] == '@') {
                obs = 1;
            }
        }
    }
    if (obs == 1) {
        (*P)--;
    }
}

void Radar_S1(char **new_mat, int N, unsigned short L,
    unsigned short C, int *P) {
    int obs = 0;
    unsigned short i = 0, j = 0;
    for (i = L - 1; i < N; i++) {
        for (j = C - 2; j <= C + 2; j++) {
            if (new_mat[i][j] == '@') {
                obs = 1;
            }
        }
    }

    for (i = L - 3; i <= L - 2; i++) {
        for (j = C - 1; j <= C + 1; j++) {
            if (new_mat[i][j] == '@') {
                obs = 1;
            }
        }
    }

    if (obs == 1) {
        (*P)--;
    }
}

void Radar_S2(char **new_mat, int N, unsigned short L,
    unsigned short C, int *P) {
    int obs = 0;
    unsigned short i = 0, j = 0;
    for (i = L - 2; i < N; i++) {
        for (j = C - 3; j <= C + 3; j++) {
            if (new_mat[i][j] == '@') {
                obs = 1;
            }
        }
    }

    for (i = L - 4; i <= L - 3; i++) {
        for (j = C - 2; j <= C + 2; j++) {
            if (new_mat[i][j] == '@') {
                obs = 1;
            }
        }
    }

    if (obs == 1) {
        (*P)--;
    }
}

void Radar_E1(char **new_mat, int N, unsigned short L,
    unsigned short C, int *P) {
    int obs = 0;
    unsigned short i = 0, j = 0;
    for (i = L - 2; i <= L + 2; i++) {
        for (j = C - 1; j < N; j++) {
            if (new_mat[i][j] == '@') {
                obs = 1;
            }
        }
    }
    for (i = L - 1; i <= L + 1; i++) {
        for (j = C - 3; j <= C - 2; j++) {
            if (new_mat[i][j] == '@') {
                obs = 1;
            }
        }
    }

    if (obs == 1) {
        (*P)--;
    }
}

void Radar_E2(char **new_mat, int N, unsigned short L,
    unsigned short C, int *P) {
    int obs = 0;
    unsigned short i = 0, j = 0;
    for (i = L - 3; i <= L + 3; i++) {
        for (j = C - 2; j < N; j++) {
            if (new_mat[i][j] == '@') {
                obs = 1;
            }
        }
    }
    for (i = L - 2; i <= L + 2; i++) {
        for (j = C - 4; j <= C - 3; j++) {
            if (new_mat[i][j] == '@') {
                obs = 1;
            }
        }
    }
    if (obs == 1) {
        (*P)--;
    }
}

void Radar_W1(char **new_mat, int N, unsigned short L,
    unsigned short C, int *P) {
    int obs = 0;
    unsigned short i = 0, j = 0;
    for (i = L - 2; i <= L + 2; i++) {
        for (j = 0; j <= C + 1; j++) {
            if (new_mat[i][j] == '@') {
                obs = 1;
            }
        }
    }
    for (i = L - 1; i <= L + 1; i++) {
        for (j = C + 2; j <= C + 3; j++) {
            if (new_mat[i][j] == '@') {
                obs = 1;
            }
        }
    }

    if (obs == 1) {
        (*P)--;
    }
}

void Radar_W2(char **new_mat, int N, unsigned short L,
    unsigned short C, int *P) {
    int obs = 0;
    unsigned short i = 0, j = 0;
    for (i = L - 3; i <= L + 3; i++) {
        for (j = 0; j <= C + 2; j++) {
            if (new_mat[i][j] == '@') {
                obs = 1;
            }
        }
    }
    for (i = L - 2; i <= L + 2; i++) {
        for (j = C + 3; j <= C + 4; j++) {
            if (new_mat[i][j] == '@') {
                obs = 1;
            }
        }
    }

    if (obs == 1) {
        (*P)--;
    }
}
