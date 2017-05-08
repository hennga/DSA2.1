
#ifndef PRAKTIKUM2TREE_DATAREADER_H
#define PRAKTIKUM2TREE_DATAREADER_H

#include "DataEntry.h"
#include <string>
#include <fstream>
#include "Tree.h"
#include "TreeNode.h"


#define CSV_SPLIT_CHAR ';'
#define CSV_REQ_SPLIT_AMUNT 3

class Datareader {

public:

	void ConvertAndAddDataTypes(Tree* _tree, DataEntry& _data);
	std::string remove_chars(std::string _s, const char _c);
	int readStringsFromFile(Tree* _tree, const char* _file);
	int readManualData(Tree* _tree);
};
#endif //PRAKTIKUM2TREE_DATAREADER_H
