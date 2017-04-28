//
// Created by henn on 27.04.17.
//

#ifndef PRAKTIKUM2TREE_DATAREADER_H
#define PRAKTIKUM2TREE_DATAREADER_H

#include "DataEntry.h"
#include <string>
#include <fstream>
#include "TreeNode.h"
#include "Tree.h"


class Datareader {

private:
		//immer schön const :D
		const std::string CSVSearchadress = "ExportZielanalyse.csv";


public:
	bool checkManualData(const std::string& _assignString);
	bool checkManualData(const double& _assignDouble);
	bool checkManualData(const int& _assignInt);
	DataEntry getManualData(void);
	bool canConvert(std::string arr[]);
	DataEntry ConvertDataTypes(std::string arr[]);
	void readStringsFromFile(const Tree* _tree, const char* _file);




};


#endif //PRAKTIKUM2TREE_DATAREADER_H
