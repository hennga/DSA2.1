#include <iostream>
#include "P4_graph.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int files_in_array = 3;
const char* file_paths[3] = {"../graphs/graph1.txt", "../graphs/graph2.txt","../graphs/graph3.txt"};



void displayMenu(bool is_graph_init)
{
    std::cout << "Please choose:" << std::endl;
    if(!is_graph_init) {
        std::cout << "1) Graph einlesen" << std::endl;
    }else {
        std::cout << "2) Tiefensuche" << std::endl
                  << "3) Breitensuche " << std::endl
                  << "4) Prim" << std::endl
                  << "5) Kruskal" << std::endl
                  << "6) Print Graph as nodelist" << std::endl
                  << "0 for quit" << std::endl;

    }
    std::cout << "?> ";
}


int main() {


    //Insert a switch-case to call your algorithms
    //Maybe you can copy from older Projects
    Graph* myGraph = new Graph();
    int menuwahl=-1;
    int key=-1;

    while(menuwahl != 0){

        do{
            displayMenu(myGraph->is_init);
            std::cin >> menuwahl;
        }while(menuwahl>6 || menuwahl < 0);

        //Read Graph
        if(menuwahl==1)
        {
            std::cout << "Insert num of file: " << std::endl;
            for (int i = 0; i < files_in_array; ++i) {
                std::cout << i << " : " << file_paths[i]<< std::endl;
            }


            int ind = -1;
            while(ind < 0 || ind >= files_in_array){
                std::cout << "?-";
                std::cin >> ind;
            }


            bool done = myGraph->init(file_paths[ind]);

            if(done) {
                std::cout << "Initialize graph successful" << std::endl;
            }else {
                std::cout << "Cannot read file" << std::endl;
            }
        }

        //Depthsearch1
        if(menuwahl==2)
        {

            std::cout << "Choose a startkey to search for: " << std::endl;
            std::cin >> key;

            //This way:
           if(myGraph->depthSearchRecStart(key)){
               std::cout << "key found" << std::endl;

           }else{
               std::cout << " not found" << std::endl;
           }

        }

        //Breadthsearch
        if(menuwahl==3){

            std::cout << "Choose a startkey: " << std::endl;
            std::cin >> key;
            //Or this:

            if( myGraph->breadthSearchIter(key)){
                std::cout << "key found" << std::endl;
			    std::cout << "________________________________ " << std::endl;
			   std::cout << std::endl;
			   

            }else{
                std::cout << "Baum nicht zusammenhaengend" << std::endl;
			   std::cout << "________________________________ " << std::endl;
			   std::cout << std::endl;
            }
        }

        //Prim
        if(menuwahl==4){
            std::cout << "Choose a startkey: " << std::endl;
            std::cin >> key;
		   
		   std::cout <<  myGraph->prim(key);
		   std::cout << std::endl;
		   std::cout << "________________________________ " << std::endl;
		   
        }

        //Kruskal
        if(menuwahl==5){
		   std::cout << "Aufwand Kruskal: " << myGraph->kruskal()<< std::endl;
		   std::cout << "________________________________ " << std::endl;
		   
        }

        //Print function
        if(menuwahl==6){
            bool done = myGraph->print();

            if(done)
                std::cout << "Print graph successful" << std::endl;
            else
                std::cout << "Not able to print" << std::endl;
        }

        //Quit
        if(menuwahl==0){
            delete myGraph;
        }
    }

    return 0;
}
