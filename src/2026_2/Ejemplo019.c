#include <stdio.h>
#include <stdlib.h>

typedef struct lt{
	float dato;
	struct lt *a, *s;
}lt;

lt* fin(lt* lt1)
{
	if(lt1==NULL)
		return NULL;
	while(lt1->s!=NULL)
		lt1=lt1->s;
	return lt1;
}

lt* inicio(lt* lt1)
{
	if(lt1==NULL)
		return NULL;
	while(lt1->a!=NULL)
		lt1=lt1->a;
	return lt1;
}

int liberar_lt(lt* lt1)
{
	lt1 = inicio(lt1);
	if(lt1==NULL)
		return 1;
	while(lt1->s!=NULL)
	{
		lt1 = lt1->s;
		free(lt1->a);
	}
	free(lt1);
	return 0;
}

lt* push(lt* lt1, float dato)
{
	lt* nv;
	nv = (lt*)malloc(sizeof(lt));
	if(nv==NULL)
	{
		liberar_lt(lt1);
		return NULL;
	}
	if(lt1==NULL)
	{
		lt1 = nv;
		nv->a = NULL;
	}
	else if(lt1->s==NULL&&lt1->a==NULL)
	{
		nv->a = lt1;
		lt1->s = nv;
	}
	else
	{
		lt1 = fin(lt1);
		nv->a = lt1;
		lt1->s = nv;
	}
	nv->s = NULL;
	nv->dato = dato;
	return lt1;
}

lt* orden(lt *lt1, float dato)
{
	lt* nv;
	nv = (lt*)malloc(sizeof(lt));
	if(nv==NULL)
	{
		liberar_lt(lt1);
		return NULL;
	}
	nv->dato = dato;
	if(lt1==NULL)
	{
		lt1 = nv;
		nv->a = NULL;
		nv->s = NULL;
	}
	else if(lt1->s==NULL&&lt1->a==NULL)
	{
		if(nv->dato<lt1->dato)
		{
			nv->s = lt1;
			nv->a = NULL;
			lt1->a = nv;
		}
		else
		{
			nv->a = lt1;
			nv->s = NULL;
			lt1->s = nv;
		}
	}
	else
	{
		lt1 = inicio(lt1);
		while(nv->dato>lt1->dato)
		{
			if(lt1->s==NULL)
				break;
			lt1 = lt1->s;
		}
		if((nv->dato>lt1->dato)&&(lt1->s==NULL))
		{
			nv->s = NULL;
			nv->a = lt1;
			lt1->s = nv;
		}
		else
		{
			nv->s = lt1;
			nv->a = lt1->a;
			lt1->a = nv;
			if(nv->a!=NULL)
				nv->a->s = nv;
		}
	}
	return lt1;
}

int imprimir_lt(lt* lt1, int opc)
{
	int i = 1;
	lt1 = (opc?inicio(lt1):fin(lt1));
	if(opc)
		printf("Ascendente\n");
	else
		printf("Descendente\n");
	while(lt1!=NULL)
	{
		printf("%d. %p %p %p\t%f\n", i, 
			lt1->a, lt1, lt1->s, lt1->dato);
		i++;
		lt1 = (opc?lt1->s:lt1->a);
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int op;
	float dato;
	lt* lt1 = NULL;
	do{
		printf("Ingrese el dato: ");
		scanf("%f", &dato);
		lt1 = orden(lt1, dato);
		printf("Ingresar otro dato: ");
		scanf("%d", &op);
	}while(op);
	imprimir_lt(lt1, 0);
	imprimir_lt(lt1, 1);
	liberar_lt(lt1);
	return 0;
}