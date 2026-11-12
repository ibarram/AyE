#include <stdio.h>
#include <stdlib.h>

typedef struct lt{
	float dato;
	struct lt *sc;
	struct lt *sp;
}lt;

lt* fin(lt *lt1, int opt)
{
	while((opt?lt1->sp:lt1->sc)!=NULL)
		lt1 = (opt?lt1->sp:lt1->sc);
	return lt1;
}

int liberar_lt(lt *lt1, int opt)
{
	lt *lt2;
	while(lt1!=NULL)
	{
		lt2 = lt1;
		lt1 = opt?lt1->sp:lt1->sc;
		free(lt2);
	}
	return 0;
}

lt* push(lt *lt1, float dato, int opt)
{
	lt *nv;
	nv = (lt*)malloc(sizeof(lt));
	nv->sc = NULL;
	nv->sp = NULL;
	if(nv==NULL)
	{
		liberar_lt(lt1, opt);
		return NULL;
	}
	nv->dato = dato;
	if(lt1==NULL)
		return nv;
	else if(opt)
	{
		nv->sp = lt1;
		return nv;
	}
	else
	{
		nv->sc = NULL;
		fin(lt1, opt)->sc = nv;
		return lt1;
	}
}

lt* cola(lt* lt1, lt* nv)
{
	lt *lt2;
	if(lt1==NULL)
		lt1 = nv;
	else
	{
		lt2 = fin(lt1, 0);
		lt2->sc = nv;
	}
	nv->sc = NULL;
	return lt1;
}

lt* pila(lt* lt_p, lt* nv)
{
	if(lt_p==NULL)
	{
		lt_p = nv;
		nv->sp = NULL;
	}
	else
	{
		nv->sp = lt_p;
		lt_p = nv;
	}
	return lt_p;
}

int contar_lt(lt *lt1, int opt)
{
	return (lt1==NULL)?0:1+contar_lt(opt?lt1->sp:lt1->sc, opt);
}

int imprimir_lt(lt *lt1, int opt)
{
	int i, n;
	n = contar_lt(lt1, opt);
	printf("Lista enlazada simple (%p).\n", lt1);
	for(i=0; i<n; i++)
	{
		printf("%d. lt[%p, %p, %p] = %f\n", i+1, lt1, 
			lt1->sc, lt1->sp, lt1->dato);
		lt1 = opt?lt1->sp:lt1->sc;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	lt *lt1;
	int op, ne, opt;
	float dato;
	lt1 = NULL;
	printf("Ingrese el tipo de estructura: ");
	scanf("%d", &opt);
	do{
		printf("Ingrese el valor: ");
		scanf("%f", &dato);
		lt1 = push(lt1, dato, opt);
		printf("Agregar otro dato: ");
		scanf("%d", &op);
	}while(op);
	ne = contar_lt(lt1, opt);
	printf("Numero de elementos: %d\n", ne);
	imprimir_lt(lt1, opt);
	liberar_lt(lt1, opt);
	return 0;
}