#include <stdio.h>

int pos(float x, float *m)
{
	int id, C[4], B[3], i;
	for(i=0; i<4; i++)
		C[3-i] = x<m[i];
	B[0] = ((!C[3])&&C[2])||((!C[1])&&C[0]);
	B[1] = (!C[2])&&C[0];
	B[2] = !C[0];
	id = (B[2]<<2)|(B[1]<<1)|B[0];
	//printf("%d %d %d %d\n", C[3], C[2], C[1], C[0]);
	//printf("%d %d %d\n", B[2], B[1], B[0]);
	return id;
}

int main(int argc, char *argv[])
{
	float M[4] = {155, 165, 175, 185}, X;
	scanf("%f", &X);
	printf("%d\n", pos(X, M));
	return 0;
}