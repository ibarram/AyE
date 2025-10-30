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
#define N_C_MAX		7

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

typedef struct lt1{
	float x;
	struct lt1 *s;
}lt1;

typedef struct lt2{
	float x;
	struct lt2 *a, *s;
}lt2;

typedef struct lt_IHME{
	int measure_id;
	char *measure_name;
	int location_id;
	char *location_name;
	int sex_id;
	char *sex_name;
	int age_id;
	char *age_name;
	int cause_id;
	char *cause_name;
	int rei_id;
	char *rei_name;
	int metric_id;
	char *metric_name;
	int year;
	double val, upper, lower;
	struct lt_IHME *a, *s;
}lt_IHME;

typedef struct u_IHME{
	int id;
	char *name;
	struct u_IHME *a, *s;
}u_IHME;

typedef struct u_year{
	int y;
	struct u_year *a, *s;
}u_year;

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
int imprimir_lt(lt1 *plt);
int liberar_lt(lt1 *plt);
lt1* crearNodo(lt1 *plt);
lt1* unir_lt(lt1 *plt, lt1 *new, int op);
lt2* inicio(lt2 *plt);
lt2* fin(lt2 *plt);
int imprimir_lt2(lt2 *plt, int dir);
int liberar_lt2(lt2 *plt);
lt2* crearNodo2(lt2 *plt);
lt2* unir_lt2(lt2 *plt, lt2 *new, int op);
lt_IHME *read_csv2(FILE *fp);
int num_registros(lt_IHME *lt1);
lt_IHME *inicio_IHME(lt_IHME *lt1);
u_IHME *inicio_u_IHME(u_IHME *lt1);
int liberar_IHME(lt_IHME *lt1);
u_IHME *unique_IHME(lt_IHME *lt1, int indice);
u_year *inicio_year(u_year *lty);
int buscar_y(u_year *lty, int year);
int imprimir_u_year(u_year *lty);
int n_u_year(u_year *lty);
u_year *unique_year(lt_IHME *lt1);
int buscar_u_IHME(u_IHME *lt_u_IHME, int id);
int imprimir_u_IHME(u_IHME *lt_u_IHME);
int n_u_IHME(u_IHME *lt_u_IHME);
double consulta_IHME(lt_IHME *lt1, int val[]);
int reporte(char *reporte, char *figura);
int reporte_2(char reporte[]);

#endif // LIBARRAM_H