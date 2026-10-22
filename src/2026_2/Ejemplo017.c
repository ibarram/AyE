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

int liberar_lt(lt *lt1)
{
	lt *lt2;
	while(lt1!=NULL)
	{
		lt2 = lt1;
		lt1 = lt1->sc;
		free(lt2);
	}
	return 0;
}

int contar_lt(lt *lt1, int opt)
{
	return (lt1==NULL)?0:1+contar_lt(opt?lt1->sp:lt1->sc);
}

int imprimir_lt(lt *lt1)
{
	int i, n;
	n = contar_lt(lt1);
	printf("Lista enlazada simple (%p).\n", lt1);
	for(i=0; i<n; i++)
	{
		printf("lt[%d] = %f\n", i+1, lt1->dato);
		lt1 = lt1->s;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	lt *lt_c, *lt_p, *nv_c, *nv_p;
	int op, nc, np;
	lt_c = NULL;
	lt_p = NULL;
	do{
		nv_c = (lt*)malloc(sizeof(lt));
		if(nv_c==NULL)
		{
			liberar_lt(lt_c);
			liberar_lt(lt_p);
			return 1;
		}
		nv_p = (lt*)malloc(sizeof(lt));
		if(nv_p==NULL)
		{
			liberar_lt(lt_c);
			liberar_lt(lt_p);
			return 2;
		}
		printf("Ingrese el valor: ");
		scanf("%f", &(nv_c->dato));
		nv_p->dato = nv_c->dato;
		lt_c = cola(lt_c, nv_c);
		lt_p = pila(lt_p, nv_p);
		printf("Agregar otro dato: ");
		scanf("%d", &op);
	}while(op);
	nc = contar_lt(lt_c);
	np = contar_lt(lt_p);
	printf("Numero de elementos (Cola): %d\n", nc);
	printf("Numero de elementos (Pila): %d\n", np);
	imprimir_lt(lt_c);
	imprimir_lt(lt_p);
	liberar_lt(lt_c);
	liberar_lt(lt_p);
	return 0;
}