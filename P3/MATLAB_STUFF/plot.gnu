reset
set autoscale x
set autoscale y
set xlabel "n [-]"
set ylabel "t [s]"
set key top left

plot \
"SORT_DATA/quicksort.txt" with linepoints title 'Quicksort',\
"SORT_DATA/mergesort.txt" with linepoints title 'Mergesort',\
"SORT_DATA/shellsort.txt" with linepoints title 'Shellsort',\
"SORT_DATA/heapsort.txt" with linepoints title 'Heapsort',\
