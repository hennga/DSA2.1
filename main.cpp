#include <iostream>
#include <string>
#include "Tree.h"
#include "Menue.h"
#include "Datareader.h"
#include "DataEntry.h"

int main() {
#define FILE_CSV_PATH "ExportZielanalyse.csv"
#define FILE_CSV_PATH "./ExportZielanalyse.csv"
//readStringsFromFile(Tree* _tree, const char* _file = "ExportZielanalyse.csv")

/*   std::cout << "1) Datensatz einfuegen, manuell" << std::endl;
   std::cout << "2) Datensatz einfuegen, CSV Datei"<< std::endl;
   std::cout << "3) Datensatz loeschen" << std::endl;
   std::cout << "4) Datensatz suchen" << std::endl;
   std::cout << "5) Datenstruktur anzeigen " << std::endl;*/
	Tree* baum = new Tree(true);
Menue men;
Datareader reader;
//dauerschleife für Menue
while (42) {
  /* code */



switch (men.MenueUserSelection()) {
case Menue::SELECTION_NN::INSERT: break; //manuell
case Menue::SELECTION_NN::INSERT_CSV : reader.readStringsFromFile(baum, FILE_CSV_PATH); break; //file
case Menue::SELECTION_NN::DELETE: break; //löschen

case Menue::SELECTION_NN::SEARCH: {
          std::string tmp = "";
          std::cin >> tmp;
          TreeNode* n = baum->searchNode(tmp);
          n->printData();
        }
        break; //suchen
case Menue::SELECTION_NN::PRINT: baum->treeAusgeben(); break; //print
  default:break;
}



}


//menu updaten


}
