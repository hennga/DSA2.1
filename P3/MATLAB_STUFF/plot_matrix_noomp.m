clear;
clc; 
close all;
fid=fopen('MATRIX_DATA/matrix_mul_col_NOMP.txt');
data=textscan(fid,'%d %f');
fclose ( fid );
x=data{1};
quicksort_y=data{2};
fid=fopen('MATRIX_DATA/matrix_mul_row_NOMP.txt');
data=textscan(fid,'%d %f')
fclose ( fid );
mergesort_y=data{2};
figure ;
title ('M*M algorithms');
xlabel('n [-]');
ylabel('t [s]');
hold on;
plot(x, quicksort_y);
plot(x, mergesort_y);
legend('ROW','COL','Location','northwest');
hold off ;