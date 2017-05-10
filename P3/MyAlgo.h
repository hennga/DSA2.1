#ifndef _MYALGORITHMS_H_
#define _MYALGORITHMS_H_
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
using namespace std;
#define SORT_D_TYPE int
#define MATRIX_TYPE double
namespace MyAlgorithms {

    //Heapsort
    void max_heapify(vector<int> &a, int i, int n);
    void HeapSort(vector<int> &a, int n);
    void HeapSortInit(vector<int> &a, int n);
    //MergeSort
    void Merge(vector<int> &a, int p, int q, int r);
    void MergeSort(vector<int> &a,  int p, int r);
    void MergeInit(vector<int> &a, int n);
    //Quicksort
    void QuickSort(vector<int> &arr, int left, int right);
    void QuickSortInit(vector<int> &a, int n);
    //Shellsort
    void ShellSort(vector<int> &a, int n);
    //Matrix Multiplikation
    void MatrixMul_ColMajor(vector<double > &A,
                            vector<double > &B,
                            vector<double > &C,
                            int n);
    void MatrixMul_RowMajor(vector<double > &A,
                            vector<double > &B,
                            vector<double > &C,
                            int n);




    //SWAPT 2 ELEMENTE
    template <typename T> void swap(T& t1, T& t2) {
        T temp = std::move(t1);
        t1 = std::move(t2);
        t2 = std::move(temp);
    }


} //end namespace

#endif //_MYALGORITHMS_H_