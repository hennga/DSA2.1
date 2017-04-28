//
// Created by henn on 26.04.17.
//

#include "Menue.h"
#include <iostream>
#include "DataEntry.h"
#include <string>
#include "Datareader.h"



std::string Menue::MenueUserSelection() {
   
   std::string eingabe;
   std::cout << "1) Datensatz einfuegen, manuell" << std::endl;
   std::cout << "2) Datensatz einfuegen, CSV Datei"<< std::endl;
   std::cout << "3) Datensatz loeschen" << std::endl;
   std::cout << "4) Datensatz suchen" << std::endl;
   std::cout << "5) Datenstruktur anzeigen " << std::endl;
   
   do {
	  std::cout << "?> ";
	  std::cin >> eingabe;
   
   }
   while (!checkUserSelection(eingabe));
   
   return eingabe;
}

bool Menue::checkUserSelection(std::string UserEntry) {
   
   if (UserEntry=="1"||UserEntry=="2"||UserEntry=="3" || UserEntry =="4"||UserEntry=="5"){
	  return true;
   }
   else {
	  std::cout << "Keine Option fuer diese Eingabe bekannt, bitte versuchen Sie es erneut"<< std::endl;
	  return false;}
}






