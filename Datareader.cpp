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





void Datareader::readStringsFromFile(std::ifstream CsvStream,std::string arr[]) {
   
   std::string Name,PLZ,Einkommen,Alter;
   
   getline(CsvStream,Name,',');
   getline(CsvStream,Alter,',');
   getline(CsvStream,Einkommen,',');
   getline(CsvStream,PLZ,',');
   
   arr[0]=Name;
   arr[1]=Alter;
   arr[2]=Einkommen;
   arr[3]=PLZ;
}

std::ifstream Datareader::createFileStream(void) {
   
	  std::ifstream CsvStream (CSVSearchadress);
   
   return CsvStream;
}

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
   
	  
	  
   } while (!this->checkManualData(newAlter))
   
   ;
   
   
   
   std::cout<<"Einkommen ? " ;
   
   
   std::cout <<"PLZ ?";
   
   
   DataEntry newEntry(newName,newPLZ,newAlter,newEinkommen);
   
   return newEntry;
   
}




}
