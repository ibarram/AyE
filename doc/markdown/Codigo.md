<br />
<div align="center">
  <a href="https://github.com/ibarram/AyE">
    <img src="/doc/img/escudo-png.png" alt="Logo" width="120" height="120">
  </a>

  <h3 align="center">Algoritmos y Estructuras de Datos (IILI06004)</h3>

  <p align="center">
    Licenciatura en Ingeniería de Datos e Inteligencia Artificial (IS75LI0801)
    <br />
    <a href="https://github.com/ibarram/AyE"><strong>Explorar la documentación »</strong></a>
    <br />
    <br />
    <a href="https://github.com/ibarram/AyE">Ver Demo</a>
    ·
    <a href="https://github.com/ibarram/AyE/issues">Reportar Bug</a>
    ·
    <a href="https://github.com/ibarram/AyE/issues">Requiere Modificaciones</a>
  </p>
</div>

<details><summary>Table of Contents</summary><p>
 
 * [Conceptos fundamentales de algoritmos](#Conceptos-fundamentales-de-algoritmos)

 * [Recursividad](#Recursividad)

 * [Estructuras de datos fundamentales](#Estructuras-de-datos-fundamentales)

 * [Algoritmos de ordenamiento](#Algoritmos-de-ordenamiento)

 * [Algoritmos de búsqueda](#Algoritmos-de-búsqueda)

 * [Análisis de algoritmos](#Análisis-de-algoritmos)

</p></details><p></p>

## Conceptos fundamentales de algoritmos

### 1. Cálculo de Seno con Serie de Taylor (Inicial): [001_seno_serie_ini.c](../../src/001_seno_serie_ini.c)
   - **Descripción**: Este código calcula la aproximación del seno de un número en radianes utilizando la **serie de Taylor**. El número de términos de la serie es configurable.

   $$sen(x)=\sum_{i=1}^{n}{(-1)^{i+1}\frac{x^{2i-1}}{(2i-1)!}}=x-\frac{x^3}{3!}+\frac{x^5}{5!}-\frac{x^7}{7!}+...$$

   - **Temas clave**: Serie de Taylor, funciones trigonométricas, precisión de cálculos numéricos.
   - **Ubicación**: `src/001_seno_serie_ini.c`
   - **Compilación**:
     ```bash
     make 001_seno_serie_ini
     ```
   - **Uso**:
     ```bash
     ./001_seno_serie_ini
     ```

## Recursividad



## Estructuras de datos fundamentales



## Algoritmos de ordenamiento



## Algoritmos de búsqueda



## Análisis de algoritmos

## **Makefile**

El archivo **Makefile** permite compilar todos los programas de manera más sencilla:

```makefile
CC = gcc
CFLAGS = -lm
TARGETS = piezas medidas calidad productos

all: $(TARGETS)

piezas: 011_piezas.c libarram.c
  $(CC) -o piezas 011_piezas.c libarram.c $(CFLAGS)

medidas: 012_Medidas.c libarram.c
  $(CC) -o medidas 012_Medidas.c libarram.c $(CFLAGS)

calidad: 014_Calidad.c libarram.c
  $(CC) -o calidad 014_Calidad.c libarram.c $(CFLAGS)

productos: 256_productos.c libarram.c
  $(CC) -o productos 256_productos.c libarram.c $(CFLAGS)

clean:
  rm -f $(TARGETS)

