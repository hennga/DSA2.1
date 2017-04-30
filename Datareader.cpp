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



void ConvertAndAddDataTypes(Tree* _tree, DataEntry& _data){
  //check ptr
if(_tree == nullptr){
  std::cout << "ERROR NULLPTR " << __FILE__ << ":" << __LINE << std::endl;
  return;
}
//check data
if(checkManualData(_data.Name)
  && checkManualData(_data.PLZ)
  && checkManualData(_data.Alter)
  &&checkManualData(_data.Einkommen)){
  }else{
    std::cout << "ERROR" << __FILE__ << ":" << __LINE << std::endl;
    return;
  }
//nutze den 3. ctr für auto pos gen
TreeNode node = new TreeNode(_tree->NumberOfNodes, &_data);

if(node == nullptr){
  std::cout << "_new_node_nullptr" << __FILE__ << ":" << __LINE__ << std::endl;
}

_tree->insertNewNode(node);
}




void readStringsFromFile(Tree* _tree, const char* _file){

        if(tree == nullptr){
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
            //check for comments and empty lines
            if (line.size() == 0 || line == "\n" ||line == "\r" || (line.at(0) == '#' && line.at(1) == ' '))
            {
                continue;
            }
            //cehck for right ; chars
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

            //REMOVE BAD CHARS
            remove_chars(line, '\r');
            //tmp vars
            std::string tmp = "";
            DataEntry entry;
            //read first
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
            //appende beide string together
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
            //appende beide string together
            tmp= "";
            tmp.append(start_str, end_str);
            entry.set_age(atoi(tmp.c_str()));
            //read third
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
            //appende beide string together
            tmp= "";
            tmp.append(start_str, end_str);
            entry.set_income(atod(tmp.c_str()));
            //read third
            start_str = strstr(end_str, ";");
            start_str++;
            if (start_str == nullptr) {
                std::cout << "CSV READING ERROR"<< __FILE__ << ":" <<__LINE__ << std::endl;
                return  -4;
            }
            tmp= "";
            tmp.append(start_str);
            //TODO JO
            //_desc->pos = atoi(tmp.c_str());

            ConvertAndAddDataTypes(_tree,entry);
        }
        return 0;
}


DataEntry Datareader::getManualData(void) {
  //tmp vars
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
