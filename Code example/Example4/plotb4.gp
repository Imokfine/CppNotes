set key outside
set title "k=0, 100 initially infected"
set xlabel "timestep"
set ylabel "people"
set datafile separator ","
set style data lines
set xrange [0:36]
set yrange [0:10000]
plot '200x200_p10000_i100_k0_d0.2_t0.2.txt' using 1:($3+$4+$5+$6) with filledcurves x1 title "didn't catch" lc rgb "#E69F00", \
'200x200_p10000_i100_k0_d0.2_t0.2.txt' using 1:($3+$4+$5) with filledcurves x1 title "dead" lc rgb "#56B4E9", \
'200x200_p10000_i100_k0_d0.2_t0.2.txt' using 1:($3+$4) with filledcurves x1 title "reovered" lc rgb "#009E73", \
'200x200_p10000_i100_k0_d0.2_t0.2.txt' using 1:3 with filledcurves x1 title "currently infected" lc rgb "#9400D3"
