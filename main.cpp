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
Tree* baum = new Tree();
Menue men;
Datareader reader;
//dauerschleife für Menue
while (42) {
  /* code */
std::string tmp = men.MenueUserSelection();


switch (tmp) {
  case "1": break; //manuell
    case "2": reader.readStringsFromFile(baum, FILE_CSV_PATH) break; //file
      case "3": break; //löschen

        case "4": {
          std::string tmp = "";
          std::cin >> tmp;
          TreeNode* n = baum->searchNode(tmp);
          n->printData();
        }
        break; //suchen
        
          case "5": baum->treeAusgebenbreak(); //print
  default:break;
}



}


//menu updaten


}
