

clear;
clc; 
close all;
fid=fopen('SORT_DATA/quicksort.txt');
data=textscan(fid,'%d %f');
fclose ( fid );
x=data{1};
quicksort_y=data{2};
fid=fopen('SORT_DATA/mergesort.txt');
data=textscan(fid,'%d %f')
fclose ( fid );
mergesort_y=data{2};
fid=fopen('SORT_DATA/heapsort.txt');
data=textscan(fid,'%d %f');
fclose ( fid );
heapsort_y=data{2};
fid=fopen('SORT_DATA/shellsort.txt');
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
legend('heapsort','quicksort','mergesort','shellsort','Location','northwest');
hold off ;
