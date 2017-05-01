//
// Created by henn on 27.04.17.
//

#include "Datareader.h"
#include <iostream>
#include <fstream>
#include <string>

//bool Datareader::checkManualData(std::string& assignString) {
//
//   try {
//	  std::getline(std::cin, assignString);
//
//	  if (assignString.empty()) {
//		 throw "Der eingegebene Name darf nicht leer sein";
//	  }
//   }
//   catch(std::string err){
//	  std::cout << err<< std::endl;
//
//	  return false;
//   }
//
//   return true;
//}
//




//bool Datareader::checkManualData( double& _assignDouble){
//return true;
//}
//bool Datareader::checkManualData( int& _assignInt){
//  return true;
//}


//
void Datareader::ConvertAndAddDataTypes(Tree* _tree, DataEntry& _data){
  //check ptr
//if(_tree == nullptr){
//  std::cout << "ERROR NULLPTR " << __FILE__ << ":" << __LINE__ << std::endl;
//  return;
//}
//
//TreeNode* node = new TreeNode(_tree->get_non(), &_data);
//
//if(node == nullptr){
//  std::cout << "_new_node_nullptr" << __FILE__ << ":" << __LINE__ << std::endl;
//}
//
//_tree->insertNewNode(node);
}
//
std::string Datareader::remove_chars(std::string _s, const char _c)
{
	std::string result;
	for (size_t i = 0; i < _s.size(); i++)
	{
		char currentChar = _s[i];
		if (currentChar != _c)
			result += currentChar;
	}
	return result;
}

//int Datareader::readStringsFromFile(Tree * _tree, const char * _file)
//{
//	return 0;
//}

int Datareader::readStringsFromFile(Tree* _tree, const char* _file){

        if(_tree == nullptr){
            std::cout << "_tree nullptr"<< __FILE__ << ":" <<__LINE__ << std::endl;
            return -1;
        }

        std::ifstream input(_file);
        if (input.fail()) {
             std::cout << "CSV FILE OPEN ERROR"<< __FILE__ << ":" <<__LINE__ << std::endl;
            return -2;
        }
        std::string line;
        for (std::string line; getline(input, line);)
        {
           std::cout << line << std::endl;
   //         //check for comments and empty lines
            if (line.size() == 0 || line == "\n" ||line == "\r" || (line.at(0) == '#' && line.at(1) == ' '))
            {
                continue;
            }
   //         //cehck for right ; chars
            int split_count = 0;
            for (int i = 0; i < line.size(); i++) {
                if(line[i] == CSV_SPLIT_CHAR){
                    split_count++;
                }
            }
            if(split_count != CSV_REQ_SPLIT_AMUNT){
                return -3;
                std::cout << "CSV FORMAT ERROR"<< __FILE__ << ":" <<__LINE__ << std::endl;
            }

   //         //REMOVE BAD CHARS
			line = remove_chars(line, '\r');
   //         //tmp vars
            std::string tmp = "";
           DataEntry entry;
			
   //         //read first
            const char* start_str = line.c_str();
            if (start_str == nullptr) {
                std::cout << "CSV READING ERROR"<< __FILE__ << ":" <<__LINE__ << std::endl;
                return  -4;
            }
            const char* end_str = strstr(start_str, ";");
            if (end_str == nullptr) {
                std::cout << "CSV READING ERROR"<< __FILE__ << ":" <<__LINE__ << std::endl;
                return  -4;
            }
   //         //appende beide string together
            tmp.append(start_str, end_str);
            entry.set_name(tmp);
            //read second
            start_str = strstr(end_str, ";");
            start_str++;
            if (start_str == nullptr) {
                std::cout << "CSV READING ERROR"<< __FILE__ << ":" <<__LINE__ << std::endl;
                return  -4;
            }
             end_str = strstr(start_str, ";");
            if (end_str == nullptr) {
                std::cout << "CSV READING ERROR"<< __FILE__ << ":" <<__LINE__ << std::endl;
                return  -4;
            }
   //         //appende beide string together
            tmp= "";
            tmp.append(start_str, end_str);
            entry.set_age(atoi(tmp.c_str()));
   //         //read third
            start_str = strstr(end_str, ";");
            start_str++;
            if (start_str == nullptr) {
                std::cout << "CSV READING ERROR"<< __FILE__ << ":" <<__LINE__ << std::endl;
                return  -4;
            }
            end_str = strstr(start_str, ";");
            if (end_str == nullptr) {
                std::cout << "CSV READING ERROR"<< __FILE__ << ":" <<__LINE__ << std::endl;
                return  -4;
            }
   //         //appende beide string together
            tmp= "";
            tmp.append(start_str, end_str);
            entry.set_income(atof(tmp.c_str()));
   //         //read third
            start_str = strstr(end_str, ";");
            start_str++;
            if (start_str == nullptr) {
                std::cout << "CSV READING ERROR"<< __FILE__ << ":" <<__LINE__ << std::endl;
                return  -4;
            }
            tmp= "";
            tmp.append(start_str);

			entry.set_plz(atoi(tmp.c_str()));
        ConvertAndAddDataTypes(_tree,entry);
        }
        return 0;
}


int Datareader::readManualData(Tree* _tree) {
	if (_tree == nullptr) {
		std::cout << __FILE__ << ":" << __LINE__ << " NULLPTR _TREE" << std::endl;
		return -1; 
	}
  //tmp vars
   std::string newName;
   int newPLZ = -1;
   int newAlter = -1;
   double newEinkommen = -1.0;
   std::cout << "Bitte geben Sie den neuen Datensatz ein" << std::endl;
   do {
	  std::cout << "Name ?> ";
	  std::cin>>newName;
   } while (newName == "");

   std::cin.ignore();
   do {
   std::cout<< "Alter ?> ";
	  std::cin>>newAlter;
   } while (newAlter < 0);

   do {
   std::cout<<"Einkommen ?> " ;
	  std::cin>>newEinkommen;
   } while (newEinkommen < 0.0);
   do {
   std::cout<<"PLZ ?> " ;
	  std::cin>>newPLZ;
  } while (newPLZ < 0);
  //TODO FIX
 
   DataEntry newEntry(newName,newPLZ,newAlter,newEinkommen);
   TreeNode* n = new TreeNode(_tree->get_non(), &newEntry);
   _tree->insertNewNode(n);
   return 0;
}





