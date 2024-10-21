#ifndef LIBARRAM_H
#define LIBARRAM_H

#define PI 3.141592653589793
#define EMAIL_MX 255
#define EMAIL_PL 63
#define N_CE 19
#define CE (char[N_CE]){'!','#','$','%','&','\'','*','+','/','=','?','^','_','{','|','}','~','"','\0'}
#define NS 256
#define INTER(x,y){x^=y;y^=x;x^=y;}

typedef struct Z
{
	float a;
	float b;
}Z;

typedef union dato{
	float f;
	int i;
	char c[4];
}dato;

float dist_norm(float md, float de);
float suma_x2(float x[], float md, int n);
float varianza2(float x[], int n);
float varianza1(float x[], int n);
int imprimir2(float x[], int n);
float suma_x(float x[], int n);
float media2(float x[], int n);
float media1(float x[], int n);
void generar(float x[], int n, float min, float max);
void imprimir(float x[], int n);
float suma(float a, float b);
int cambio(int E, int A, int B);
int chocolate(int X, int Y, int A, int B);
float potencia(float x, int n);
long int factorial(long int n);
float exp1(float x, int n);
float fct(float x, int n);
float exp3(float x, int n);
float exp4(float x, int n);
int validar(char email[]);
int isce(char c);
int ispnt(char c);
int KSA(unsigned char *clave, unsigned char *S);
int PRGA(unsigned char *S, unsigned char *msg, unsigned char *msg2);
int RC4_cod(unsigned char *clave, unsigned char *msg, unsigned char *msg2);
Z capturarZ(void);
Z sumaZ(Z Z1, Z Z2);
Z multiplicaZ(Z Z1, Z Z2);
Z conjZ(Z Z1);
Z invZ(Z Z1);
Z divZ(Z Z1, Z Z2);
float magZ(Z Z1);
float angZ(Z Z1);

#endif
