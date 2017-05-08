
//#define USE_OMP_FOR_SORT



#ifndef BLA
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#ifdef USE_OMP_FOR_SORT
#include <omp.h>
#endif
#include "MyAlgo.h"

using namespace std;
#define SHORT_FUNC_HEAPSORT
//#define SHORT_FUNC_MERGESORT
//#define SHORT_FUNC_QUICKSORT
//#define SHORT_FUNC_SHELLSORT

//#define PRINT_COMPLETE_TEXT

//#define USE_TEST_DATA //otherwise randomdata will be generated
#define ROOT_PATH "../MATLAB_STUFF/" //speicher ordner
#define FILE_SAVE_EXT ".txt" //endung
#define I_DONT_WAIT
#define USE_GCC_TIME

//wenn wir test daten benutzen wollen dann legen wir diret den vektor an sonst füllen wir den
//dafür brauchen wir aber den radonom header
#ifdef USE_TEST_DATA
std::vector<int> data_pool{0,98,44,30,22,64,63,11,23,8,18};
#else
#include "random_gen.h"
std::vector<int> data_pool;
#endif

//TEST DA BEI MIR OPENMP DIE TIMER NICHT GEHEH WIRD NOCH GELÖSCHT
//http://stackoverflow.com/questions/3756323/getting-the-current-time-in-milliseconds
#ifdef USE_GCC_TIME
#include <sys/time.h>
long long current_timestamp() {
    struct timeval te;
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // caculate milliseconds
    // printf("milliseconds: %lld\n", milliseconds);
    return milliseconds;
}

long start = 0;
long end = 0;
#endif



//hier werden die notendigen defines für jeden alogo gesetzt
//zZ nur den namen für die dateien erspart ein if :)
//und hier werden für die jeweiligen algos notwendige vars angelegt
#ifdef SHORT_FUNC_HEAPSORT
#define SORTING_ALGO_NAME "heapsort"
#else
#ifdef SHORT_FUNC_MERGESORT
#define SORTING_ALGO_NAME "mergesort"
int mergesort_low = 0;
int mergesort_high = 0;
std::vector<int> merge_sort_b_vector;

#else
#ifdef SHORT_FUNC_QUICKSORT
#define SORTING_ALGO_NAME "quicksort"
#else
#ifdef SHORT_FUNC_SHELLSORT
#define SORTING_ALGO_NAME "shellsort"
#endif
#endif
#endif
#endif



//einfach den speicher string zusammenbauen also root + name + ext
//wenn wir aber die daten nicht importieren wollen sondern nur normal anzeigen lassen wollen
//dann fügen wir noch _show hinzu
#ifdef PRINT_COMPLETE_TEXT
#define FILE_OUT_NAME ROOT_PATH SORTING_ALGO_NAME "_show" FILE_SAVE_EXT
#else
#define FILE_OUT_NAME ROOT_PATH SORTING_ALGO_NAME FILE_SAVE_EXT
#endif


//SOME PRINTING FUNCS
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




#ifdef  USE_OMP_FOR_SORT
#pragma omp parallel
#endif
int main(int argc, char** argv) {
    //OPEN FILE
    ofstream file;
    file.open(FILE_OUT_NAME,fstream::out);
    if(file.fail()){
        std::cout << "FILE OPEN FAILED" << std::endl;
        return -1;
    }
    //SET TIME VARS
    double dtime = 0.0; //tür time diff
    double time_sum = 0.0; //für die summe

    //SET LOOP PARAMETER AUFGABE ABER LEICH GEÄNTERT WEGEN WARTEN UND SO s. DEFINE OBEN
#ifdef USE_TEST_DATA
    int n_start = 1;
    int n_step = 1;
    int n_end = 10;
#else
#ifdef I_DONT_WAIT
    int n_start = 0;
    int n_step = 1;
    int n_end = 50;
#else
    int n_start = 1000;
    int n_step = 1000;
    int n_end = 1000000;
#endif
#endif

    //GENERATE RANDOM DATA IF WE DONT USE THE TEST DATA
#ifndef USE_TEST_DATA
    data_pool.clear();
    for (int j = 0; j < n_end; ++j) {
        data_pool.push_back(randomFrom(1, 100));
    }
    std::cout << data_pool.size() << " random zahlen erzeugt" << std::endl;
#endif
    //PRINT HEADLINE OF FILE
    print_file_headlines(&file);
    //erstelle einen wektor mit einer kopie der datein die wir dann sortiren
    std::vector<int> data_use_vector;
    data_use_vector.clear();

    //LOOP
    for (int n = n_start; n<n_end; n+=n_step) {
        cout << "n: " << n << endl;
        /**********************/
        // init data here //
        /**********************/
//lade daten zum sortieren
        data_use_vector = data_pool;
//für die einzelnen algos die init sachen
#ifdef SHORT_FUNC_MERGESORT
        mergesort_low = 0;
        mergesort_high = data_use_vector.size();
#endif



//SAVE TIME
#ifdef USE_OMP_FOR_SORT
        dtime = omp_get_wtime();
#endif

        const clock_t begin_time = clock();

        /**********************/
        // run algorithm here //
        /**********************/
#ifdef SHORT_FUNC_HEAPSORT
        MyAlgorithms::HeapSort(data_use_vector, data_use_vector.size());
#endif

#ifdef SHORT_FUNC_MERGESORT
        MyAlgorithms::MergeSort(data_use_vector,merge_sort_b_vector,mergesort_low,mergesort_high);
#endif



        //DSIPLAY HERE
#if defined(PRINT_COMPLETE_TEXT)
        print_vecotr("Durchgang " + std::to_string(n) + "->",data_use_vector,&file);
#else
#ifdef USE_OMP_FOR_SORT
        dtime = omp_get_wtime() - dtime;

#endif
#endif
        start = current_timestamp() -start;
float de  = float( clock () - begin_time ) /  CLOCKS_PER_SEC;
        file << n << "\t" << setprecision(10) <<de << endl;
        time_sum +=de;
    }

file << time_sum;
    //FINALER SORT + TIME SUMME AUSGEBEN NUR IN DER HSO FILE
#if defined(PRINT_COMPLETE_TEXT)
    print_vecotr("",data_use_vector,&file);
    file << "Finished in :" << time_sum << " sec" << std::endl;
#endif


    file.close();
}
#endif
