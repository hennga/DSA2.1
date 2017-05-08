#ifndef _MYALGORITHMS_H_
#define _MYALGORITHMS_H_
#include <vector>
using namespace std;

namespace MyAlgorithms { 

  //Heapsort
  void max_heapify(vector<int> &a, int i, int n);	
  void HeapSort(vector<int> &a, int n);
  
  //MergeSort
  void Merge(vector<int> &a, vector<int> &b,int low, int pivot, int high);
  void MergeSort(vector<int> &a, vector<int> &b, int low, int high);

  //Quicksort
  void QuickSort(vector<int> &arr, int left, int right);

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
