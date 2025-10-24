#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "libarram.h"

/*
float suma(float a, float b)
{
	return a+b;
}
*/

/*
long int factorial(long int n)
{
	if(n<=1)
		return 1;
	return n*factorial(n-1);
}
*/

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

float factor(float x, int n)
{
	return n?(x/n)*factor(x,n-1):1;
}

float exp3(float x, int n)
{
	return n?factor(x, n)+exp3(x,n-1):1;
}

float exp4(float x, int n)
{
	static int i = 0;
	static float fct = 1;
	i++;
	fct*=(x/i);
	if(n)
	{
		return fct+exp4(x,n-1);
	}
	else
	{
		i = 0;
		fct = 1;
		return 1;
	}
}

int* DU(int n, int min, int max)
{
	int *p, i, j, flag;
	srand(time(NULL));
	if(n)
	{
		p = (int*)malloc(n*sizeof(int));
		if(p==NULL)
			return p;
		p[0] = rand()%(max-min+1)+min;
		for(i=1; i<n; i++)
		{
			flag = 1;
			while(flag)
			{
				p[i] = rand()%(max-min+1)+min;
				for(j=0; j<i; j++)
					if(p[i]==p[j])
						break;
				if(j==i)
					flag = 0;
			}
		}
	}
	else
		p = NULL;
	return p;
}

void imprimir_DU(int *d, int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%d. %d\n", i+1, d[i]);
}

int suma(int *x, int n)
{
	if(n)
		return x[0]+suma(x+1,n-1);
	else
		return 0;	
}

int suma2(int *x, int n)
{
	if(n)
		return (x[0]*x[0])+suma2(x+1,n-1);
	else
		return 0;	
}

float media2(int *x, int n)
{
	int i;
	float md;
	for(i=1, md=x[0]; i<n; i++)
		md+=x[i];
	return md/n;
}

float media(int *x, int n)
{
	return ((float)suma(x, n))/n;
}

float varianza(int *x, int n)
{
	float md = media(x, n);
	return ((float)suma2(x, n))/n-md*md;
}

float varianza2(int *x, int n)
{
	float md, vr;
	int i;
	md =  media2(x, n);
	for(i=1, vr=x[0]*x[0]; i<n; i++)
		vr+=(x[i]*x[i]);
	return vr/n-md*md;
}

int estInf(float md, float vr)
{
	return floor(md+.5-sqrt(12*vr+1)/2);
}

int estSup(float md, float vr)
{
	return ceil(md-.5+sqrt(12*vr+1)/2);
}

int estN(int *x, int n)
{
	int N, b, a;
	float md, vr;
	md = media2(x, n);
	vr = varianza2(x, n);
	b = estSup(md, vr);
	a = estInf(md, vr);
	N = b - a + 1;
	return N;
}

int esValido(char str[])
{
	int n, nl, i, j, v, nse;
	char *pstr1, *pstr2, *pstr3;
	const char str_esp[] = "!#$%&'*+/=?^_{|}~.";
	nse = strlen(str_esp);
	n = strlen(str);
	if(n>N_MAX)
		return 0;
	pstr1 = strchr(str, '@');
	if(pstr1==NULL)
		return 0;
	pstr2 = strchr(pstr1+1, '@');
	if(pstr2!=NULL)
		return 0;
	nl = (int)(pstr1-str);
	if(nl>N_local)
		return 0;
	if((n-nl)>N_dominio)
		return 0;
	pstr2 = strchr(pstr1, '.');
	if(pstr2==NULL)
		return 0;
	pstr2 = strchr(str, '.');
	while(pstr2!=NULL)
	{
		pstr3 = strchr(pstr2+1, '.');
		if(pstr3!=NULL)
		{
			if((pstr3-pstr2)==1)
				return 0;
			else if((pstr3-pstr2)>N_punto)
				return 0;
		}
		pstr2 = pstr3;
	}
	i=1;
	while(pstr1[i]!='\0')
	{
		if(isalnum(pstr1[i])||pstr1[i]=='.')
			i++;
		else
			return 0;
	}
	i=0;
	while(str[i]!='@')
	{
		for(j=0, v=0; j<nse; j++)
			v += str[i]==str_esp[j]?1:0;
		if(isalnum(str[i])||v)
			i++;
		else
			return 0;
	}
	return 1;
}

int RC4(char msg_1[], char clave[], char msg_2[])
{
	int nc, i, j, k, nM, NS, NC;
	char *S;
	nc = strlen(msg_1);
	NC = strlen(clave);
	nM = 'Z'-'A'+1;
	for(i=0; i<nc; i++)
	{
		if(msg_1[i]<'a')
			msg_1[i]-='A';
		else
			msg_1[i]-=('a'-nM);
	}
	NS = 2*nM;
	S=(char*)malloc(NS*sizeof(char));
	if(S==NULL)
		return 1;
	for(i=0; i<NS; i++)
		S[i] = i;
	for(i=0, j=0; i<NS; i++)
	{
		j = (j+S[i]+clave[i%NC])%NS;
		SWAP(S[i], S[j]);
	}
	for(k=0, i=0, j=0; k<nc; k++)
	{
		i = ( i + 1 ) % NS;
		j = ( j + S[i] ) % NS;
		SWAP( S[i], S[j] );
		msg_2[k] = msg_1[k] ^ S[ ( S[i] + S[j] ) % NS ];
		printf("%d ", msg_2[k]);
		if(msg_2[k]<nM)
			msg_2[k]+='A';
		else
			msg_2[k]+=('a'-nM);
	}
	msg_2[k]='\0';
	printf("\n");
	free(S);
	return 0;
}

Complejo sumaC(Complejo Z1, Complejo Z2)
{
	Complejo Z3;
	Z3.a = Z1.a+Z2.a;
	Z3.b = Z1.b+Z2.b;
	return Z3;
}

int mayusculas(char str[])
{
	if(str[0]=='\0')
		return 0;
	else
	{
		str[0] = toupper(str[0]);
		return mayusculas(str+1);
	}
}

CURP capturarCURP(void)
{
	CURP X;
	printf("Ingrese su apellido paterno: ");
	scanf("%s", X.AP);
	mayusculas(X.AP);
	printf("Ingrese su apellido materno: ");
	scanf("%s", X.AM);
	mayusculas(X.AM);
	printf("Ingrese su nombre: ");
	scanf("%s", X.Nom);
	mayusculas(X.Nom);
	printf("Ingrese su fecha de nacimiento (Dia): ");
	scanf("%d", &(X.fecha.dia));
	printf("Ingrese su fecha de nacimiento (Mes): ");
	scanf("%d", &(X.fecha.mes));
	printf("Ingrese su fecha de nacimiento (Anio): ");
	scanf("%d", &(X.fecha.anio));
	printf("Ingrese su estado de nacimiento (XX): ");
	scanf("%s", X.E);
	mayusculas(X.E);
	printf("Ingrese su genero [0: Hombre, 1: Mujer]: ");
	scanf("%d", &(X.G));
	return X;
}

void imprimirCURP(CURP X)
{
	char *str[] = {"Hombre", "Mujer"};
	printf("Datos:\n");
	printf("%s %s, %s\n", X.AP, X.AM, X.Nom);
	printf("%02d/%02d/%02d\n", X.fecha.dia, X.fecha.mes, X.fecha.anio);
	printf("Genero: %s\n", str[X.G]);
}

char vocal(char str[])
{
	if(str[0]=='A'||str[0]=='E'||str[0]=='I'||str[0]=='O'||str[0]=='U'||str[0]=='\0')
		return str[0];
	else
		return vocal(str+1);
}

char consonate(char str[])
{
	if(str[0]=='A'||str[0]=='E'||str[0]=='I'||str[0]=='O'||str[0]=='U')
		return consonate(str+1);
	else
		return str[0];
}

CURP generarCURP(CURP X)
{
	X.curp[0] = X.AP[0];
	X.curp[1] = vocal(X.AP+1);
	X.curp[2] = X.AM[0];
	X.curp[3] = X.Nom[0];
	sprintf(X.curp+4, "%02d%02d%02d", X.fecha.dia, X.fecha.mes, X.fecha.anio);
	X.curp[10] = X.G?'M':'H';
	X.curp[11] = X.E[0];
	X.curp[12] = X.E[1];
	X.curp[13] = consonate(X.AP+1);
	X.curp[14] = consonate(X.AM+1);
	X.curp[15] = consonate(X.Nom+1);
	X.curp[16] = 'X';
	X.curp[17] = 'X';
	X.curp[18] = '\0';
	return X;
}

float** CrearMatrizO(int n, int m)
{
	int i;
	float **X, *pX;
	pX = (float*)malloc(n*m*sizeof(float));
	if(pX == NULL)
		return NULL;
	X = (float**)malloc(n*sizeof(float*));
	if(X==NULL)
	{
		free(pX);
		return NULL;
	}
	for(i=0; i<n; i++)
		X[i] = pX+i*m;
	return X;
}

float** CrearMatrizD(int n, int m)
{
	int i;
	float **X;
	X = (float**)malloc(n*sizeof(float*));
	if(X==NULL)
		return NULL;
	for(i=0; i<n; i++)
	{
		X[i] = (float*)malloc(m*sizeof(float));
		if(X[i]==NULL)
		{
			for(i--; i>-1; i--)
				free(X[i]);
			free(X);
			return NULL;
		}
	}
	return X;
}

void liberarO(float **X)
{
	free(X[0]);
	free(X);
}

void liberarD(float **X, int n)
{
	int i;
	for(i=0; i<n; i++)
		free(X[i]);
	free(X);
}

void imprimirMat(float **X, int n, int m, char *str)
{
	int i, j;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			printf("%s[%d][%d] = %f\n", str, i+1, j+1, X[i][j]);
}

float **multiplicarMat(float **X, int nX, int mX, float **Y, int nY, int mY)
{
	float **Z;
	int i, j, k;
	if(mX!=nY)
		return NULL;
	Z = (float**)malloc(nX*sizeof(float*));
	if(Z==NULL)
		return NULL;
	Z[0] = (float*)calloc(nX*mY,sizeof(float));
	if(Z[0]==NULL)
	{
		free(Z);
		return NULL;
	}
	for(i=1; i<nX; i++)
		Z[i] = Z[i-1]+mY;
	for(i=0; i<nX; i++)
		for(j=0; j<mY; j++)
			for(k=0; k<mX; k++)
				Z[i][j] += X[i][k]*Y[k][j];
	return Z;
}

void capturarMat(float **X, int nX, int mX, char *str)
{
	int i, j;
	for(i=0; i<nX; i++)
		for(j=0; j<mX; j++)
		{
			printf("%s[%d][%d] = ", str, i+1, j+1);
			scanf("%f", X[i]+j);
		}
}

int read_csv(INEGI *info)
{
	char c, *str, *pstr1, *pstr2;
	long int i;
	rewind(info->fp);
	while ((c = fgetc(info->fp)) != EOF)
	{
		if(c==10)
			info->nr++;
	}
	info->nr-=2;
	info->data = (INEGI_CSV*)malloc(info->nr*sizeof(INEGI_CSV));
	if(info->data==NULL)
		return 0;
	rewind(info->fp);
	while ((c = fgetc(info->fp)) != 10);
	str = (char*)malloc(sizeof(INEGI_CSV)*sizeof(char));
	if(str==NULL)
	{
		free(info->data);
		return 0;
	}
	for(i=0; i<info->nr; i++)
	{
		fgets(str, sizeof(INEGI_CSV), info->fp);
		//printf("%s\n", str);
		pstr1 = strchr(str, ',');
		*pstr1 = '\0';
		pstr1++;
		pstr2 = strchr(pstr1, ',');
		*pstr2 = '\0';
		pstr2++;
		info->data[i].cve_entidad = atoi(str);
		strcpy(info->data[i].desc_entidad, pstr1);
		pstr1 = strchr(pstr2, ',');
		*pstr1 = '\0';
		pstr1++;
		info->data[i].cve_municipio = atoi(pstr2);
		pstr2 = strchr(pstr1, ',');
		*pstr2 = '\0';
		pstr2++;
		strcpy(info->data[i].desc_municipio, pstr1);
		pstr1 = strchr(pstr2, ',');
		*pstr1 = '\0';
		pstr1++;
		info->data[i].id_indicador = atol(pstr2);
		pstr2 = strchr(pstr1, ',');
		*pstr2 = '\0';
		pstr2++;
		strcpy(info->data[i].indicador, pstr1);
		pstr1 = strchr(pstr2, ',');
		*pstr1 = '\0';
		pstr1++;
		info->data[i].anio = atoi(pstr2);
		pstr2 = strchr(pstr1, ',');
		*pstr2 = '\0';
		pstr2++;
		info->data[i].valor = atof(pstr1);
		strcpy(info->data[i].unidad_medida, pstr2);
		/*
		printf("%ld\t%d\t%s\t%d\t%s\t%ld\t%s\t%d\t%f\t%s\n", i, 
			info->data[i].cve_entidad, info->data[i].desc_entidad,
			info->data[i].cve_municipio, info->data[i].desc_municipio, 
			info->data[i].id_indicador, info->data[i].indicador,
			info->data[i].anio, info->data[i].valor, info->data[i].unidad_medida);
			*/
	}
	free(str);
	return info->nr;
}

double consulta(INEGI *info, int cve_entidad, int cve_municipio, long int id_indicador, int anio)
{
	long int i, cmp;
	double valor;
	for(i=0; i<info->nr; i++)
	{
		cmp = 	((info->data[i].cve_entidad==cve_entidad)&&
				(info->data[i].cve_municipio==cve_municipio)&&
				(info->data[i].id_indicador==id_indicador)&&
				(info->data[i].anio==anio));
		if(cmp)
			return info->data[i].valor;
	}
	return 0;
}

int imprimir_lt(lt1 *plt)
{
	if(plt!=NULL)
	{
		printf("%f\n", plt->x);
		return imprimir_lt(plt->s);
	}
	else
		return 0;
}

int liberar_lt(lt1 *plt)
{
	if(plt!=NULL)
	{
		liberar_lt(plt->s);
		free(plt);
		return 1;
	}
	else
		return 0;
}

lt1* crearNodo(lt1 *plt)
{
	lt1 *new;
	new = (lt1*)malloc(sizeof(lt1));
	if(new==NULL)
	{
		liberar_lt(plt);
		return NULL;
	}
	new -> s = NULL;
	return new;
}

lt1* unir_lt(lt1 *plt, lt1 *new, int op)
{
	// 0 -> pila
	// 1 -> cola
	// 2 -> ascendente
	// . -> descendente
	lt1 *pB = plt;
	switch(op)
	{
	case 0:
		new->s = plt;
		return new;
	case 1:
		if(plt==NULL)
			return new;
		while(pB->s!=NULL)
			pB = pB->s;
		pB->s=new;
		return plt;
	case 2:
		if(plt==NULL)
			return new;
		else if(plt->s==NULL)
		{
			if(new->x<plt->x)
			{
				new->s = plt;
				return new;
			}
			else
			{
				plt->s=new;
				return plt;
			}
		}
		else
		{
			if(new->x<plt->x)
			{
				new->s = plt;
				return new;
			}
			else
			{
				pB = plt;
				while(new->x>pB->s->x)
				{
					pB = pB->s;
					if(pB->s==NULL)
						break;
				}
				if(pB->s==NULL)
				{
					if(new->x>pB->x)
						pB->s = new;
				}
				else
				{
					new->s=pB->s;
					pB->s=new;
				}
				return plt;
			}
		}
	default:
		if(plt==NULL)
			return new;
		else if(plt->s==NULL)
		{
			if(new->x>plt->x)
			{
				new->s = plt;
				return new;
			}
			else
			{
				plt->s=new;
				return plt;
			}
		}
		else
		{
			if(new->x>plt->x)
			{
				new->s = plt;
				return new;
			}
			else
			{
				pB = plt;
				while(new->x<pB->s->x)
				{
					pB = pB->s;
					if(pB->s==NULL)
						break;
				}
				if(pB->s==NULL)
				{
					if(new->x<pB->x)
						pB->s = new;
				}
				else
				{
					new->s=pB->s;
					pB->s=new;
				}
				return plt;
			}
		}
		return plt;
	}
}

lt2* inicio(lt2 *plt)
{
	if(plt!=NULL)
	{
		while(plt->a!=NULL)
			plt=plt->a;
	}
	return plt;
}

lt2* fin(lt2 *plt)
{
	if(plt!=NULL)
	{
		while(plt->s!=NULL)
			plt=plt->s;
	}
	return plt;
}

int imprimir_lt2(lt2 *plt, int dir)
{
	if(plt!=NULL)
	{
		printf("%f\n", plt->x);
		return imprimir_lt2(dir?plt->s:plt->a, dir);
	}
	else
		return 0;
}

int liberar_lt2(lt2 *plt)
{
	plt = inicio(plt);
	while(plt->s!=NULL)
	{
		plt=plt->s;
		free(plt->a);
	}
	free(plt);
	return 0;
}

lt2* crearNodo2(lt2 *plt)
{
	lt2 *new;
	new = (lt2*)malloc(sizeof(lt2));
	if(new==NULL)
	{
		liberar_lt2(plt);
		return NULL;
	}
	new -> s = NULL;
	new -> a = NULL;
	return new;
}

lt2* unir_lt2(lt2 *plt, lt2 *new, int op)
{
	// 1 -> pila/cola
	// . -> ascendente/descendente
	if(op)
	{
		if(plt!=NULL)
		{
			plt = inicio(plt);
			new->s = plt;
			plt->a = new;
		}
		return new;
	}
	else
	{
		return new;
	}
}

lt_IHME *read_csv2(FILE *fp)
{
	char c;
	char str[N_MAX], *str_1, *str_2;
	int i, j, k, nc;
	lt_IHME *lt1;
	char *ptr, **pptr;
	int *ptr_i;
	lt1 = NULL;
	if(fp==NULL)
		return NULL;
	rewind(fp);
	while ((c = fgetc(fp)) != 10);
	k = 0;
	while(c!=EOF)
	{
		i = 0;
		nc = 0;
		while((c = fgetc(fp)) != 10)
		{
			if(c==EOF)
				break;
			if(c==',')
				nc++;
			str[i++] = c;
		}
		str[i] = '\0';
		if(strlen(str)<35||nc!=17)
			break;
		if(lt1==NULL)
		{
			lt1 = (lt_IHME*)malloc(sizeof(lt_IHME));
			if(lt1==NULL)
				return NULL;
			lt1->s = NULL;
			lt1->a = NULL;
		}
		else
		{
			while(lt1->s!=NULL)
				lt1=lt1->s;
			lt1->s = (lt_IHME*)malloc(sizeof(lt_IHME));
			if(lt1->s==NULL)
			{
				liberar_IHME(lt1);
				return NULL;
			}
			lt1 -> s -> a = lt1;
			lt1 = lt1->s;
			lt1->s = NULL;
		}
		for(i=0, ptr=(char*)lt1, str_1 = str; i<7; i++)
		{
			str_2 = strchr(str_1, ',');
			*str_2 = '\0';
			str_2++;
			//lt1->measure_id = atoi(str_1);
			ptr_i = (int*)ptr;
			*ptr_i = atoi(str_1);
			str_1 = strchr(str_2, ',');
			*str_1 = '\0';
			str_1++;
			nc = strlen(str_2);
			ptr+=sizeof(void*);
			//lt1->measure_name = (char*)malloc((nc+1)*sizeof(char));
			pptr = (char**)ptr;
			*pptr = (char*)malloc((nc+1)*sizeof(char));
			//strcpy(lt1->measure_name, str_2);
			strcpy(*pptr, str_2);
			ptr+=sizeof(void*);
		}
		str_2 = strchr(str_1, ',');
		*str_2 = '\0';
		str_2++;
		lt1->year = atoi(str_1);
		str_1 = strchr(str_2, ',');
		*str_1 = '\0';
		str_1++;
		lt1->val = atof(str_2);
		str_2 = strchr(str_1, ',');
		*str_2 = '\0';
		str_2++;
		lt1->upper = atof(str_1);
		lt1->lower = atof(str_2);
	}
	return lt1;
}

int num_registros(lt_IHME *lt1)
{
	int n;
	lt1 = inicio_IHME(lt1);
	n = 1;
	while(lt1->s!=NULL)
	{
		lt1 = lt1->s;
		n++;
	}
	return n;
}

lt_IHME *inicio_IHME(lt_IHME *lt1)
{
	while(lt1->a!=NULL)
		lt1 = lt1->a;
	return lt1;
}

u_IHME *inicio_u_IHME(u_IHME *lt1)
{
	while(lt1->a!=NULL)
		lt1 = lt1->a;
	return lt1;
}

u_IHME *fin_u_IHME(u_IHME *lt1)
{
	while(lt1->s!=NULL)
		lt1 = lt1->s;
	return lt1;
}

int liberar_IHME(lt_IHME *lt1)
{
	char** ptr;
	int i;
	lt1 = inicio_IHME(lt1);
	while(lt1->s!=NULL)
	{
		lt1 = lt1->s;
		ptr = &(lt1->a->measure_name);
		for(i=0; i<7; i++)
		{
			free(*ptr);
			ptr+=(2*sizeof(void*));
		}
		free(lt1->a);
	}
	ptr = &(lt1->measure_name);
	for(i=0; i<7; i++)
	{
		free(*ptr);
		ptr+=(2*sizeof(void*));
	}
	free(lt1);
	return 0;
}

u_IHME *unique_IHME(lt_IHME *lt1, int indice)
{
	int df, dm;
	u_IHME *lt_u_IHME;
	void *p1, *p2;
	char **p3;
	lt_u_IHME = NULL;
	if(lt1==NULL)
		return NULL;
	lt1 = inicio_IHME(lt1);
	lt_u_IHME = (u_IHME*)malloc(sizeof(u_IHME));
	if(lt_u_IHME==NULL)
		return NULL;
	lt_u_IHME->a=NULL;
	lt_u_IHME->s=NULL;
	p1 = (void*)(&(lt1->measure_id));
	p2 = (void*)(&(lt1->location_id));
	df = p2-p1;
	p2 = (void*)(&(lt1->measure_name));
	dm = p2-p1;
	p1 = &(lt1->measure_id);
	p1 += (indice*df);
	lt_u_IHME->id = *((int*)p1);
	p2 = p1+dm;
	p3 = (char**)p2;
	lt_u_IHME->name = *p3;
	while(lt1->s!=NULL)
	{
		lt1=lt1->s;
		p1 = (void*)(&(lt1->measure_id));
		p1 += (indice*df);
		lt_u_IHME = fin_u_IHME(lt_u_IHME);
		if(!buscar_u_IHME(lt_u_IHME, *((int*)p1)))
		{
			lt_u_IHME->s = (u_IHME*)malloc(sizeof(u_IHME));
			if(lt_u_IHME->s==NULL)
				return NULL;
			lt_u_IHME->s->a=lt_u_IHME;
			lt_u_IHME = lt_u_IHME->s;
			p1 = &(lt1->measure_id);
			p1 += (indice*df);
			lt_u_IHME->id = *((int*)p1);
			p2 = p1+dm;
			p3 = (char**)p2;
			lt_u_IHME->name = *p3;
			lt_u_IHME->s = NULL;
		}
	}
	return lt_u_IHME; 
}

int buscar_u_IHME(u_IHME *lt_u_IHME, int id)
{
	if(lt_u_IHME->id==id)
		return 1;
	while(lt_u_IHME->a!=NULL)
	{
		lt_u_IHME = lt_u_IHME->a;
		if(lt_u_IHME->id==id)
			return 1;
	}
	return 0;
}

int imprimir_u_IHME(u_IHME *lt_u_IHME)
{
	lt_u_IHME = inicio_u_IHME(lt_u_IHME);
	while(lt_u_IHME!=NULL)
	{
		printf("%d. %s\n", lt_u_IHME->id, lt_u_IHME->name);
		lt_u_IHME=lt_u_IHME->s;
	}
	return 0;
}

double consulta_IHME(lt_IHME *lt1, int val[])
{
	void *p1, *p2;
	int df, flag, i;
	p1 = (void*)(&lt1->measure_id);
	p2 = (void*)(&lt1->location_id);
	df = p2-p1;
	lt1 = inicio_IHME(lt1);
	while(lt1!=NULL)
	{
		p1 = (void*)(&lt1->measure_id);
		for(i=0, flag=1; i<(N_C_MAX+1); i++)
			flag&=(*((int*)(p1+i*df))==val[i]);
		if(flag)
			return lt1->val;
		lt1=lt1->s;
	}
	return 0;
}

