//
// Created by henn on 24.04.17.
//

#include "Menue.h"
#include <iostream>

void Menue:: showSelectionMenue() const {
  
	
	for (auto &eintrag : MenueText){
	  std::cout<<eintrag << std::endl;
   }
}

int Menue::readMenueSelection() {
   int input = 0;
   std::cout<<"?> ";
   std::cin >> input;
   return input;
}

std::string Menue::readSearchWord() {
   std::string input = "";
   std::cin>>input;
   return input;
}

void Menue::callRingpufferMethods(int codeInt, Ringpuffer& Rp) {

 switch (codeInt){
   case 1 :
      std::cout << insertText;
	  Rp.addNode();
	  std::cout<<afterInsertText<<std::endl;
	  break;

   case 2:
      std::cout << searchText;
	   Rp.searchNode(readSearchWord());
	  
	  break;
	  
   case 3:
	  Rp.printRingpuffer();
	   break;
	
   default: {std::cout <<"Kein Befehl fuer diese Eingabe bekannt" << std::endl; }
 }
}



