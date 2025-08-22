/*
10_Ejemplo.c es el de la grafica, el actual es de las tallas
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../include/ldan-dev.h"

#define N 2000
#define pi 3.14159

int main(int argc, char const *argv[]) {
    int T[4] = {155, 165, 175, 185};
    int X[N], i, M[5] = {0, 0, 0, 0, 0}, j, k0, k1;
    int md = 170, s = 10;
    float Z0, Z1, U0, U1;
    srand(time(NULL));
    for(i=0; i<N/2; i++)
    {
        U0 = rand();
        U1 = rand();
        Z0 = sqrt(-2*log(U0/RAND_MAX))*cos(2*pi*(U1/RAND_MAX));
        Z1 = sqrt(-2*log(U0/RAND_MAX))*sin(2*pi*(U1/RAND_MAX));
        Z0 = md+s*Z0;
        Z1 = md+s*Z1;
        for(j=0, k0=0, k1=0; j<4; j++)
        {
            k0+=(Z0<T[j]);
            k1+=(Z1<T[j]);
        }
        M[k0]++;
        M[k1]++;
    }
    printf("XS: %d S: %d M: %d, L: %d XL: %d", M[0], M[1], M[2], M[3], M[4]);
    return 0;
}
