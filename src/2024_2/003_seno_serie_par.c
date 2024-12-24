#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Función principal que calcula la aproximación del seno de un número utilizando
 * una serie de Taylor optimizada. Los parámetros se pasan como argumentos de la línea de comandos.
 * 
 * @param argc El número de argumentos pasados al programa.
 * @param argv El arreglo de argumentos pasados al programa.
 * @return 0 si el programa finaliza correctamente, 1 si hay un error en los argumentos.
 */
int main(int argc, char *argv[]) {
    double x, sx, fct, pt=0.1;
    long int n, i;

    for(i=0; i<argc; i++)
        printf("%s\n", argv[i]);
    // Verifica que se pasen exactamente dos argumentos: el valor de x y el número de términos n
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <valor de x> <número de términos>\n", argv[0]);
        return 1;
    }

    // Convierte los argumentos de la línea de comandos a sus respectivos tipos
    //x = atof(argv[1]);
    int s=1;
    i=0;
    if(*argv[1]=='-')
    {
        s=-1;
        i++;
    }
    x = 0;
    while(*(argv[1]+i)>='0'&&*(argv[1]+i)<='9')
    {
        x*=10;
        x+=(*(argv[1]+i)-'0');
        i++;
    }
    if(*(argv[1]+i)=='.')
    {
        i++;
        while(*(argv[1]+i)>='0'&&*(argv[1]+i)<='9')
        {
            x+=((*(argv[1]+i)-'0')*pt);
            pt*=0.1;
            i++;
        }
    }
    x*=s;
    //n = atol(argv[2]);
    s=1;
    i=0;
    if(*argv[2]=='-')
    {
        s=-1;
        i++;
    }
    n = 0;
    while(*(argv[2]+i)>='0'&&*(argv[2]+i)<='9')
    {
        n*=10;
        n+=(*(argv[2]+i)-'0');
        i++;
    }
    n*=s;

    // Inicializa las variables para la serie de Taylor
    for (i = 0, fct = x, sx = 0; i < n; i++) {
        // Calcula la suma de la serie de Taylor para sin(x)
        sx += (2 * ((i + 1) % 2) - 1) * fct;
        // Calcula el siguiente término de la serie
        fct *= (x / (2 * i + 2)) * (x / (2 * i + 3));
    }

    // Almacena la aproximación de sin(x) usando la serie de Taylor
    double approx_sin = sx;
    // Calcula el valor real de sin(x)
    double actual_sin = sin(x);

    // Imprime los resultados
    printf("Aproximación de sin(%.2f) usando %ld términos: %.10f\n", x, n, approx_sin);
    printf("Valor real de sin(%.2f): %.10f\n", x, actual_sin);

    return 0;
}