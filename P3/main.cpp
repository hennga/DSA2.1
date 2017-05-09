
#define USE_OMP_FOR_SORT

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "MyAlgo.h"


//#define SHORT_FUNC_HEAPSORT
//#define SHORT_FUNC_MERGESORT
//#define SHORT_FUNC_QUICKSORT
#define SHORT_FUNC_SHELLSORT

#define PRINT_COMPLETE_TEXT

#define USE_TEST_DATA //otherwise randomdata will be generated


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
#include <sys/time.h>
long long current_timestamp() {
    struct timeval te;
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // caculate milliseconds
    return milliseconds;
}
long start = 0;





//hier werden die notendigen defines für jeden alogo gesetzt
//zZ nur den namen für die dateien erspart ein if :)
//und hier werden für die jeweiligen algos notwendige vars angelegt
#ifdef SHORT_FUNC_HEAPSORT
#define SORTING_ALGO_NAME "heapsort"
#else
#ifdef SHORT_FUNC_MERGESORT
#define SORTING_ALGO_NAME "mergesort"
#else
#ifdef SHORT_FUNC_QUICKSORT
#define SORTING_ALGO_NAME "quicksort"
#else
#ifdef SHORT_FUNC_SHELLSORT
#define SORTING_ALGO_NAME "shellsort"
#else
#error "PLEASE SELECT A SORTING METHOD"
#endif
#endif
#endif
#endif



//einfach den speicher string zusammenbauen also root + name + ext
//wenn wir aber die daten nicht importieren wollen sondern nur normal anzeigen lassen wollen
//dann fügen wir noch _show hinzu
#ifdef PRINT_COMPLETE_TEXT
#define FILE_OUT_NAME "../MATLAB_STUFF/" SORTING_ALGO_NAME "_show" ".txt"
#else
#define FILE_OUT_NAME "../MATLAB_STUFF/" SORTING_ALGO_NAME ".txt"
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

//if we want only use the test data we only made 10 loops
int n_start = 1;
int n_step = 1;
int n_end = 10;


int main(int argc, char** argv) {
    //OPEN FILE
    std::ofstream file;
    file.open(FILE_OUT_NAME,std::fstream::out);
    if(file.fail()){
        std::cout << "FILE OPEN FAILED" << std::endl;
        return -1;
    }
    //SET TIME VARS
    double dtime = 0.0; //für delta time
    double time_sum = 0.0; //für die summe gebrauchter zeit

    //SET LOOP PARAMETER AUFGABE ABER LEICH GEÄNTERT WEGEN WARTEN UND SO s. DEFINE OBEN
#ifdef USE_TEST_DATA
     n_start = 1;
     n_step = 1;
     n_end = 10;
#else
     n_start = 1000;
     n_step = 10000;
     n_end = 10000000;

    //GENERATE RANDOM DATA IF WE DONT USE THE TEST DATA
    data_pool.clear();
    for (int j = 0; j < n_end+n_step+n_start; ++j) {
        data_pool.push_back(randomFrom(1, 100));
    }
    std::cout << data_pool.size() << " random zahlen erzeugt" << std::endl;
    #endif




    //PRINT HEADLINE OF FILE
    print_file_headlines(&file);
    //erstelle einen vektor mit einer kopie der datein die wir dann sortiren
    std::vector<int> data_use_vector;
    data_use_vector.clear();


    //SETUP OMP
    //int num procs = omp get num procs();
    //omp set num threads(num procs);

    //LOOP
    #pragma omp parallel for
    for (int n = n_start; n<n_end; n+=n_step) {
        std::cout << "n: " << n << endl;
        /**********************/
        // init data here //
        /**********************/
        //lade daten zum sortieren
data_use_vector.clear();
#ifdef USE_TEST_DATA
        data_use_vector = data_pool;
#else
        for (int i = 0; i < n_step; ++i) {
            if(i+n > data_pool.size()){break;}
            data_use_vector.push_back((int)data_pool.at(n+i));
        }

#endif




        //SAVE TIME BEFORE RUNNING
        const clock_t begin_time = clock();

        /**********************/
        // run algorithm here //
        /**********************/
#ifdef SHORT_FUNC_HEAPSORT
        MyAlgorithms::HeapSort(data_use_vector, data_use_vector.size());
#endif

#ifdef SHORT_FUNC_MERGESORT
        MyAlgorithms::MergeSort(data_use_vector,1,data_use_vector.size());
#endif

#ifdef SHORT_FUNC_QUICKSORT
        MyAlgorithms::QuickSort(data_use_vector,0,data_use_vector.size());
#endif

#ifdef SHORT_FUNC_SHELLSORT
     MyAlgorithms::ShellSort(data_use_vector,data_use_vector.size());
#endif


        
        //DSIPLAY HERE
#if defined(PRINT_COMPLETE_TEXT)
        print_vecotr("Durchgang " + std::to_string(n) + "->",data_use_vector,&file);
#endif



        //CALC DELTA TIME
        start = current_timestamp() -start;
	    double de  = double( clock () - begin_time ) /  CLOCKS_PER_SEC;
        file << n << "\t" << setprecision(10) <<de << endl;
        time_sum +=de;
    }



    //FINALER SORT + TIME SUMME AUSGEBEN NUR IN DER HSO FILE
#if defined(PRINT_COMPLETE_TEXT)
    print_vecotr("",data_use_vector,&file);
    file << "Finished in :" << time_sum << " sec" << std::endl;
#endif


    file.close();
}

