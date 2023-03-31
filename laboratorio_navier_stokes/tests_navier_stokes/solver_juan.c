#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

#include "solver_juan.h"

/*
Función para acceder al indice correcto de memoria de los 
arreglos usados para almacenar los valores de la grilla.    
*/

static int N = 5;

#define IX(i, j) (i + (N + 2) * j)
// #define SWAP(x0, x) {
//     float* tmp = x0;
//     x0 = x;
//     x = tmp;
// }

typedef enum {
    NONE = 0,
    VERTICAL = 1,
    HORIZONTAL = 2 
} boundary;

static void set_bnd(unsigned int n, boundary b, float* x) {

    for (unsigned int i = 1; i <= n; i++) {
        x[IX(0, i)] = b == VERTICAL ? -x[IX(1, i)] : x[IX(1, i)];
        x[IX(n + 1, i)] = b == VERTICAL ? -x[IX(n, i)] : x[IX(n, i)];
        x[IX(i, 0)] = b == HORIZONTAL ? -x[IX(i, 1)] : x[IX(i, 1)];
        x[IX(i, n + 1)] = b == HORIZONTAL ? -x[IX(i, n)] : x[IX(i, n)];
    }
    x[IX(0, 0)] = 0.5f * (x[IX(0, 1)] + x[IX(1, 0)]);
    x[IX(0, n + 1)] = 0.5f * (x[IX(0, n)] + x[IX(1, n + 1)]);
    x[IX(n + 1, 0)] = 0.5f * (x[IX(n + 1, 1)] + x[IX(n, 0)]);
    x[IX(n + 1, n + 1)] = 0.5f * (x[IX(n + 1, n)] + x[IX(n, n + 1)]);
}

static void lin_solve(unsigned int n, boundary b, float* x, const float* x0, float a, float c)
{
    unsigned int i, j, k;
    for (k = 0; k < 20; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                x[IX(i, j)] = (x0[IX(i, j)] + a * (x[IX(i - 1, j)] + x[IX(i + 1, j)] + x[IX(i, j - 1)] + x[IX(i, j + 1)])) / c;
            }
        }
        printf("==============================\n");
        printf("Iteration n: %d\n", k);
        printf("%f  %f  %f  %f  %f\n", x[IX(1,1)], x[IX(2,1)], x[IX(3,1)], x[IX(4,1)], x[IX(5,1)]);
        printf("\n");
        printf("%f  %f  %f  %f  %f\n", x[IX(1,2)], x[IX(2,2)], x[IX(3,2)], x[IX(4,2)], x[IX(5,2)]);
        printf("\n");
        printf("%f  %f  %f  %f  %f\n", x[IX(1,3)], x[IX(2,3)], x[IX(3,3)], x[IX(4,3)], x[IX(5,3)]);
        printf("\n");
        printf("%f  %f  %f  %f  %f\n", x[IX(1,4)], x[IX(2,4)], x[IX(3,4)], x[IX(4,4)], x[IX(5,4)]);
        printf("\n");
        printf("%f  %f  %f  %f  %f\n", x[IX(1,5)], x[IX(2,5)], x[IX(3,5)], x[IX(4,5)], x[IX(5,5)]);
        printf("==============================\n");
        set_bnd(n, b, x);
    }
}

static void diffuse(unsigned int n, boundary b, float* x, const float* x0, float diff, float dt)
{
    float a = dt * diff * n * n;
    lin_solve(n, b, x, x0, a, 1 + 4 * a);
}

static void advect(unsigned int n, boundary b, float* d, const float* u, const float* v, float dt)
{
    int i0, i1, j0, j1;
    float x, y, s0, t0, s1, t1;
    float dt0 = dt * n;

    for (unsigned int i = 1; i <= n; i++){
        for (unsigned int j = 1; j <= n; j++) {
            x = i - dt0 * u[IX(i, j)];
            y = j - dt0 * v[IX(i, j)];
            if (x < 0.5f) {
                x = 0.5f;
            }
            else if (x > n + 0.5f) {
                x = n + 0.5f;
            }
            i0 = (int)x;
            i1 = i0 + 1;
            if (y < 0.5f) {
                y = 0.5f;
            }
            else if (y > n + 0.5f) {
                y = n + 0.5f;
            }
            j0 = (int)y;
            j1 = j0 + 1;
            s1 = x - i0;
            s0 = 1 - s1;
            t1 = y - j0;
            t0 = 1 - t1;
            d[IX(i, j)] = s0 * (t0 * d0[IX(i0, j0)] + t1 * d0[IX(i0, j1)]) /
                        + s1 * (t0 * d0[IX(i1, j0)] + t1 * d0[IX(i1, j1)]);
        }
    }
    set_bnd(n, b, d);
}


void main(void) {
    float* x_1;
    float* x_0;

    float dt = 0.1f;
    float diff = 0.0f;


    int size = (N + 2) * (N + 2);

    x_0 = (float*)malloc(size * sizeof(float));
    x_1 = (float*)malloc(size * sizeof(float));

    srand((unsigned int) time(NULL));

    for (unsigned int i = 0; i <= N + 1; i++) {
        for (unsigned int j = 0; j <= N + 1; j++) {
            x_0[IX(i, j)] = ((float) rand())/ ((float) (RAND_MAX));
            x_1[IX(i, j)] = 10.f * ((float) rand())/ ((float) (RAND_MAX));   
        }
    }

    printf("==============================\n");
    printf("Initial state\n");
    printf("%f  %f  %f  %f  %f\n", x_1[IX(1,1)], x_1[IX(2,1)], x_1[IX(3,1)], x_1[IX(4,1)], x_1[IX(5,1)]);
    printf("\n");
    printf("%f  %f  %f  %f  %f\n", x_1[IX(1,2)], x_1[IX(2,2)], x_1[IX(3,2)], x_1[IX(4,2)], x_1[IX(5,2)]);
    printf("\n");
    printf("%f  %f  %f  %f  %f\n", x_1[IX(1,3)], x_1[IX(2,3)], x_1[IX(3,3)], x_1[IX(4,3)], x_1[IX(5,3)]);
    printf("\n");
    printf("%f  %f  %f  %f  %f\n", x_1[IX(1,4)], x_1[IX(2,4)], x_1[IX(3,4)], x_1[IX(4,4)], x_1[IX(5,4)]);
    printf("\n");
    printf("%f  %f  %f  %f  %f\n", x_1[IX(1,5)], x_1[IX(2,5)], x_1[IX(3,5)], x_1[IX(4,5)], x_1[IX(5,5)]);
    printf("==============================\n");
}