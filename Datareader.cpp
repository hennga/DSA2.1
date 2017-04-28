//
// Created by henn on 27.04.17.
//

#include "Datareader.h"
#include <iostream>
#include <fstream>
#include <string>

bool Datareader::checkManualData(std::string &assignString) {

   try {
	  std::getline(std::cin, assignString);

	  if (assignString.empty()) {
		 throw "Der eingegebene Name darf nicht leer sein";
	  }
   }
   catch(std::string err){
	  std::cout << err<< std::endl;

	  return false;
   }

   return true;
}




bool checkManualData(const std::string& _assignString){
  if(_assignString == ""){return false;}
return true;
}
bool checkManualData(const double& _assignDouble){
return true;
}
bool checkManualData(const int& _assignInt){
  return true;
}


void readStringsFromFile(const Tree* _tree, const char* _file);



DataEntry Datareader::getManualData(void) {
   std::string newName;
   int newPLZ;
   int newAlter;
   double newEinkommen;

   std::cout << "Bitte geben Sie den neuen Datensatz ein" << std::endl;

   do {
	  std::cout << "Name ?> ";
	  std::cin>>newName;
   } while (!this->checkManualData(newName));

   do {
   std::cout<< "Alter ?> ";
	  std::cin>>newAlter;
   } while (!this->checkManualData(newAlter));

   do {
   std::cout<<"Einkommen ?> " ;
	  std::cin>>newEinkommen;
   } while (!this->checkManualData(newEinkommen));


   do {
   std::cout<<"PLZ ?> " ;
	  std::cin>>newEinkommen;
  } while (!this->checkManualData(newPLZ));

   DataEntry newEntry(newName,newPLZ,newAlter,newEinkommen);

   return newEntry;
}




}
