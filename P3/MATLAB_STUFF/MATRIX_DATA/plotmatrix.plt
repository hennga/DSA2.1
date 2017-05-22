reset
set autoscale x
set autoscale y
set xlabel " n []"
set ylabel " n[s]"

set key top left


plot\
"matrix_mul_col.txt" with linespoints title "column",\
"matrix_mul_row.txt" with linespoints title "row",\
