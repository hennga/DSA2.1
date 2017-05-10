reset
set autoscale x
set autoscale y
set xlabel "n [-]"
set ylabel "t [s]"
set key top left

plot \
"quicksort.txt" with linepoints title 'Quicksort',\
"mergesort.txt" with linepoints title 'Mergesort',\
"shellsort.txt" with linepoints title 'Shellsort',\
"heapsort.txt" with linepoints title 'Heapsort',\
