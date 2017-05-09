#ifndef _MYALGORITHMS_H_
#define _MYALGORITHMS_H_
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define SORT_D_TYPE int
#define MATRIX_TYPE double
namespace MyAlgorithms {

    //Heapsort
    void max_heapify(vector<SORT_D_TYPE> &a, int i, int n);
    void HeapSort(vector<SORT_D_TYPE> &a, int n);
    void HeapSortInit(vector<int> &a, int n);
    //MergeSort
    void Merge(vector<SORT_D_TYPE> &a, vector<SORT_D_TYPE> &b,int low, int pivot, int high);
    void MergeSort(vector<SORT_D_TYPE> &a, vector<SORT_D_TYPE> &b, int low, int high);
    void MergeInit(vector<SORT_D_TYPE> &a, int n);
    //Quicksort
    void QuickSort(vector<SORT_D_TYPE> &arr, int left, int right);
    void QuickSortInit(vector<SORT_D_TYPE> &a, int n);
    //Shellsort

    //Matrix Multiplikation
    void MatrixMul_ColMajor(vector<MATRIX_TYPE> &A,
                            vector<MATRIX_TYPE> &B,
                            vector<MATRIX_TYPE> &C,
                            int n);
    void MatrixMul_RowMajor(vector<MATRIX_TYPE> &A,
                            vector<MATRIX_TYPE> &B,
                            vector<MATRIX_TYPE> &C,
                            int n);





    template <typename T> void swap(T& t1, T& t2) {
        T temp = std::move(t1);
        t1 = std::move(t2);
        t2 = std::move(temp);
    }


} //end namespace

#endif //_MYALGORITHMS_H_