


#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
//#include <omp.h>
#include "MyAlgo.h"

using namespace std;


#define USE_TEST_DATA //otherwise randomdata will be
#ifdef USE_TEST_DATA
std::vector<int> data_pool{94,44,30,22,64,63,11,23,8,18};
#endif




#define PRINT_COMPLETE_TEXT
#define SHORT_FUNC_HEAPSORT

#ifdef SHORT_FUNC_HEAPSORT
#if defined(_WIN64) || defined(_WIN32) || defined(WINDOOF) || defined(_MSC_VER)
#define FILE_OUT_NAME "MATLAB_STUFF/heapsort.txt"
#else
#define FILE_OUT_NAME "./MATLAB_STUFF/heapsort.txt"
#endif
#endif


int main(int argc, char** argv) {
    ofstream file;
    file.open(FILE_OUT_NAME);
    double dtime;

//#ifdef USE_TEST_DATA
  //  int n_start = 0;
  //  int n_step = 1;
  //  int n_end = 10;
//#else
    int n_start = 1000;
    int n_step = 1000;
    int n_end = 1000000;
//#endif

#if defined(SHORT_FUNC_HEAPSORT) && defined(PRINT_COMPLETE_TEXT)
	file << "Heap Sort:" << std::endl;
#endif


    for (int n = n_start; n<n_end; n+=n_step) {
        cout << "n: " << n << endl;
        /**********************/
        // init data here //
        /**********************/

#if defined(SHORT_FUNC_HEAPSORT) && defined(PRINT_COMPLETE_TEXT)
		file << "Durchlauf " << n;
		for (size_t i = 0; i < data_pool.size(); i++)
		{
			file << " " << data_pool.at(i);
		}
		file << std::endl;
#endif


    //    dtime = omp_get_wtime();
		#ifdef SHORT_FUNC_HEAPSORT
		MyAlgorithms::HeapSort(data_pool, data_pool.size());
		#endif
        /**********************/
        // run algorithm here //
        /**********************/
  //      dtime = omp_get_wtime() - dtime;
  //     file << n << "\t" << scientific << setprecision(10) << dtime << endl;
    }
    file.close();
}