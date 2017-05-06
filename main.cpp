#include <iostream>
#include <string>
#include "Tree.h"
#include "Menue.h"
#include "Datareader.h"
#include "DataEntry.h"

int main() {
#ifdef _MSC_VER
#define FILE_CSV_PATH "c:\\users\\marcel\\desktop\\dsa2.1\\ExportZielanalyse.csv"
#else
#define FILE_CSV_PATH "/home/henn/2Semester/ADS/Praktikum/Praktikum1/TestKraken/DSA2.1/ExportZielanalyse.csv"
#endif
   
   Tree *baum = new Tree(true);
   Menue men;
   Datareader reader;
//dauerschleife für Menue
   
   while (42) {
	  
	  
	  switch (men.MenueUserSelection()) {
		 case Menue::SELECTION_NN::INSERT:
			reader.readManualData(baum);
			break; //manuell
		 case Menue::SELECTION_NN::INSERT_CSV :
			reader.readStringsFromFile(baum, FILE_CSV_PATH);
			break; //file
		 case Menue::SELECTION_NN::DELETE: {
			int p = -1;
			while (p < 0) {
			   std::cout << "POS LOESCHEN EINGEBEN >";
			   std::cin >> p;
			}
			p = baum->removeNode(p);
			switch (p) {
			   case 0:
				  std::cout << "DEL OK" << std::endl;
				  break;
			   case -1:
				  std::cout << "DEL ERROR" << std::endl;
				  break;
			   case 3:
				  std::cout << "KEIN SOLCHER KNOTEN VORHANDEN" << std::endl;
				  break;
			   case -2:
				  std::cout << " NO ENTRIES IN TREE" << std::endl;
				  break;
			   default:
				  std::cout << "DEF" << std::endl;
				  break;
			}
		 }
			break; //löschen
			
			//die { machen einen neuen scope auf so kann ich einfach neue vars erstellen :D
		 case Menue::SELECTION_NN::SEARCH: {
			std::string tmp = "";
			while (tmp.empty()) {
			   std::cout << "NAMEN EINGEBEN>>";
			   std::cin >> tmp;
			}
			baum->searchNodeAndPrint(tmp, baum->getAnker());
		 }
			break; //suchen
		 case Menue::SELECTION_NN::PRINT: {
			std::cout << "ID | NAME | ALTER | Einkommen | PLZ  | PosID" << std::endl;
			baum->treeAusgeben(baum->getAnker());
		 }
			break; //print
		 case Menue::SELECTION_NN::EXIT:
			return 0;
			break;
		 default:
			return 0;
			break;
	  }
   }


//menu updaten


}
