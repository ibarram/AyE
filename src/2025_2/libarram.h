#ifndef LIBARRAM_H
#define LIBARRAM_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SWAP(a, b) {\
		a^=b;\
		b^=a;\
		a^=b;\
		}
#define N_MAX 		254
#define N_local 	64
#define N_dominio	255
#define N_punto		63

typedef struct{
	float a, b;
}Complejo;

//float suma(float a, float b);
//long int factorial(long int n);
int cambio(int E, int A, int B);
int chocolate(int X, int Y, int A, int B);
float potencia(float x, int n);
long int factorial(long int n);
float exp1(float x, int n);
float factor(float x, int n);
float exp3(float x, int n);
float exp4(float x, int n);
int* DU(int n, int min, int max);
void imprimir_DU(int *d, int n);
int suma(int *x, int n);
int suma2(int *x, int n);
float media(int *x, int n);
float media2(int *x, int n);
float varianza(int *x, int n);
float varianza2(int *x, int n);
int estInf(float md, float vr);
int estSup(float md, float vr);
int estN(int *x, int n);
int esValido(char str[]);
int RC4(char msg_1[], char clave[], char msg_2[]);
Complejo sumaC(Complejo Z1, Complejo Z2);

#endif // LIBARRAM_H