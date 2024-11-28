#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "libarram.h"

float dist_norm(float md, float de)
{
	float U1, U2, Z1;
	U1 = (float)rand()/RAND_MAX;
	U2 = (float)rand()/RAND_MAX;
	Z1 = sqrt(-2*log(U1))*sin(2*PI*U2);
	return (Z1*de+md);
}

int imprimir2(float x[], int n)
{
	printf("%f\n", x[0]);
	if(n-1)
		return imprimir2(x+1, n-1);
	else
		return 0;
}

float suma_x(float x[], int n)
{
	//return n-1?x[0]+suma_x(x+1,n-1):x[0];
	if(n-1)
		return x[0]+suma_x(x+1,n-1);
	else
		return x[0];
}

float media2(float x[], int n)
{
	return suma_x(x, n)/n;
}

float media1(float x[], int n)
{
	int i;
	float md;
	for(i=1, md=x[0]; i<n; i++)
		md+=x[i];
	return md/n;
}

float suma_x2(float x[], float md, int n)
{
	if(n-1)
		return (x[0]-md)*(x[0]-md)+suma_x2(x+1, md, n-1);
	else
		return (x[0]-md)*(x[0]-md);
}

float varianza2(float x[], int n)
{
	float md;
	md = media2(x, n);
	return suma_x2(x, md, n)/(n-1);
}

float varianza1(float x[], int n)
{
	int i;
	float md, vr;
	for(i=0, md = media1(x, n), vr=0; i<n; i++)
		vr+=((x[i]-md)*(x[i]-md));
	return vr/(n-1);
}

void generar(float x[], int n, float min, float max)
{
	int i;
	for(i=0; i<n; i++)
		x[i] = (max-min)*((float)rand())/RAND_MAX+min;
}

void imprimir(float x[], int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("x[%d] = %f\n", i+1, x[i]);
}

float suma(float a, float b)
{
	return a+b;
}

int cambio(int E, int A, int B)
{
	int Zi;
	Zi = (E/A)*B;
	return Zi?Zi+cambio(Zi+E-(Zi*A)/B,A,B):0;
}

int chocolate(int X, int Y, int A, int B)
{
	return X/Y+cambio(X/Y,A,B);
}

float potencia(float x, int n)
{
	return n?x*potencia(x,n-1):1;
}

long int factorial(long int n)
{
	return n?n*factorial(n-1):1;
}

float exp1(float x, int n)
{
	return n?potencia(x,n)/factorial(n)+exp1(x,n-1):1;
}

float fct(float x, int n)
{
	return n?(x/n)*fct(x,n-1):1;
}

float exp3(float x, int n)
{
	return n?fct(x,n)+exp3(x,n-1):1;
}

float exp4(float x, int n)
{
	static float fct1=1;
	static int i=0;
	fct1*=(x/(i+1));
	if(n-i++)
		return fct1+exp4(x,n);
	else
	{
		fct1=1;
		i=0;
		return 1;
	}
}

int isce(char c)
{
	static int i = 0;
	if(c==CE[i])
	{
		i=0;
		return 1;
	}
	else if(CE[i]!='\0')
	{
		i++;
		return isce(c);
	}
	else
	{
		i=0;
		return 0;
	}
}

int ispnt(char c)
{
	static int i=-1, j=-1;
	i++;
	if(c=='.'&&i)
	{
		if((j+1)==i)
			return 0;
		else
		{
			j = i;
			return 1;
		}
	}
	else
		return 0;
}

int validar(char email[])
{
	int nc, da, i, nce;
	char *bc;
	nc = strlen(email);
	if(nc>EMAIL_MX)
		return 0;
	bc = strchr(email, '@');
	if(bc==NULL)
		return 0;
	da = (int)(bc-email);
	if(da>EMAIL_PL)
		return 0;
	for(i=0; i<da; i++)
		if(!ispnt(email[i])&&!isalnum(email[i])&&!isce(email[i]))
			return 0;
	return 1;
}

int KSA(unsigned char *clave, unsigned char *S)
{
	unsigned int i, j, NC;
	for(i=0; i<NS; i++)
		S[i]=i;
	NC = strlen((char*)clave);
	for(i=0, j=0; i<NS; i++)
	{
		j = (j+S[i]+clave[i%NC])%NS;
		if(i!=j)
			INTER(S[i], S[j]);
	}
	return 0;
}

int PRGA(unsigned char *S, unsigned char *msg, unsigned char *msg2)
{
	unsigned int i, j, k, NM;
	NM = strlen((char*)msg);
	for(k=0, i=0, j=0; k<NM; k++)
	{
		i = (i+1)%NS;
		j = (j+S[i])%NS;
		if(i!=j)
			INTER(S[i], S[j]);
		msg2[k]=msg[k]^(S[(S[i]+S[j])%NS]);
	}
	msg2[k]='\0';
	return 0;
}

int RC4_cod(unsigned char *clave, unsigned char *msg, unsigned char *msg2)
{
	unsigned char S[NS];
	KSA(clave, S);
	PRGA(S, msg, msg2);
	return 0;
}

Z capturarZ(void)
{
	Z Z1;
	printf("Real: ");
	scanf("%f", &(Z1.a));
	printf("Imaginaria: ");
	scanf("%f", &(Z1.b));
	return Z1;
}

Z sumaZ(Z Z1, Z Z2)
{
	Z Z3;
	Z3.a = Z1.a+Z2.a;
	Z3.b = Z1.b+Z2.b;
	return Z3;
}

Z multiplicaZ(Z Z1, Z Z2)
{
	Z Z3;
	Z3.a = Z1.a*Z2.a-Z1.b*Z2.b;
	Z3.b = Z1.a*Z2.b+Z1.b*Z2.a;
	return Z3;
}

Z conjZ(Z Z1)
{
	Z Z3;
	Z3.a = Z1.a;
	Z3.b = -Z1.b;
	return Z3;
}

Z invZ(Z Z1)
{
	Z Z3;
	float r = Z1.a*Z1.a+Z1.b*Z1.b;
	if(r)
	{
		Z3.a = Z1.a/r;
		Z3.b = -Z1.b/r;
	}
	else
	{
		Z3.a = 0;
		Z3.b = 0;
	}
	return Z3;
}

Z divZ(Z Z1, Z Z2)
{
	return multiplicaZ(Z1, invZ(Z2));
}

float magZ(Z Z1)
{
	return sqrt(pow(Z1.a,2)+pow(Z1.b,2));
}

float angZ(Z Z1)
{
	return atanf(Z1.b/Z1.a);
}

float **crearMC(int NR, int NC)
{
	float **A, *pA;
	int i;
	pA = (float*)malloc(NC*NR*sizeof(float));
	if(pA==NULL)
		return NULL;
	A = (float**)malloc(NR*sizeof(float*));
	if(A==NULL)
	{
		free(pA);
		return NULL;
	}
	for(i=0; i<NR; i++)
		A[i] = pA+i*NC;
	return A;
}

float **crearMD(int NR, int NC)
{
	float **A;
	int i;
	A = (float**)malloc(NR*sizeof(float*));
	if(A==NULL)
		return NULL;
	for(i=0; i<NR; i++)
	{
		A[i] = (float*)malloc(NC*sizeof(float));
		if(A[i]==NULL)
		{
			for(i--;i<-1; i--)
				free(A[i]);
			free(A);
			return NULL;
		}
	}
	return A;
}

int liberarC(float **A)
{
	free(A[0]);
	free(A);
	return 0;
}

int liberarD(float **A, int NR)
{
	int i;
	for(i=0; i<NR; i++)
		free(A[i]);
	free(A);
	return 0;
}

int liberarD2(float **A, int NR)
{
	free(A[NR-1]);
	if(NR-1)
		return liberarD2(A, NR-1);
	else
	{
		free(A);
		return 0;
	}
}

/*
int multiplicar(float **A, float **B, float **C, int NR, int NC, int MR, int MC)
{
	int i, j, k;
	float aux1, aux2, aux3;
	if(NC!=MR)
		return 1;
	for(i=0; i<NR; i++)
		for(j=0; j<MC; j++)
			for(k=0, aux3=0; k<NC; k++) // *(*(C+j)+i)=0
			{
				aux1 = A[i][k];
				aux2 = B[k][j];
				aux3 += aux1*aux2;
				printf("aux1 = %.2f\taux2 = %.2f\taux3 = %.2f\n", aux1, aux2, aux3);
				printf("%p\n", A[i]);
				printf("%p\n", B[k]);
				printf("%p\n", C[i]);
				C[i][j] = aux3;
			}
	return 0;
}
*/
int multiplicar(float **A, float **B, float **C, int NR, int NC, int MR, int MC)
{
	int i, j, k;
	if(NC!=MR)
		return 1;
	for(i=0; i<NR; i++)
		for(j=0; j<MC; j++)
			for(k=0, C[i][j]=0; k<NC; k++) // *(*(C+j)+i)=0
				C[i][j] += A[i][k]*B[k][j];
	return 0;
}

void capturarM(float **A, int NR, int NC)
{
	int i, j;
	for(i=0; i<NR; i++)
		for(j=0; j<NC; j++)
		{
			printf("A[%d][%d] = ", i+1, j+1);
			scanf("%f", A[i]+j); // &(*(*(A+j)+i))=&(*(A[j]+i))=A[j]+i
		}
}

void imprimirM(float **A, int NR, int NC)
{
	int i, j;
	for(i=0; i<NR; i++)
	{
		for(j=0; j<NC; j++)
			printf("%.4f\t", A[i][j]);
		printf("\n");
	}
}

long int num_registros(char *file_name)
{
	FILE *fp;
	int nc, ncl, flag;
	char c;
	long int nr;
	fp = fopen(file_name, "rt");
	if(fp==NULL)
		return 0;
	fflush(fp);
	nc=0;
	do{
		c = getc(fp);
		if(c==',')
			nc++;
	}while(c!='\n');
	c = getc(fp);
	ncl = 0;
	nr = 0;
	flag = 1;
	while(c!=EOF)
	{
		if((c==',')&flag)
			ncl++;
		if(c=='"')
			flag = !flag;
		if(c=='\n')
		{
			if(ncl==nc)
				nr++;
			ncl = 0;
		}
		c = getc(fp);
	}
	fclose(fp);
	return  nr;
}

int lectura_bd(char *file_name, bd_INEGI *Datos)
{
	int nc, *realloc_nid;
	long int nr, i, j, k, l, flag, np, *realloc_id, **realloc_id_d;
	char **palabra;
	float fct;
	char buffer[MAX_STR], c, **realloc_dic;
	estados estado[9] = {conv_entero, cadena_s, conv_entero, cadena_d, 
		conv_enterol, cadena_i, conv_entero, conv_enterol, sincronizacion};
	FILE *fp;
	nr = num_registros(file_name);
	if(nr==0)
		return 1;
	fp = fopen(file_name, "rt");
	if(fp==NULL)
		return 2;
	ini_bd(Datos);
	Datos->nr = nr;
	Datos->mem = (int*)malloc(3*nr*sizeof(int)+2*nr*sizeof(long int));
	if(Datos->mem==NULL)
	{
		fclose(fp);
		return 3;
	}
	fct = (1.0*sizeof(long int))/sizeof(int);
	Datos->cve_entidad=Datos->mem;
	Datos->mem+=nr;
	Datos->cve_municipio=Datos->mem;
	Datos->mem+=nr;
	Datos->id_indicador=(long int*)(Datos->mem);
	Datos->mem+=((int)(fct*nr));
	Datos->anio=Datos->mem;
	Datos->mem+=nr;
	Datos->valor=(long int*)(Datos->mem);
	Datos->mem=Datos->cve_entidad;
	Datos->desc_entidad.palabra = (char**)malloc(nr*sizeof(char*));
	if(Datos->desc_entidad.palabra==NULL)
	{
		liberar_mem(Datos);
		fclose(fp);
		return 4;
	}
	Datos->desc_entidad.np = 0;
	Datos->desc_municipio.palabra = (char**)malloc(nr*sizeof(char*));
	if(Datos->desc_municipio.palabra==NULL)
	{
		liberar_mem(Datos);
		fclose(fp);
		return 5;
	}
	Datos->desc_municipio.np = 0;
	Datos->desc_municipio.id = (long int**)malloc(nr*sizeof(long int*));
	if(Datos->desc_municipio.id==NULL)
	{
		liberar_mem(Datos);
		fclose(fp);
		return 6;
	}
	Datos->desc_municipio.ntid = 0;
	Datos->desc_municipio.nid = (int*)calloc(nr,sizeof(int));
	if(Datos->desc_municipio.nid==NULL)
	{
		liberar_mem(Datos);
		fclose(fp);
		return 7;
	}
	Datos->indicador.palabra = (char**)malloc(nr*sizeof(char*));
	if(Datos->indicador.palabra==NULL)
	{
		liberar_mem(Datos);
		fclose(fp);
		return 8;
	}
	Datos->indicador.id = (long int*)malloc(nr*sizeof(long int));
	if(Datos->indicador.id==NULL)
	{
		liberar_mem(Datos);
		fclose(fp);
		return 9;
	}
	Datos->indicador.np = 0;
	printf("Numero de registros: %ld\n", Datos->nr);
	do{
		c=getc(fp);
	}while(c!='\n');
	for(i=0; i<Datos->nr; i++)
	{
		Datos->mem = Datos->cve_entidad;
		for(k=0; k<9; k++)
		{
			j = 0;
			flag = 0;
			do{
				buffer[j++] = getc(fp);
				if(buffer[j-1]=='"')
					flag = !flag;
			}while(flag||(buffer[j-1]!=(estado[k]==sincronizacion?'\n':',')));
			buffer[j-1] = '\0';
			nc = strlen(buffer);
			switch(estado[k])
			{
			case conv_entero:
				Datos->mem[i] = atoi(buffer);
				Datos->mem+=nr;
				break;
			case conv_enterol:
				Datos->mem[(int)(fct*i)] = atol(buffer);
				Datos->mem+=(int)(fct*nr);
				break;
			case cadena_s:
			case cadena_i:
				np = estado[k]==cadena_s?Datos->desc_entidad.np:Datos->indicador.np;
				palabra = estado[k]==cadena_s?Datos->desc_entidad.palabra:Datos->indicador.palabra;
				flag = !np;
				if(np)
				{
					j=0;
					while(strcmp(palabra[j++], buffer))
						if(j==np)
						{
							flag=1;
							break;
						}
				}
				if(flag)
				{
					palabra[np] = (char*)malloc((nc+1)*sizeof(char));
					if(palabra[np]==NULL)
					{
						for(j=0; j<np; j++)
							free(palabra[j]);
						liberar_mem(Datos);
						fclose(fp);
						return 10;
					}
					strcpy(palabra[np], buffer);
					if(estado[k]==cadena_i)
						Datos->indicador.id[np] = Datos->id_indicador[i];
					estado[k]==cadena_s?Datos->desc_entidad.np++:Datos->indicador.np++;
				}
				break;
			case cadena_d:
				if(Datos->cve_entidad[i]==36)
					l = 33;
				else if(Datos->cve_entidad[i]==99)
					l = 34;
				else
					l = Datos->cve_entidad[i];
				flag = !(Datos->desc_municipio.np);
				j=0;
				while((!flag)&&strcmp(Datos->desc_municipio.palabra[j++], buffer))
					if(j==Datos->desc_municipio.np)
						flag = 1;
				if(flag)
				{
					Datos->desc_municipio.palabra[j] = (char*)malloc((nc+1)*sizeof(char));
					if(Datos->desc_municipio.palabra[j]==NULL)
					{
						liberar_mem(Datos);
						fclose(fp);
						return 11;
					}
					strcpy(Datos->desc_municipio.palabra[j], buffer);
					Datos->desc_municipio.np++;
				}
				if(Datos->desc_municipio.ntid==l)
				{
					Datos->desc_municipio.id[Datos->desc_municipio.ntid] = (long int *)malloc(NM_M*sizeof(long int));
					if(Datos->desc_municipio.id[Datos->desc_municipio.ntid]==NULL)
					{
						liberar_mem(Datos);
						return 12;
					}
					Datos->desc_municipio.ntid++;
				}
				if(Datos->desc_municipio.nid[l]==Datos->cve_municipio[i])
				{
					Datos->desc_municipio.nid[l]++;
					Datos->desc_municipio.id[l][Datos->cve_municipio[i]] = j;
				}
				break;
			default:
				break;
			}
		}
	}
	realloc_dic = (char**)realloc(Datos->desc_entidad.palabra, (Datos->desc_entidad.np)*sizeof(char*));
	if(realloc_dic==NULL)
	{
		liberar_mem(Datos);
		fclose(fp);
		return 13;
	}
	else
		Datos->desc_entidad.palabra = realloc_dic;
	realloc_id_d = (long int**)realloc(Datos->desc_municipio.id, (Datos->desc_municipio.ntid)*sizeof(long int*));
	if(realloc_id_d==NULL)
	{
		liberar_mem(Datos);
		fclose(fp);
		return 14;
	}
	else
		Datos->desc_municipio.id = realloc_id_d;
	for(i=0; i<Datos->desc_municipio.ntid; i++)
	{
			realloc_id = (long int*)realloc(Datos->desc_municipio.id[i], (Datos->desc_municipio.nid[i])*sizeof(long int));
			if(realloc_id==NULL)
			{
				liberar_mem(Datos);
				fclose(fp);
				return 19+i;
			}
			else
				Datos->desc_municipio.id[i] = realloc_id;
	}
	realloc_nid = (int*)realloc(Datos->desc_municipio.nid, (Datos->desc_municipio.ntid)*sizeof(int));
	if(realloc_nid==NULL)
	{
		liberar_mem(Datos);
		fclose(fp);
		return 15;
	}
	else
		Datos->desc_municipio.nid = realloc_nid;
	realloc_dic = (char**)realloc(Datos->desc_municipio.palabra, (Datos->desc_municipio.np)*sizeof(char*));
	if(realloc_dic==NULL)
	{
		liberar_mem(Datos);
		fclose(fp);
		return 16;
	}
	else
		Datos->desc_municipio.palabra = realloc_dic;
	realloc_dic = (char**)realloc(Datos->indicador.palabra, (Datos->indicador.np)*sizeof(char*));
	if(realloc_dic==NULL)
	{
		liberar_mem(Datos);
		fclose(fp);
		return 17;
	}
	else
		Datos->indicador.palabra = realloc_dic;
	realloc_id = (long int*)realloc(Datos->indicador.id, (Datos->indicador.np)*sizeof(long int));
	if(realloc_id==NULL)
	{
		liberar_mem(Datos);
		fclose(fp);
		return 18;
	}
	else
		Datos->indicador.id = realloc_id;
	fclose(fp);
	return 0;
}

char* buscar(diccionario_i dic, long int id)
{
	long int i;
	i = 0;
	while(dic.id[i++]!=id)
		if(i==dic.np)
			return NULL;
	return dic.palabra[i-1];
}

int buscar_i(diccionario_r dic, char *palabra)
{
	long int i;
	i = 0;
	while(strcmp(dic.palabra[i++], palabra))
		if(i==dic.np)
			return -1;
	return i-1;
}

void imprimir_dr(diccionario_r dic)
{
	long int i;
	printf("%ld\n", dic.np);
	for(i=0; i<dic.np; i++)
		printf("%ld. %s\n", i, dic.palabra[i]);
}

void imprimir_di(diccionario_i dic)
{
	long int i;
	printf("%ld\n", dic.np);
	for(i=0; i<dic.np; i++)
		printf("%ld. %ld\t%s\n", i+1, dic.id[i], dic.palabra[i]);
}

void imprimir_dd(diccionario_d dic)
{
	long int i, j;
	printf("%ld\n", dic.np);
	for(i=0; i<dic.np; i++)
		printf("%ld. %s\n", i+1, dic.palabra[i]);
	printf("%ld\n", dic.ntid);
	for(i=0; i<dic.ntid; i++)
	{
		printf("%ld. %d\t", i+1, dic.nid[i]);
		for(j=0; j<dic.nid[i]; j++)
			printf("%ld ", dic.id[i][j]);
		printf("\n");
	}
}

int liberar_bd(bd_INEGI Datos)
{
	long int i;
	free(Datos.desc_municipio.nid);
	for(i=0; i<Datos.desc_municipio.ntid; i++)
		free(Datos.desc_municipio.id[i]);
	free(Datos.desc_municipio.id);
	for(i=0; i<Datos.desc_municipio.np; i++)
		free(Datos.desc_municipio.palabra[i]);
	free(Datos.desc_municipio.palabra);
	free(Datos.cve_entidad);
	for(i=0; i<Datos.desc_entidad.np; i++)
		free(Datos.desc_entidad.palabra[i]);
	free(Datos.desc_entidad.palabra);
	for(i=0; i<Datos.indicador.np; i++)
		free(Datos.indicador.palabra[i]);
	free(Datos.indicador.palabra);
	free(Datos.indicador.id);
	return 0;
}

int ini_bd(bd_INEGI *Datos)
{
	Datos->nr = 0;
	Datos->mem = NULL;
	Datos->cve_entidad = NULL;
	Datos->desc_entidad.palabra = NULL;
	Datos->desc_entidad.np = 0;
	Datos->cve_municipio = NULL;
	Datos->desc_municipio.id = NULL;
	Datos->desc_municipio.nid = NULL;
	Datos->desc_municipio.ntid = 0;
	Datos->desc_municipio.palabra = NULL;
	Datos->desc_municipio.np = 0;
	Datos->id_indicador = NULL;
	Datos->indicador.id = NULL;
	Datos->indicador.palabra = NULL;
	Datos->indicador.np = 0;
	Datos->anio = NULL;
	Datos->valor = NULL;
	return 0;
}

int liberar_mem(bd_INEGI *Datos)
{
	long int i;
	if(Datos->cve_entidad != NULL)
		free(Datos->cve_entidad);
	Datos->nr = 0;
	Datos->mem = NULL;
	Datos->cve_entidad = NULL;
	Datos->cve_municipio = NULL;
	Datos->id_indicador = NULL;
	Datos->anio = NULL;
	Datos->valor = NULL;
	if(Datos->desc_entidad.palabra!=NULL)
	{
		for(i=0; i<Datos->desc_entidad.np; i++)
			free(Datos->desc_entidad.palabra[i]);
		free(Datos->desc_entidad.palabra);
		Datos->desc_entidad.palabra = NULL;
		Datos->desc_entidad.np = 0;
	}
	if(Datos->desc_municipio.palabra!=NULL)
	{
		for(i=0; i<Datos->desc_municipio.np; i++)
			free(Datos->desc_municipio.palabra[i]);
		free(Datos->desc_municipio.palabra);
		Datos->desc_municipio.palabra = NULL;
		Datos->desc_municipio.np = 0;
	}
	if(Datos->desc_municipio.id!=NULL)
	{
		for(i=0; i<Datos->desc_municipio.ntid; i++)
			free(Datos->desc_municipio.id[i]);
		free(Datos->desc_municipio.id);
		Datos->desc_municipio.id = NULL;
		Datos->desc_municipio.ntid = 0;
	}
	if(Datos->desc_municipio.nid!=NULL)
	{
		free(Datos->desc_municipio.nid);
		Datos->desc_municipio.nid = NULL;
	}
	if(Datos->indicador.palabra!=NULL)
	{
		for(i=0; i<Datos->indicador.np; i++)
			free(Datos->indicador.palabra[i]);
		free(Datos->indicador.palabra);
		Datos->indicador.palabra = NULL;
		Datos->indicador.np = 0;
	}
	if(Datos->indicador.id!=NULL)
	{
		free(Datos->indicador.id);
		Datos->indicador.id = NULL;
	}
	return 0;
}