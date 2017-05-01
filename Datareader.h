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


#define CSV_SPLIT_CHAR ';'
#define CSV_REQ_SPLIT_AMUNT 3

class Datareader {

public:
	bool checkManualData( std::string& _assignString);
	bool checkManualData( double& _assignDouble);
	bool checkManualData( int& _assignInt);
	DataEntry getManualData(void);
	void ConvertAndAddDataTypes(Tree* _tree, DataEntry& _data);
	int readStringsFromFile(Tree* _tree, const char* _file = "ExportZielanalyse.csv");
	int readManualData(Tree* _tree);
};
#endif //PRAKTIKUM2TREE_DATAREADER_H
