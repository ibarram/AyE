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
#define N_MAX_C		30
#define N_CURP		19
#define N_INEGI		200

typedef struct{
	float a, b;
}Complejo;

typedef enum{
	H, M
}Genero;

typedef struct{
	int dia;
	int mes;
	int anio;
}FN;

typedef struct{
	char AP[N_MAX_C];
	char AM[N_MAX_C];
	char Nom[N_MAX_C];
	FN fecha;
	char E[3];
	Genero G;
	char curp[N_CURP];
}CURP;

typedef struct{
	int cve_entidad;
	char desc_entidad[N_INEGI];
	int cve_municipio;
	char desc_municipio[N_INEGI];
	long int id_indicador;
	char indicador[N_INEGI];
	int anio;
	double valor;
	char unidad_medida[N_INEGI/10];
}INEGI_CSV;

typedef struct{
	FILE *fp;
	long int nr;
	INEGI_CSV *data;
}INEGI;

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
CURP capturarCURP(void);
void imprimirCURP(CURP X);
CURP generarCURP(CURP X);
float** CrearMatrizO(int n, int m);
float** CrearMatrizD(int n, int m);
void liberarO(float **X);
void liberarD(float **X, int n);
void imprimirMat(float **X, int n, int m, char *str);
float **multiplicarMat(float **X, int nX, int mX, float **Y, int nY, int mY);
void capturarMat(float **X, int nX, int mX, char *str);
int read_csv(INEGI *info);
double consulta(INEGI *info, int cve_entidad, int cve_municipio, long int id_indicador, int anio);

#endif // LIBARRAM_H