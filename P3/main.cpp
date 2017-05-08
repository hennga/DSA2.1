#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <omp.h>
#include "MyAlgorithms.h"

using namespace std;


#define USE_TEST_DATA //otherwise randomdata will be



int main(int argc, char** argv) {
  ofstream file;
  file.open("example.txt");
  double dtime;
  #ifdef USE_TEST_DATA
  int n_start = 0;
  int n_step = 1;
  int n_end = 10;
  #else
  int n_start = 1000;
  int n_step = 1000;
  int n_end = 1000000;
  #endif
  for (int n = n_start; n<n_end; n+=n_step) {
    cout << "n: " << n << endl;
    /**********************/
    // init data here //
    /**********************/

    dtime = omp_get_wtime();
    /**********************/
    // run algorithm here //
    /**********************/
    dtime = omp_get_wtime() - dtime;
    file << n << "\t" << scientific << setprecision(10) << dtime << endl;
  }
  file.close();
}
