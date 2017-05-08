#ifndef _MYALGORITHMS_H_
#define _MYALGORITHMS_H_
#include <vector>
using namespace std;
#define SORT_D_TYPE int
namespace MyAlgorithms {

    //Heapsort
    void max_heapify(vector<SORT_D_TYPE> &a, int i, int n);
    void HeapSort(vector<SORT_D_TYPE> &a, int n);
    void HeapSortInit(vector<int> &a, int n);
    //MergeSort
    void Merge(vector<SORT_D_TYPE> &a, vector<SORT_D_TYPE> &b,int low, int pivot, int high);
    void MergeSort(vector<SORT_D_TYPE> &a, vector<SORT_D_TYPE> &b, int low, int high);
    void MergeInit(vector<int> &a, int n);
    //Quicksort
    void QuickSort(vector<int> &arr, int left, int right);
    void QuickSortInit(vector<int> &a, int n);
    //Shellsort

    //Matrix Multiplikation
    void MatrixMul_ColMajor(vector<double> &A,
                            vector<double> &B,
                            vector<double> &C,
                            int n);
    void MatrixMul_RowMajor(vector<double> &A,
                            vector<double> &B,
                            vector<double> &C,
                            int n);
} //end namespace

#endif //_MYALGORITHMS_H_