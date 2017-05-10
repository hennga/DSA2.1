
#define USE_OMP_FOR_SORT

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "MyAlgo.h"
#include "random_gen.h"
#include <sys/time.h>
enum SORT_TYPE_SELECTOR{
    ALGO_SORT_HEAPSORT = 0,
    ALGO_SORT_MERGESORT = 1,
    ALGO_SORT_QUICKSORT = 2,
    ALGO_SORT_SHELLSORT = 3
};



const unsigned int PROBLEMGROESSE_SORT = 10000;
const unsigned int LOOPS_SORT = 100;
const SORT_TYPE_SELECTOR selected_algorythm = SORT_TYPE_SELECTOR::ALGO_SORT_HEAPSORT;
const bool use_test_data = false;
const char* SAFE_FILE_DIR = "../MATLAB_STUFF/DATA/"; //make sure the folder exits
std::vector<int> data_pool{0,98,44,30,22,64,63,11,23,8,18};//HIER TESTDATEN EINGEBEN wird später überschrieben wenn das bool oben falsch ist


long start = 0;
int n_start = 1;
int n_step = 1;
unsigned int n_end = 10;
unsigned int do_loops = LOOPS_SORT;










//gibt den aktuelle system timestamp zurück
long long current_timestamp() {
    struct timeval te;
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // caculate milliseconds
    return milliseconds;
}
void print_vecotr(std::string _text, std::vector<int>& _a, std::ofstream* _file = nullptr, int _start = 1, int _end =0){
    std::cout << _text << " ";
    if(_file != nullptr){
        *_file << _text;
    }
    for (int i = _start; i < _a.size()+_end; i++)
    {
        if(_file != nullptr){
        *_file << " " << _a[i];
        }
        std::cout << " "<< _a[i];
    }
    std::cout << std::endl;
    if(_file != nullptr){
        *_file << std::endl;
    }
}
void print_file_headlines(std::ofstream* _file = nullptr){
#if defined(SHORT_FUNC_HEAPSORT) && defined(PRINT_COMPLETE_TEXT)
   if(_file != nullptr) {
       *_file << "----------" << SORTING_ALGO_NAME << "-------------" << std::endl;
   }
       std::cout << "----------" << SORTING_ALGO_NAME << "-------------"<< std::endl;
#endif


}


int main(int argc, char** argv) {
    //bestimme den namen des sortier algos wäre per define einfacher gewesen :D
    std::string algo_name = "unknown";
    switch(selected_algorythm){
        case SORT_TYPE_SELECTOR::ALGO_SORT_HEAPSORT:
            algo_name = "heapsort";
            break;
        case SORT_TYPE_SELECTOR ::ALGO_SORT_MERGESORT:
            algo_name = "mergesort";
            break;
        case SORT_TYPE_SELECTOR ::ALGO_SORT_QUICKSORT:
            algo_name = "quicksort";
            break;
        case SORT_TYPE_SELECTOR::ALGO_SORT_SHELLSORT:
            algo_name = "shellsort";
            break;
        default:
            algo_name = "unknown";
            break;
    }

    //hier steht der output file path drin
    std::string final_file_name = SAFE_FILE_DIR +algo_name + "_" + std::to_string(PROBLEMGROESSE_SORT) + "_" + std::to_string(LOOPS_SORT) + ".txt";

    //OPEN FILE
    std::ofstream file;
    file.open(final_file_name,std::fstream::out);
    if(file.fail()){
        std::cout << "FILE OPEN FAILED" << std::endl;
        return -1;
    }
    std::cout << "DATA WILL BE WRITTEN TO:" <<std::endl << final_file_name << std::endl;

    //SET TIME VARS
    double dtime = 0.0; //für delta time


//sollen keine testdaten benutz werden random generieren
if(use_test_data) {
    n_start = 1;
    n_step = 1;
    n_end = data_pool.size();
}else {
    do_loops = LOOPS_SORT;
    n_start = 1;
    n_step = PROBLEMGROESSE_SORT; //=Problemgrösse
    n_end = n_start * (do_loops * n_step);
    //GENERATE RANDOM DATA IF WE DONT USE THE TEST DATA
    data_pool.clear();
    for (int j = 0; j < n_end + n_step + n_start; ++j) {
        data_pool.push_back(randomFrom(1, 100));
    }
    std::cout << data_pool.size() << " random zahlen erzeugt" << std::endl;
}




    //PRINT HEADLINE OF FILE
    print_file_headlines(&file);
    //einen vektor für das sortierte ergebnis
    std::vector<int> data_use_vector;
    data_use_vector.clear();
    unsigned int loop_counter = 0;

    //SETUP OMP
    //int num procs = omp get num procs();
    //omp set num threads(num procs);

    //LOOP pragma für openmp
    #pragma omp parallel for
    for (int n = n_start; n<n_end; n+=n_step) {
        loop_counter++;
        std::cout << "n: " << loop_counter << endl;

        //lade daten zum sortieren
        data_use_vector.clear();
        if(use_test_data) {
            data_use_vector = data_pool;
        }else {
            for (int i = 0; i < n_step; ++i) {
                if (i + n > data_pool.size()) {
                    std::cout << "e";
                    break;
                }
                data_use_vector.push_back((int) data_pool.at(n + i));
            }
        }


        //SAVE TIME BEFORE RUNNING
        const clock_t begin_time = clock();
        /**********************/
        // run algorithm here //
        /**********************/
        switch(selected_algorythm){
            case SORT_TYPE_SELECTOR::ALGO_SORT_HEAPSORT:
                MyAlgorithms::HeapSort(data_use_vector, data_use_vector.size());
                break;
            case SORT_TYPE_SELECTOR ::ALGO_SORT_MERGESORT:
                MyAlgorithms::MergeSort(data_use_vector,1,data_use_vector.size());
                break;
            case SORT_TYPE_SELECTOR ::ALGO_SORT_QUICKSORT:
                MyAlgorithms::QuickSort(data_use_vector,1,data_use_vector.size());
                break;
            case SORT_TYPE_SELECTOR::ALGO_SORT_SHELLSORT:
                MyAlgorithms::ShellSort(data_use_vector,data_use_vector.size());
                break;
            default:
                break;
        }



        //CALC DELTA TIME AND PRINT THEM TO FILE
        start = current_timestamp() -start;
	    double de  = double( clock () - begin_time ) /  CLOCKS_PER_SEC;
        file << n << "\t" << setprecision(10) <<de << endl;

    }
    file.close();
}

