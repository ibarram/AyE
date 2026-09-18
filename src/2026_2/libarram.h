#ifndef libarram_H
#define libarram_H

#define PI 3.1415926535

float suma(float a, float b);
int cambio(int E, int A, int B);
int chocolate(int X, int Y, int A, int B);
float potencia(float x, int n);
long int factorial(long int n);
float exp1(float x, int n);
float fct(float x, int n);
float exp3(float x, int n);
float exp4(float x, int n);
int swap(int *a, int *b);
int du_sr(int x[], int n, int max, int min, unsigned int seed);
int imprimir(int x[], int n);
float media(int x[], int n);
float varianza(int x[], int n);
int limite_inf(int x[], int n);
int limite_sup(int x[], int n);
int cardinalidad(int x[], int n);

#endif // libarram_H
