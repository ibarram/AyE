set datafile separator ','

set terminal pngcairo size 1000,600 enhanced font 'Arial,12'
set output 'histograma.png'

set title "Histograma de Datos por Año"
set xlabel "Año"
set ylabel "Valor"
set grid ytics

set style data histograms
set style fill solid 0.6 border -1
set boxwidth 0.7
set key off

set xtics rotate by -45

plot 'datos.csv' using 2:xtic(1) title 'Datos'

unset output
