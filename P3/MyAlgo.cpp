//
// Created by marcel on 5/8/17.
//

#include "MyAlgo.h"
using namespace std;

namespace MyAlgorithms{

    //Heapsort
    void max_heapify(vector<int> &a, int i, int n) {
        int l,r,largest,loc;
        l=2*i;
        r=(2*i+1);
        if((l<=n)&&a[l]>a[i])
            largest=l;
        else
            largest=i;
        if((r<=n)&&(a[r]>a[largest]))
            largest=r;
        if(largest!=i)
        {
            loc=a[i];
            a[i]=a[largest];
            a[largest]=loc;
            max_heapify(a, largest,n);
        }
    }
    void HeapSort(vector<int> &a, int n) {
        HeapSortInit(a,n);
        int i, temp;
        for (i = n; i >= 2; i--)
        {
            temp = a[i];
            a[i] = a[1];
            a[1] = temp;
            max_heapify(a, 1, i-1);
        }
    }
    void HeapSortInit(vector<int> &a, int n)
    {
        int i;
        for(i = n/2; i >= 1; i--)
        {
            max_heapify(a, i, n);
        }
    }


    //MergeSort
    void Merge(vector<int> &a, vector<int> &b,int low, int pivot, int high) {
        /********************************************/
        // implement mergesort helper function here //
        /********************************************/

    }

    void MergeSort(vector<int> &a, vector<int> &b, int low, int high) {
        /****************************/
        // implement mergesort here //
        /****************************/

    }
    void MergeSortInit(vector<int> &a, int n){

    }

    //Quicksort
    void QuickSort(vector<int> &arr, int left, int right) {
        /****************************/
        // implement quicksort here //
        /****************************/
    }
    void QuickSortInit(vector<int> &a, int n){

    }


    void MatrixMul_ColMajor(vector<double> &A, vector<double> &B, vector<double> &C,
                            int n) {
        //lda, ldb, ldc are leading dimensions of matrices A,B and C
        int lda = n;
        int ldb = n;
        int ldc = n;
        double s = 0.0;

        for (int i=0; i<n ; i++) {
            for (int j=0; j<n ; j++) {
                s = 0.0;
                for (int k=0; k<n; k++) {
                    s = s + A[i+k*lda] * B[k+j*ldb];
                }
                C[i+j*ldc]=s;
            }
        }
    }

    void MatrixMul_RowMajor(vector<double> &A, vector<double> &B, vector<double> &C,
                            int n) {
        //lda, ldb, ldc are leading dimensions of matrices A,B and C
        int lda = n;
        int ldb = n;
        int ldc = n;
        double s = 0.0;
        /***************************************/
        // implement row major calculation here//
        /***************************************/
    }

} // end namespace
