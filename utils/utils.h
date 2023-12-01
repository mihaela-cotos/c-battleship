#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define OFFSET_CHAR 5
#define COD_SIZE 5
#define OFFSET_INT 9
#define PLANE_SIZE 13

void readPlanes(void *info, unsigned short *a, unsigned short *b, unsigned char *d, unsigned char *t);

void DrawPlane_1N(unsigned short Line, unsigned short Column, char **mat);
void DrawPlane_1S(unsigned short Line, unsigned short Column, char **mat);
void DrawPlane_1E(unsigned short Line, unsigned short Column, char **mat);
void DrawPlane_1W(unsigned short Line, unsigned short Column, char **mat);
void DrawPlane_2N(unsigned short Line, unsigned short Column, char **mat);
void DrawPlane_2S(unsigned short Line, unsigned short Column, char **mat);
void DrawPlane_2E(unsigned short Line, unsigned short Column, char **mat);
void DrawPlane_2W(unsigned short Line, unsigned short Column, char **mat);

void Radar_N1(char **new_mat, int N, unsigned short L, unsigned short C, int *P);
void Radar_N2(char **new_mat, int N, unsigned short L, unsigned short C, int *P);
void Radar_S1(char **new_mat, int N, unsigned short L, unsigned short C, int *P);
void Radar_S2(char **new_mat, int N, unsigned short L, unsigned short C, int *P);
void Radar_E1(char **new_mat, int N, unsigned short L, unsigned short C, int *P);
void Radar_E2(char **new_mat, int N, unsigned short L, unsigned short C, int *P);
void Radar_W1(char **new_mat, int N, unsigned short L, unsigned short C, int *P);
void Radar_W2(char **new_mat, int N, unsigned short L, unsigned short C, int *P);

void SolveTask1(void *info, int nr_avioane);
void SolveTask2(void *info, int nr_avioane, int N, char **mat);
void SolveTask3(void *info, int nr_avioane);
void SolveTask4(void *info, int nr_avioane, int nr_obstacole, int *x, int *y, int N);

void *init_info(int nr_avioane);
int *init_vector(int N);
char** init_mat(int N);
void free_mat(char **mat, int N);

void Task1();
void Task2();
void Task3();
void Task4();
