# --- Salida ---
set terminal pngcairo size 900,600
set output 'bigotes.png'

# --- Datos ---
set datafile separator ","

# --- Apariencia ---
set title "Gráfica de Bigotes"
set xlabel "Grupo (número)"
set ylabel "Valor"
set grid xtics ytics mxtics mytics

# Deja espacio a la derecha para el cuadro externo
set rmargin 23   # ajusta si hace falta más/menos espacio

# Eje X con números (1..N) en lugar de nombres
# ($0+1) posiciona 1,2,3,... y xtic etiqueta con ese número
set xtics rotate by 60 offset 0,-1

# Opcional: quita la leyenda estándar
unset key

# --- Construir texto de la equivalencia NOMBRE -> NÚMERO desde el CSV ---
# Requiere awk (está en Linux). Salta encabezado y genera "1 = A\n2 = B\n..."
LEG = system("awk -F, 'NR>1{printf \"%d = %s\\n\", NR-1, $1}' temp.csv")

# --- Colocar el cuadro a la derecha, fuera del área de ploteo ---
# Coordenadas 'graph' (1.0 es el borde derecho del gráfico). Ajusta 1.02/0.98 a gusto.
set label 100 LEG at graph 1.02,1 left front tc rgb "black" boxed offset 1,-1

# --- Trazo de bigotes ---
# using ($0+1):2:3:4 => X=número, Y=media (col 2), min=col 3, max=col 4
# every ::1 salta el encabezado
plot 'temp.csv' using ($0+1):2:3:4:xtic(sprintf("%d",$0+1)) every ::1 \
     with yerrorbars lc rgb "blue" lw 2 notitle
