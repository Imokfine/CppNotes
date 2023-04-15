set title "10x10 grid, k=1.0, 100 steps"
set datafile separator ","
set xrange [0:10]
set yrange [0:10]
set grid
plot "output4.txt" with lines title "path followed"

