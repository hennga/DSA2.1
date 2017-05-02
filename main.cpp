#include <iostream>
#include <string>
#include "Tree.h"
#include "Menue.h"
#include "Datareader.h"
#include "DataEntry.h"

int main() {
#ifdef _MSC_VER 
#define FILE_CSV_PATH "ExportZielanalyse.csv"
#else
#define FILE_CSV_PATH "./ExportZielanalyse.csv"
#endif

	Tree* baum = new Tree(true);
Menue men;
Datareader reader;
//dauerschleife für Menue
while (42) {




switch (men.MenueUserSelection()) {
case Menue::SELECTION_NN::INSERT:reader.readManualData(baum); break; //manuell
case Menue::SELECTION_NN::INSERT_CSV : reader.readStringsFromFile(baum, FILE_CSV_PATH); break; //file
case Menue::SELECTION_NN::DELETE: {
	int p = -1;
	while (p < 0)
	{
		std::cout << "POS LOESCHEN EINGEBEN >";
		std::cin >> p;
	}
	p =baum->deleteNode(p);
	switch (p)
	{
	case 0:std::cout << "DEL OK" << std::endl; break;
	case -1:std::cout << "DEL ERROR" << std::endl; break;
	case -2:std::cout << " NO ENTRIES" << std::endl; break;

	default:
		std::cout << "DEF" << std::endl;
		break;
	}
}
	break; //löschen

	//die { machen einen neuen scope auf so kann ich einfach neue vars erstellen :D
case Menue::SELECTION_NN::SEARCH: {
          std::string tmp = "";
          std::cin >> tmp;
		  TreeNode* n = baum->getAnker();
		  baum->searchNode(tmp,n);
        //  n->printData();
        }
        break; //suchen
case Menue::SELECTION_NN::PRINT: {
	std::cout << "ID | NAME | ALTER | Einkommen | PLZ " << std::endl;
	baum->treeAusgeben(baum->getAnker());
		}
		break; //print
  default:break;
}



}


//menu updaten


}
