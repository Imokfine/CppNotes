set title "10x10 grid, k=0.5, 100 steps"
set datafile separator ","
set xrange [0:10]
set yrange [0:10]
set grid
plot "output3.txt" with lines title "path followed"

