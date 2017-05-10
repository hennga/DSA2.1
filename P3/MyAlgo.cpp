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
    void Merge(vector<int> &a, int p, int q, int r) {

        int n1=q-p+1;
        int n2=r-q;
        int L[n1+1];
        int R[n2+1];
        for(int i=1;i<=n1;i++)
        {
            L[i]=a[p+i-1];
        }
        for(int j=1;j<=n2;j++)
        {
            R[j]=a[q+j];
        }
        L[n1+1]=999;
        R[n2+1]=999;
        int i=1, j=1;
        for(int k=p;k<=r;k++)
        {
            if(L[i]<=R[j])
            {
                a[k]=L[i];
                i=i+1;
            }
            else
            {
                a[k]=R[j];
                j=j+1;
            }
        }
    }

    void MergeSort(vector<int> &a, int p, int r) {
        int q;
        if(p<r)
        {
            q=(p+r)/2;
            MergeSort(a,p,q);
            MergeSort(a,q+1,r);
            Merge(a,p,q,r);
        }
    }
    void MergeSortInit(vector<int> &a, int n){

    }


    //Quicksort
    int partition(vector<int>& A, int p,int q) {
        int x= A[p];
        int i=p;
        int j;
        for(j=p+1; j<q; j++)
        {
            if(A[j]<=x)
            {
                i=i+1;
                swap(A[i],A[j]);
            }
        }
        swap(A[i],A[p]);
        return i;
    }
    void QuickSort(vector<int> &arr, int left, int right) {
        /****************************/
        // implement quicksort here //
        /****************************/
        int r;
        if(left<right)
        {
            r=partition(arr, left,right);
            QuickSort(arr,left,r);
            QuickSort(arr,r+1,right);
        }
    }
    void QuickSortInit(vector<int> &a, int n){

    }



    //SHELLSORT HIBBART
    void ShellSort(vector<SORT_D_TYPE> &a, int n){
        int i, j,k, increment, temp;
         int swp=0,comp=0;
        int val;
        val=log(n+1)/log(2);
        increment =pow(2,val)-1;
        while (increment > 0)
        {
            for (i=0;i<increment;i++)
            {
                for(j=0;j<n;j+=increment)
                {
                    temp=a[j];
                    for(k=j-increment;k>=0&&temp<a[k];k-=increment)
                    {
                        comp++;
                        swp++;
                        a[k+increment]=a[k];
                    }
                    a[k+increment]=temp;
                    swp++;
                }
            }
            comp++;
            val--;
            if(increment!=1)
                increment=pow(2,val)-1;
            else
                increment = 0;
        }
    }


    //MATRIX SHIT
    void MatrixMul_ColMajor(vector<double> &A, vector<double> &B, vector<double> &C, int n) {
        //lda, ldb, ldc are leading dimensions of matrices A,B and C
        int lda = n;
        int ldb = n;
        int ldc = n;
        double s = 0.0;

        for (int i=0; i<n ; i++) {
            for (int j=0; j<n ; j++) {
                s = 0.0;
                for (int k=0; k<n; k++) {
                    int r =i+k*lda;
                    int r1 = k+j*ldb;
                    s = s + A[r] * B[r1];
                }
                int r2 =i+j*ldc;
                int w = 0;

               // C[r2]=s;
            }
        }
    }

    void MatrixMul_RowMajor(vector<double> &A, vector<double> &B, vector<double> &C, int n) {
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
