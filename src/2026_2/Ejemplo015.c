/**
 * @file    Ejemplo015.c
 * @brief   Multiplicación de matrices con dos esquemas de memoria dinámica.
 *
 * @details El programa captura dos matrices desde la entrada estándar,
 *          calcula su producto @f$ C = A \cdot B @f$ y lo imprime.
 *          Su objetivo didáctico es mostrar dos formas de reservar
 *          una matriz en el *heap*:
 *
 *          - **Matriz A**: un único bloque contiguo (`float*`) que se
 *            indexa con aritmética de apuntadores.
 *          - **Matriz B**: un bloque contiguo de datos más un arreglo de
 *            apuntadores (`float**`) que permite usar la notación `M[i][j]`.
 *          - **Matriz C**: un arreglo de apuntadores en el que cada vector
 *            se reserva por separado con `calloc`.
 *
 *          **Convención de almacenamiento (column-major).** En las tres
 *          matrices los datos se guardan por columnas. Para una matriz de
 *          @f$ n @f$ renglones y @f$ m @f$ columnas, el elemento del
 *          renglón @f$ r @f$ y la columna @f$ c @f$ (base 0) se encuentra en:
 *
 *          | Matriz | Tipo       | Acceso al elemento @f$ (r, c) @f$ |
 *          |--------|------------|-----------------------------------|
 *          | A      | `float*`   | `A[c*n + r]`                      |
 *          | B      | `float**`  | `B[c][r]`                         |
 *          | C      | `float**`  | `C[c][r]`                         |
 *
 *          Es decir, el primer índice de `B` y `C` selecciona la **columna**.
 *
 * @author  Mario-Alberto Ibarra-Manzano
 * @date    2026-10-12
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief   Lee un entero positivo desde la entrada estándar.
 *
 * @details Repite la solicitud hasta obtener un valor mayor o igual a 1.
 *          Si la entrada no es numérica, descarta el resto de la línea
 *          para evitar un ciclo infinito.
 *
 * @param[in] mensaje  Texto que se muestra al usuario antes de leer.
 * @return  Entero leído (siempre @f$ \geq 1 @f$), o -1 si se alcanzó
 *          el fin de archivo (EOF).
 */
int leerPositivo(const char *mensaje)
{
	int valor, r, c;
	do{
		printf("%s", mensaje);
		r = scanf("%d", &valor);
		if(r==EOF)
			return -1;
		if(r!=1)
		{
			while((c=getchar())!='\n' && c!=EOF);
			valor = 0;
		}
	}while(valor<1);
	return valor;
}

/**
 * @brief   Reserva y captura una matriz como un único bloque contiguo.
 *
 * @details Reserva @f$ n \times m @f$ flotantes con `malloc` y los llena
 *          desde la entrada estándar, columna por columna. El elemento
 *          @f$ (r, c) @f$ queda en `M[c*n + r]`, equivalente a
 *          `*(M + c*n + r)`.
 *
 * @param[in] n  Número de renglones (@f$ n \geq 1 @f$).
 * @param[in] m  Número de columnas (@f$ m \geq 1 @f$).
 * @return  Apuntador al bloque de datos, o `NULL` si falla la reserva.
 *
 * @note    El llamador debe liberar la memoria con `free(M)`.
 */
float* capturarM1(int n, int m)
{
	float *M;
	int i, j;
	M = (float*)malloc(n*m*sizeof(float));
	if(M==NULL)
		return NULL;
	for(i=0; i<m; i++)          /* i: columna */
		for(j=0; j<n; j++)      /* j: renglón */
		{
			printf("A[%d][%d] = ", j+1, i+1);
			scanf("%f", M+i*n+j); // &M[i*n+j] = &*(M+i*n+j) = M+i*n+j
		}
	return M;
}

/**
 * @brief   Reserva y captura una matriz con bloque contiguo e índice de columnas.
 *
 * @details Reserva un bloque de @f$ n \times m @f$ flotantes (`pM`) y un
 *          arreglo de @f$ m @f$ apuntadores (`M`), donde `M[c]` apunta al
 *          inicio de la columna @f$ c @f$ dentro de `pM`. Así, el elemento
 *          @f$ (r, c) @f$ se accede como `M[c][r]`.
 *
 * @param[in] n  Número de renglones (@f$ n \geq 1 @f$).
 * @param[in] m  Número de columnas (@f$ m \geq 1 @f$).
 * @return  Arreglo de apuntadores a columnas, o `NULL` si falla alguna reserva
 *          (en ese caso no queda memoria pendiente de liberar).
 *
 * @note    Para liberar: `free(M[0]); free(M);` (en ese orden),
 *          ya que `M[0]` apunta al inicio del bloque de datos.
 */
float** capturarM2(int n, int m)
{
	float **M, *pM;
	int i, j;
	pM = (float*)malloc(n*m*sizeof(float));
	if(pM==NULL)
		return NULL;
	M = (float**)malloc(m*sizeof(float*));
	if(M==NULL)
	{
		free(pM);
		return NULL;
	}
	for(i=0; i<m; i++)
		M[i] = pM+n*i;          /* inicio de la columna i */
	for(i=0; i<m; i++)          /* i: columna */
		for(j=0; j<n; j++)      /* j: renglón */
		{
			printf("B[%d][%d] = ", j+1, i+1);
			scanf("%f", M[i]+j); // &M[i][j] = M[i]+j
		}
	return M;
}

/**
 * @brief   Calcula el producto matricial @f$ C = A \cdot B @f$.
 *
 * @details Para cada renglón @f$ r @f$ de A y cada columna @f$ c @f$ de B:
 *          @f[
 *              C_{r,c} = \sum_{k=0}^{m_A-1} A_{r,k}\, B_{k,c}
 *          @f]
 *          Con la convención column-major del programa esto se traduce en
 *          `C[c][r] += A[k*nA + r] * B[c][k]`.
 *
 *          La matriz resultante tiene @f$ n_A @f$ renglones y @f$ m_B @f$
 *          columnas; se almacena como @f$ m_B @f$ columnas reservadas por
 *          separado con `calloc` (inicializadas en cero). Complejidad:
 *          @f$ O(n_A\, m_A\, m_B) @f$.
 *
 * @param[in] A   Matriz A, bloque contiguo column-major (ver capturarM1()).
 * @param[in] nA  Renglones de A.
 * @param[in] mA  Columnas de A.
 * @param[in] B   Matriz B, arreglo de columnas (ver capturarM2()).
 * @param[in] nB  Renglones de B.
 * @param[in] mB  Columnas de B.
 * @return  Matriz C de @f$ n_A \times m_B @f$ con `C[c][r]` = @f$ C_{r,c} @f$,
 *          o `NULL` si algún argumento es `NULL`, si las dimensiones son
 *          incompatibles (@f$ m_A \neq n_B @f$) o si falla una reserva.
 *
 * @note    Para liberar: `free(C[c])` para cada @f$ c \in [0, m_B) @f$
 *          y después `free(C)`.
 */
float** multiplicacion(float *A, int nA, int mA, float **B, int nB, int mB)
{
	float **C;
	int i, j, k;
	if(A==NULL||B==NULL||mA!=nB)
		return NULL;
	C = (float**)malloc(mB*sizeof(float*));
	if(C==NULL)
		return NULL;
	for(i=0; i<mB; i++)
	{
		C[i] = (float*)calloc(nA,sizeof(float));
		if(C[i]==NULL)
		{
			for(--i; i>-1; i--)  /* libera las columnas ya reservadas */
				free(C[i]);
			free(C);
			return NULL;
		}
	}
	for(i=0; i<nA; i++)             /* i: renglón de A y de C   */
		for(j=0; j<mB; j++)         /* j: columna de B y de C   */
			for(k=0; k<mA; k++)     /* k: índice de la suma     */
				C[j][i] += (A[k*nA+i]*B[j][k]);  /* A(i,k) * B(k,j) */
	return C;
}

/**
 * @brief   Imprime los elementos de una matriz almacenada por columnas.
 *
 * @details Recorre la matriz por renglones y muestra cada elemento con
 *          índices en base 1, en el formato `C[r][c] = valor`.
 *
 * @param[in] C  Matriz en formato de arreglo de columnas (`C[c][r]`).
 * @param[in] n  Número de renglones.
 * @param[in] m  Número de columnas.
 * @retval 0  La matriz se imprimió correctamente.
 * @retval 1  `C` es `NULL`; no se imprime nada.
 */
int imprimir(float **C, int n, int m)
{
	int i, j;
	if(C==NULL)
		return 1;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			printf("C[%d][%d] = %f\n", i+1, j+1, C[j][i]);
	return 0;
}

/**
 * @brief   Punto de entrada: captura A y B, calcula A·B e imprime el resultado.
 *
 * @details Solicita las dimensiones de ambas matrices y verifica que sean
 *          compatibles (columnas de A = renglones de B) **antes** de
 *          capturar los datos. Después captura A y B, calcula el producto,
 *          lo imprime y libera toda la memoria reservada.
 *
 * @param[in] argc  Número de argumentos de línea de comandos (no se usa).
 * @param[in] argv  Argumentos de línea de comandos (no se usan).
 * @retval 0  Ejecución exitosa.
 * @retval 1  Falló la reserva de memoria de A.
 * @retval 2  Falló la reserva de memoria de B.
 * @retval 3  Falló la reserva de memoria de C.
 * @retval 4  Dimensiones incompatibles o entrada terminada (EOF).
 */
int main(int argc, char *argv[])
{
	int nA, mA, nB, mB, i;
	float *A, **B, **C;
	(void)argc;
	(void)argv;
	nA = leerPositivo("Ingrese el numero de renglones de A: ");
	mA = leerPositivo("Ingrese el numero de columnas de A: ");
	nB = leerPositivo("Ingrese el numero de renglones de B: ");
	mB = leerPositivo("Ingrese el numero de columnas de B: ");
	if(nA<1||mA<1||nB<1||mB<1)
		return 4;
	if(mA!=nB)
	{
		printf("Error: las columnas de A (%d) deben ser iguales a los renglones de B (%d).\n", mA, nB);
		return 4;
	}
	A = capturarM1(nA, mA);
	if(A==NULL)
		return 1;
	B = capturarM2(nB, mB);
	if(B==NULL)
	{
		free(A);
		return 2;
	}
	C = multiplicacion(A, nA, mA, B, nB, mB);
	if(C==NULL)
	{
		free(A);
		free(B[0]);
		free(B);
		return 3;
	}
	imprimir(C, nA, mB);
	free(A);
	free(B[0]);
	free(B);
	for(i=0; i<mB; i++)
		free(C[i]);
	free(C);
	return 0;
}
