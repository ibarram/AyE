#include <stdio.h>
#include <stdlib.h>

#define N 200

typedef struct lt_u{
	char c;
	struct lt_u *s;
}lt_u;
typedef lt_u *plt_u;

int capturar(char *str)
{
	int n = 0;
	do{
		str[n++] = getchar();
	}while(n<N&&str[n-1]!=10);
	n--;
	str[n] = '\0';
	return n;
}

int contar_lt(plt_u lt1)
{
	int n;
	n = 0;
	while(lt1!=NULL)
	{
		lt1 = lt1->s;
		n++;
	}
	return n;
}

plt_u fin(plt_u lt1)
{
	if(lt1==NULL)
		return NULL;
	while(lt1->s!=NULL)
		lt1 = lt1->s;
	return lt1;
}

int liberar(plt_u lt1)
{
	plt_u lt2;
	while(lt1!=NULL)
	{
		lt2 = lt1;
		lt1 = lt1->s;
		free(lt2);
	}
	return 0;
}

int imprimir_lt(plt_u lt1)
{
	printf("UNICO: ");
	while(lt1!=NULL)
	{
		printf("%c", lt1->c);
		lt1 = lt1->s;
	}
	printf("\n");
	return 0;
}

int imprimir_lt_d(plt_u lt1)
{
	printf("LT: ");
	while(lt1!=NULL)
	{
		printf("%p\t%c\t%p\n", lt1, lt1->c, lt1->s);
		lt1 = lt1->s;
	}
	return 0;
}

plt_u unicos(char *str)
{
	plt_u lt1 = NULL, nv;
	int n = 0;
	while(str[n]!='\0')
	{
		if(lt1==NULL)
		{
			nv = (plt_u)malloc(sizeof(lt_u));
			if(nv==NULL)
			{
				liberar(lt1);
				return NULL;
			}
			nv->c = str[n];
			nv->s = NULL;
			lt1 = nv;
		}
		else
		{
			nv = lt1;
			while(nv!=NULL)
			{
				if(str[n]==nv->c)
					break;
				nv = nv->s;
			}
			if(nv!=NULL)
			{
				n++;
				continue;
			}
			nv = (plt_u)malloc(sizeof(lt1));
			if(nv==NULL)
			{
				liberar(lt1);
				return NULL;
			}
			nv->c = str[n];
			nv->s = NULL;
			fin(lt1)->s = nv;
		}
		n++;
	}
	return lt1;
}

int* histograma(plt_u lt1, char *str)
{
	int n, *h, i, j, nh;
	n = contar_lt(lt1);
	h = (int*)calloc(n, sizeof(int));
	if(h==NULL)
		return NULL;
	for(i=0; i<n; i++)
	{
		j = 0;
		nh = 0;
		while(str[j]!='\0')
		{
			if(lt1->c==str[j])
				nh++;
			j++;
		}
		h[i] = nh;
		lt1 = lt1->s;
	}
	return h;
}

char consulta(plt_u lt1, int n)
{
	while((lt1!=NULL)&&n)
	{
		lt1 = lt1->s;
		n--;
	}
	return lt1!=NULL?lt1->c:'\0';
}

int imprimir_h(plt_u lt1, int *h_c)
{
	int n, i;
	n = contar_lt(lt1);
	for(i=0; i<n; i++)
		printf("%d\t", h_c[i]);
	printf("\n");
	for(i=0; i<n; i++)
	{
		printf("%c\t", lt1->c);
		lt1 = lt1->s;
	}
	printf("\n");
	return 0;
}

int max_h(int *h_c, int nh)
{
	int i_max, i;
	i_max = 0;
	for(i=1; i<nh; i++)
		if(h_c[i]>h_c[i_max])
			i_max = i;
	return i_max;
}

int main(int argc, char *argv[])
{
	char str[N];
	int *h_c;
	int n, nh, i_max;
	plt_u lt1;
	n = capturar(str);
	printf("MSG: %s (%d)\n", str, n);
	lt1 = unicos(str);
	if(lt1==NULL)
		return 1;
	imprimir_lt(lt1);
	h_c = histograma(lt1, str);
	if(h_c==NULL)
	{
		liberar(lt1);
		return 2;
	}
	imprimir_h(lt1, h_c);
	printf("%c\n", consulta(lt1, 3));
	nh = contar_lt(lt1);
	i_max = max_h(h_c, nh);
	printf("MAX: %d\t%c\n", h_c[i_max], consulta(lt1, i_max));
	liberar(lt1);
	free(h_c);
	return 0;
}