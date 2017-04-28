//
// Created by henn on 26.04.17.
//

#ifndef PRAKTIKUM2TREE_DATAENTRY_H
#define PRAKTIKUM2TREE_DATAENTRY_H

#include "string"

class DataEntry {

private:
	std::string Name;
	int PLZ;
	int Alter;
	double Einkommen;

public:
	DataEntry(std::string newName,int newPLZ,int newAlter, double newEinkommen):
	Name(newName),PLZ(newPLZ),Alter(newAlter),Einkommen(newEinkommen){}
};


#endif //PRAKTIKUM2TREE_DATAENTRY_H
