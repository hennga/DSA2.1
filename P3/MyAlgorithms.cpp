#include "MyAlgorithms.h"

using namespace std;

namespace MyAlgorithms{

  //Heapsort
  void max_heapify(vector<int> &a, int i, int n) {
	  	/*******************************************/
		// implement heapsort helper function here //
		/*******************************************/ 

  }  
  void HeapSort(vector<int> &a, int n) {
	  	/***************************/
		// implement heapsort here //
		/***************************/ 
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
  
 //Quicksort
  void QuickSort(vector<int> &arr, int left, int right) {
	    /****************************/
		// implement quicksort here //
		/****************************/ 
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
 
