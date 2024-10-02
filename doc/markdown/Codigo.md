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
   - **Descripción**: Este código calcula la aproximación del seno de $$x$$ en radianes utilizando la **serie de Taylor**. El número $$n$$ de términos de la serie es configurable.

   $$sen(x)=\sum_{i=1}^{n}{(-1)^{i+1}\frac{x^{2i-1}}{(2i-1)!}}=x-\frac{x^3}{3!}+\frac{x^5}{5!}-\frac{x^7}{7!}+...$$

   - **Temas clave**: Serie de Taylor, Funciones Trigonométricas, Bucles, Ciclos, Bifurcaciones.
   - **Ubicación**: `src/001_seno_serie_ini.c`
   - **Compilación**:
     ```bash
     make 001_seno_serie_ini
     ```
   - **Uso**:
     ```bash
     ./001_seno_serie_ini
     ```

<p align="center">
  <img src="../img/Fig_TB_01_1.jpg" alt="Figura 1" width="200"/>
  <img src="../img/Fig_TB_01_2.jpg" alt="Figura 2" width="200"/>
  <img src="../img/Fig_TB_01_3.jpg" alt="Figura 3" width="200"/>
</p>

<p align="center">
  <strong>Figura 1</strong> | <strong>Figura 2</strong> | <strong>Figura 3</strong>
</p>


<div style="display: flex; justify-content: space-around;">
    <div style="text-align: center;">
        <img src="../img/Fig_TB_01_1.jpg" alt="(a)" width="200"/>
        <p><strong>(a)</strong></p>
    </div>
    <div style="text-align: center;">
        <img src="../img/Fig_TB_01_2.jpg" alt="(b)" width="200"/>
        <p><strong>(b)</strong></p>
    </div>
    <div style="text-align: center;">
        <img src="../img/Fig_TB_01_3.jpg" alt="(c)" width="200"/>
        <p><strong>(c)</strong></p>
    </div>
</div>



<img src="../img/Fig_TB_02_1.jpg" alt="Figura de la función seno" width="300" /> <img src="../img/Fig_TB_02_2.jpg" alt="Figura del tiempo de procesamiento" width="300" /> <img src="../img/Fig_TB_02_3.jpg" alt="Figura del error de calculo" width="300" />

## Recursividad



## Estructuras de datos fundamentales



## Algoritmos de ordenamiento



## Algoritmos de búsqueda



## Análisis de algoritmos

## **Makefile**

El archivo **Makefile** permite compilar todos los programas de manera más sencilla:

```makefile
CC = gcc
LIB = libarram
001 = 001_seno_serie_ini
002 = 002_seno_serie_opt
003 = 003_seno_serie_par
004 = 004_billetes
005 = 005_distancia
006 = 006_mochila
007 = 007_libreria
008 = 008_choco
009 = 009_expo
010 = 010_pseudoalea
011 = 011_piezas
012 = 012_Medidas
256 = 256_productos
014 = 014_Calidad
015 = 015_email

all: $(001) $(002) $(003) $(004) $(005) $(006) $(007) $(008) $(009) $(010) $(011) $(012) $(256) $(014) $(015)

$(001): $(001).c
  $(CC) -o $(001) $(001).c

$(002): $(002).c
  $(CC) -o $(002) $(002).c

$(003): $(003).c
  $(CC) -o $(003) $(003).c

$(004): $(004).c
  $(CC) -o $(004) $(004).c

$(005): $(005).c
  $(CC) -o $(005) $(005).c

$(006): $(006).c
  $(CC) -o $(006) $(006).c

$(007): $(007).c lib$(LIB).a
  $(CC) $(007).c -L. -l$(LIB) -o $(007)

$(008): $(008).c lib$(LIB).a
  $(CC) $(008).c -L. -l$(LIB) -o $(008)

$(009): $(009).c lib$(LIB).a
  $(CC) $(009).c -L. -l$(LIB) -o $(009)

lib$(LIB).a: $(LIB).o
  ar rcs lib$(LIB).a $(LIB).o

$(LIB).o: $(LIB).c
  $(CC) -c $(LIB).c -o $(LIB).o

$(010): $(010).c
  $(CC) -o $(010) $(010).c

$(011): $(011).c
  $(CC) -o $(011) $(011).c

$(012): $(012).c
  $(CC) $(012).c -L. -l$(LIB) -o $(012)

$(256): $(256).c lib$(LIB).a
  $(CC) $(256).c -L. -l$(LIB) -o $(256)

$(014): $(014).c
  $(CC) -o $(014) $(014).c

$(015): $(015).c lib$(LIB).a
  $(CC) $(015).c -L. -l$(LIB) -o $(015)

clean:
  rm -f $(001) $(002) $(003) $(004) $(005) $(006) $(007) $(008) $(009) lib$(LIB).a $(LIB).o $(010) $(011) $(012) $(256) $(014) $(015)


