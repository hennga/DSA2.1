//
// Created by henn on 27.04.17.
//

#ifndef PRAKTIKUM2TREE_DATAREADER_H
#define PRAKTIKUM2TREE_DATAREADER_H

#include "DataEntry.h"
#include <string>
#include <fstream>



class Datareader {

private: std::string CSVSearchadress = "ExportZielanalyse.csv";


public:
	bool checkManualData(std::string& assignString);
	bool checkManualData(double& assignDouble);
	bool checkManualData(int& assignInt);
	std::ifstream createFileStream(void);
	DataEntry getManualData(void);
	bool canConvert(std::string arr[]);
	DataEntry ConvertDataTypes(std::string arr[]);
	void readStringsFromFile(std::ifstream CsvStream,std::string arr[]);
	
	
	
	
};


#endif //PRAKTIKUM2TREE_DATAREADER_H
