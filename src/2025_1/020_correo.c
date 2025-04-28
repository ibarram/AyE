#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define C_DEL '@'
#define C_DOM '.'
#define NC_MAX 254
#define NC_PL 64

int validad_email(char *str)
{
	unsigned long int nc, ncpl, i, j;
	char c_val[] = "-_.ñ", flag;
	char *lc, *ld;
	nc = strlen(str);
	if(nc>NC_MAX)
		return 0;
	lc = strchr(str, C_DEL);
	if(lc==NULL)
		return 0;
	ncpl = lc-str;
	if(ncpl>NC_PL||ncpl<1)
		return 0;
	for(i=0; i<ncpl; i++)
		if((!isalnum(str[i]))&&(strchr(c_val,str[i])==NULL))
			/*
			for(flag=1, j=0; j<ncv; j++)
				if(str[i]==c_val[j])
					flag=0;
			if(flag)
				return 0;
				*/
				return 0;
	if(strstr(str, "..")!=NULL)
		return 0;
	ld = strchr(lc, C_DOM);
	if(ld==NULL)
		return 0;
	printf("%lu\t%c\t%lu\n", nc, *lc, ncpl);
	return 1;
}

int main(int argc, char *argv[])
{
	int i;
	if(argc==1)
	{
		printf("Uso: %s email@dominio\n", argv[0]);
		return 1;
	}
	for(i=1; i<argc; i++)
		printf("%s %d\n", argv[i], validad_email(argv[i]));
}
