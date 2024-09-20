#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include"libarram.h"

#define	N 5

int main(int argc, char *argv[])
{
	int P[N], n, i, b, s, x;
	float M[N-1], md, de, d, y;
	//float ln2;
	srand(time(NULL));
	do{
		printf("Ingrese el numero de productos: ");
		scanf("%d", &n);
	}while(n<1);
	do{
		printf("Ingrese la media: ");
		scanf("%f", &md);
		printf("Ingrese la desviacion estandar: ");
		scanf("%f", &de);
	}while(md<=0||de<=0);
	for(i=0; i<N-1; i++)
	{
		printf("Ingrese el rango %d: ", i+1);
		scanf("%f", &M[i]);
	}
	for(i=0; i<N; i++)
		P[i] = 0;
	//ln2 = log(2.0);
	for(i=0; i<n; i++)
	{
		d = dist_norm(md, de);
		//b=((M[3]<d)<<2)|(((M[0]<d)&(M[2]>d))<<1)|(((M[0]<d)&(M[1]>d))|((M[2]<d)&(M[3]>d)));
		x = ((d<M[0])<<3)|((d<M[1])<<2)|((d<M[2])<<1)|d<M[3];
		//y = log(16.0/(x+1))/ln2;
		y = ((((x/960.0)-(197.0/6720))*x+1817.0/6720)*x-1693.0/1363)*x+4;
		b = (int)y;
		P[b]++;
		/*switch(b)
		{
		case 15:
			s=0;
			break;
		case 7:
			s=1;
			break;
		case 3:
			s=2;
			break;
		case 1:
			s=3;
			break;
		default:
			s=4;
		}
		P[s]++;*/
		/*
		if(d<M[0])
			P[0]++;
		else if(d<M[1])
			P[1]++;
		else if(d<M[2])
			P[2]++;
		else if(d<M[3])
			P[3]++;
		else
			P[4]++;
		*/
	}
	printf("XS [?-%.1f]: %d\nS [%.1f-%.1f]: %d\nM [%.1f-%.1f]: %d\nL [%.1f-%.1f]: %d\n XL [%.1f-?]: %d\n", 
			M[0], P[0], M[0], M[1], P[1], M[1], M[2], P[2], M[2], M[3], P[3], M[3], P[4]);
	return 0;
}