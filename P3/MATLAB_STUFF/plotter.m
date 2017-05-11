base_dir='DATA_SORT/';
loop_string ='100';
pron_string = '1000';

heapsort_name= 'heapsort';
quicksort_name='quicksort';
mergesort_name='mergesort';
shellsort_name='shellsort';


clear;
clc; 
close all;
fid=fopen([base_dir heapsort_name '/' heapsort_name '_' loop_string '_' pron_string '.txt']);
data=textscan(fid,'%d %f');
fclose ( fid );
x=data{1};
quicksort_y=data{2};
fid=fopen([base_dir mergesort_name '/' mergesort_name '_' loop_string '_' pron_string '.txt']);
data=textscan(fid,'%d %f')
fclose ( fid );
mergesort_y=data{2};
fid=fopen([base_dir heapsort_name '/' heapsort_name '_' loop_string '_' pron_string '.txt']);
data=textscan(fid,'%d %f');
fclose ( fid );
heapsort_y=data{2};
fid=fopen([base_dir shellsort_name '/' shellsort_name '_' loop_string '_' pron_string '.txt']);
data=textscan(fid,'%d %f');
fclose ( fid );
shellsort_y =data{2};
figure ;
title ('sorting algorithms');
xlabel('n [-]');
ylabel('t [s]');
hold on;
plot(x, quicksort_y);
plot(x, mergesort_y);
plot(x,heapsort_y);
plot(x, shellsort_y );
legend('quicksort','mergesort','heapsort','shellsort','Location','northwest');
hold off ;
