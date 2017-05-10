
#define USE_OMP_FOR_SORT

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "MyAlgo.h"
#include "random_gen.h"
#include <sys/time.h>
#include <omp.h>

enum SORT_TYPE_SELECTOR{
    ALGO_SORT_HEAPSORT = 0,
    ALGO_SORT_MERGESORT = 1,
    ALGO_SORT_QUICKSORT = 2,
    ALGO_SORT_SHELLSORT = 3,
    ALGO_MATRIX_MUL_COL = 4,
    ALGO_MATRIX_MUL_ROW = 5
};


const unsigned int PROBLEMGROESSE_SORT = 4;
const unsigned int LOOPS_SORT = 100;
const SORT_TYPE_SELECTOR selected_algorythm = SORT_TYPE_SELECTOR::ALGO_MATRIX_MUL_COL;
const char* SAFE_FILE_DIR = "../MATLAB_STUFF/DATA/"; //make sure the folder exits
std::vector<int> data_pool{0,98,44,30,22,64,63,11,23,8,18};//HIER TESTDATEN EINGEBEN wird später überschrieben wenn das bool oben falsch ist
std::vector<double> data_pool_double;

long start = 0;
int n_start = 1;
int n_step = 1;
unsigned int n_end = 10;
unsigned int do_loops = LOOPS_SORT;
double dtime = 0.0; //für delta time









//gibt den aktuelle system timestamp zurück == OPENMP FIX
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
        case SORT_TYPE_SELECTOR::ALGO_MATRIX_MUL_COL:
            algo_name = "matrix_mul_col";
            break;
        case SORT_TYPE_SELECTOR::ALGO_MATRIX_MUL_ROW:
            algo_name = "matrix_mul_row";
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




    do_loops = LOOPS_SORT;
    n_start = 1;
    n_step = PROBLEMGROESSE_SORT; //=Problemgrösse


    if(selected_algorythm == SORT_TYPE_SELECTOR::ALGO_MATRIX_MUL_COL || selected_algorythm == SORT_TYPE_SELECTOR::ALGO_MATRIX_MUL_ROW) {
        //wir brauchen die anzahl der zahlen 2x da wir 2 matrizzen füllen wollen
        n_end = n_start * (do_loops * n_step*2);
        data_pool_double.clear();
        for (int j = 0; j < n_end + n_step + n_start; ++j) {
            data_pool_double.push_back(randomFrom(1.0f, 100.0f));
        }
        std::cout << data_pool_double.size() << " (double) random zahlen für Matrix multiplikazion erzeugt" << std::endl;
    }else {
        n_end = n_start * (do_loops * n_step);
        //GENERATE RANDOM DATA IF WE DONT USE THE TEST DATA
        data_pool.clear();
        for (int j = 0; j < n_end + n_step + n_start; ++j) {
            data_pool.push_back(randomFrom(1, 100));
        }
        std::cout << data_pool.size() << " (int) random zahlen erzeugt" << std::endl;
    }




    //einen vektor für das sortierte ergebnis
    std::vector<int> data_use_vector;
    data_use_vector.clear();
    unsigned int loop_counter = 0;

    //VEKTOREN FÜR MATRIX MUL
    std::vector<double> matrix_mul_vector_a;
    std::vector<double> matrix_mul_vector_b;
    std::vector<double> matrix_mul_vector_result;
    //SETUP OMP
    //int num procs = omp get num procs();
    //omp set num threads(num procs);

    //LOOP pragma für openmp
    #pragma omp parallel for
    for (int n = n_start; n<n_end; n+=n_step) {
        loop_counter++;
        std::cout << "n: " << loop_counter << endl;
        if(loop_counter >= 100){break;}
        //die daten müssen unterschiedlich geladen werden wenn es eine matrix ist
        //also bei der matrix m,ul müssen wir die zahlen in 2 vektoren splitten
        if(selected_algorythm == SORT_TYPE_SELECTOR::ALGO_MATRIX_MUL_COL || selected_algorythm == SORT_TYPE_SELECTOR::ALGO_MATRIX_MUL_ROW) {
            matrix_mul_vector_a.clear();
            matrix_mul_vector_b.clear();
            matrix_mul_vector_result.clear();
            //wo ist die mitte des vectors
            int size_half = (double)(data_pool_double.size()/2.0f);
            for (int i = 0; i < PROBLEMGROESSE_SORT; ++i) {
                //wir füllen in den vector a die erste hälfte der erzeugten zahlen
                //und in b die 2. obere hälfte
                matrix_mul_vector_a.push_back((double)data_pool_double.at(n + i));
                matrix_mul_vector_b.push_back((double)data_pool_double.at(n + i+size_half));
                matrix_mul_vector_result.push_back(-1.0f);
            }
        }else{
            //lade daten zum sortieren
            data_use_vector.clear();
                for (int i = 0; i < PROBLEMGROESSE_SORT; ++i) {
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
            case SORT_TYPE_SELECTOR::ALGO_MATRIX_MUL_COL:
              MyAlgorithms::MatrixMul_ColMajor(matrix_mul_vector_a,matrix_mul_vector_b,matrix_mul_vector_result,(int)sqrt((double)matrix_mul_vector_a.size()));
                break;
            case SORT_TYPE_SELECTOR::ALGO_MATRIX_MUL_ROW:
                MyAlgorithms::MatrixMul_RowMajor(matrix_mul_vector_a,matrix_mul_vector_b,matrix_mul_vector_result,(int)sqrt((double)matrix_mul_vector_a.size()));
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

