//
// Created by henn on 26.04.17.
//

#ifndef PRAKTIKUM2TREE_MENUE_H
#define PRAKTIKUM2TREE_MENUE_H

#include <string>
#include "DataEntry.h"


class Menue{

public:

	enum SELECTION_NN
	{
		INSERT = 0,
		INSERT_CSV = 1,
		DELETE = 2,
		SEARCH = 3,
		PRINT = 4
	};


	SELECTION_NN MenueUserSelection();
	bool checkUserSelection(std::string eingabe);

};














#endif //PRAKTIKUM2TREE_MENUE_H
