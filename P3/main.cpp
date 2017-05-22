
#define USE_OMP

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#define USE_OMP_MAT_ROW
#define USE_OMP_MAT_COL

#include "MyAlgo.h"
#include "random_gen.h"
#include <omp.h>

const unsigned int SORT_TYPE_ENUM_SIZE = 6;
enum SORT_TYPE_SELECTOR{
    ALGO_SORT_HEAPSORT = 0,
    ALGO_SORT_MERGESORT = 1,
    ALGO_SORT_QUICKSORT = 2,
    ALGO_SORT_SHELLSORT = 3,
    ALGO_MATRIX_MUL_COL = 4,
    ALGO_MATRIX_MUL_ROW = 5
};



 SORT_TYPE_SELECTOR selected_algorythm = SORT_TYPE_SELECTOR::ALGO_SORT_QUICKSORT;
const std::string SAFE_FILE_DIR = "../MATLAB_STUFF/";



int n_start = 2;
int n_step = 1;
unsigned int n_end = 10000;
double dtime = 0.0; //für delta time
std::vector<int> data_pool;
std::vector<double> data_pool_double;

using namespace std;
int main(int argc, char** argv) {

#ifdef USE_OMP
   int procs = omp_get_max_threads();
   std::cout << "openmp enabled set threads to " << procs << std::endl;
   omp_set_num_threads(procs);
#endif
   
   std::string algo_name = "";
   switch (selected_algorythm) {
	  case SORT_TYPE_SELECTOR::ALGO_SORT_HEAPSORT:
		 algo_name += "heapsort";
		 break;
	  case SORT_TYPE_SELECTOR::ALGO_SORT_MERGESORT:
		 algo_name += "mergesort";
		 break;
	  case SORT_TYPE_SELECTOR::ALGO_SORT_QUICKSORT:
		 algo_name += "quicksort";
		 break;
	  case SORT_TYPE_SELECTOR::ALGO_SORT_SHELLSORT:
		 algo_name += "shellsort";
		 break;
	  case SORT_TYPE_SELECTOR::ALGO_MATRIX_MUL_COL:
		 algo_name += "matrix_mul_col";
		 break;
	  case SORT_TYPE_SELECTOR::ALGO_MATRIX_MUL_ROW:
		 algo_name += "matrix_mul_row";
		 break;
	  default:
		 algo_name += "unknown";
		 break;
   }
   
   
   std::string final_file_name = "tmp.txt";
   //WENN WIR EINE MATRIX HABEN STEHT IM DATEINAMEN DIE DIMENSION
   if (selected_algorythm == SORT_TYPE_SELECTOR::ALGO_MATRIX_MUL_COL ||
	   selected_algorythm == SORT_TYPE_SELECTOR::ALGO_MATRIX_MUL_ROW) {
	  final_file_name =
	  SAFE_FILE_DIR + "MATRIX_DATA/" + algo_name + ".txt";
   } else {
	  final_file_name = SAFE_FILE_DIR + "SORT_DATA/" + algo_name + ".txt";
   }
   std::cout << "DATA WILL BE WRITTEN TO:" << std::endl << final_file_name << std::endl;
   
   std::ofstream file;
   file.open(final_file_name, std::fstream::out);
   if (file.fail()) {
	  std::cout << "FILE OPEN FAILED" << std::endl;
	  return -1;
   };
   
   
   data_pool_double.clear();
   for (int j = 0; j <= 4000000; ++j) {
	  data_pool_double.push_back(randomFrom(1.0f, 100.0f));
   };
   
   
   std::cout << data_pool_double.size() << " (double) random Zahlen erzeugt"
			 << std::endl;
   
   //einen vektor für das sortierte ergebnis
   unsigned int loop_counter = 0;
   
   
   
   std::vector<double> resultvector;
   
   
   for(int sharedLauf = n_start;sharedLauf<=n_end;sharedLauf+=n_step){
	
   
	  std::vector<double> matrix_mul_vector_a;
	  std::vector<double> matrix_mul_vector_b;
	  std::vector<double> matrix_mul_vector_result;
	  std::vector<int> data_use_vector;
	  data_use_vector.clear();
	  //die daten müssen unterschiedlich geladen werden wenn es eine matrix ist
	  //also bei der matrix m,ul müssen wir die zahlen in 2 vektoren splitten
	  if (selected_algorythm == SORT_TYPE_SELECTOR::ALGO_MATRIX_MUL_COL ||
		  selected_algorythm == SORT_TYPE_SELECTOR::ALGO_MATRIX_MUL_ROW) {
		 matrix_mul_vector_a.clear();
		 matrix_mul_vector_b.clear();
		 matrix_mul_vector_result.clear();
		 long size_half = (data_pool_double.size() / 2);
	  
		 for (int ij = 0; ij < (sharedLauf * sharedLauf); ++ij) {
			matrix_mul_vector_a.push_back((double) data_pool_double.at(ij));
			matrix_mul_vector_b.push_back((double) data_pool_double.at(size_half + ij));
			matrix_mul_vector_result.push_back(-1.0f);
		 }
		 //    std::cout << "data size mul a" << matrix_mul_vector_a.size() << std::endl;
		 //   std::cout << "data size mul b" << matrix_mul_vector_b.size() << std::endl;
	  } else {
		 //LADE DATEN IN DEN SORTIER VECTOR
		 data_use_vector.clear();
		 for (int i = 0; i <sharedLauf ; ++i) {
			data_use_vector.push_back((int) data_pool_double.at(i));
		 }
		 //  std::cout << "data size " << data_use_vector.size() << std::endl;
	  }
   
	  std::cout <<     "        n " << sharedLauf << endl;
   
	  /**********************/
	  // run algorithm here //
	  /**********************/

      double begin =0.0f;
	  double end = 0.0f;
   
   
	  
//#pragma omp parallel for ordered
//	  for(int u=1;u<=1;++u)
	  
		 begin = omp_get_wtime();
	  
		
		 
		 switch (selected_algorythm) {
			case SORT_TYPE_SELECTOR::ALGO_SORT_HEAPSORT:
			   MyAlgorithms::HeapSort(data_use_vector, data_use_vector.size());
			   break;
			case SORT_TYPE_SELECTOR::ALGO_SORT_MERGESORT:
			   MyAlgorithms::MergeSort(data_use_vector, 1, data_use_vector.size());
			   break;
			case SORT_TYPE_SELECTOR::ALGO_SORT_QUICKSORT:
			   MyAlgorithms::QuickSort(data_use_vector, 1, data_use_vector.size());
			   break;
			case SORT_TYPE_SELECTOR::ALGO_SORT_SHELLSORT:
			   MyAlgorithms::ShellSort(data_use_vector, data_use_vector.size());
			   break;
			case SORT_TYPE_SELECTOR::ALGO_MATRIX_MUL_COL:
			   MyAlgorithms::MatrixMul_ColMajor(matrix_mul_vector_a, matrix_mul_vector_b, matrix_mul_vector_result,
												(int) sqrt((double) matrix_mul_vector_a.size()));
			   break;
			case SORT_TYPE_SELECTOR::ALGO_MATRIX_MUL_ROW:
			   MyAlgorithms::MatrixMul_RowMajor(matrix_mul_vector_a, matrix_mul_vector_b, matrix_mul_vector_result,
												(int) sqrt((double) matrix_mul_vector_a.size()));
			   break;
			default:
			   break;
		 }
	  end = omp_get_wtime();
	  
	  
   
   
	  //CALC DELTA TIME AND PRINT THEM TO FILE
	  // start = current_timestamp() - start;
	  //double de = double(clock() - begin_time) / CLOCKS_PER_SEC;
	  double newtime = end-begin;
   
	  std::cout<<  newtime;
	  
   
	  file << sharedLauf << "\t" << setprecision(20) << newtime << endl;
		
	  
	  
   }
   
   //std::ostream_iterator<std::string> output_iterator(output_file, "\n");
   //std::copy(example.begin(), example.end(), output_iterator);
   
   
	  file.close();
	  
   
}
