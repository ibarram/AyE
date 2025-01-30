#include <stdio.h>

int str2int(char *str)
{
	int i, valor;
	i = str[0]=='-';
	valor = 0;
	while(str[i]>='0'&&str[i]<='9')
		valor = 10*valor + str[i++]-'0';
	return str[0]=='-'?-valor:valor;
}

float str2float(char *str)
{
	int i;
	float valor, p10=10;
	i = str[0]=='-';
	valor = 0;
	while(str[i]>='0'&&str[i]<='9')
		valor = 10*valor + str[i++]-'0';
	if(str[i++]=='.')
		while(str[i]>='0'&&str[i]<='9')
		{
			valor += (str[i++]-'0')/p10;
			p10*=10;
		}
	return str[0]=='-'?-valor:valor;
}

float seno(float x, int n)
{
	int i, signo;
	float sx, factor;
	if(n<1)
		return 0;
	for(i=0, sx=0, signo=1, factor=x; i<n; i++)
	{
		sx += signo*factor;
		factor*=(x/(2*i+2))*(x/(2*i+3));
		signo*=-1;		
	}
	return sx;
}

int main(int argc, char *argv[])
{
	float x, sx;
	int n;
	switch(argc)
	{
	case 1:
		printf("Ingrese el valor de x: ");
		scanf("%f", &x);
		do{
			printf("Ingrese el numero de iteraciones: ");
			scanf("%d", &n);
		}while(n<1);
		break;
	case 2:
		printf("Ingrese el valor de x: ");
		scanf("%f", &x);
		n = str2int(argv[1]);
		break;
	case 3:
		n = str2int(argv[1]);
		x = str2float(argv[2]);
		break;
	default:
		printf("Error en el numero de argumentos.\n");
		return 1;
	}
	sx = seno(x, n<1?10:n);
	printf("sen(%f) = %f\n", x, sx);
	return 0;
}