set terminal pngcairo size 800,600
set output 'bigotes.png'
set datafile separator ","

set style data yerrorbars
set boxwidth 0.5
set style fill solid 0.4
set title "Gráfica de Bigotes"
set xlabel "Grupo"
set ylabel "Valor"
set grid ytics

plot 'temp.csv' using 0:2:3:4:xtic(1) every ::1 with yerrorbars lc rgb "blue" lw 2 title "Medias ± rango"
