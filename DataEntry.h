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
	//hmm lieber den ctr in die cpp oder ? besser leserlich bei so vielen vars
DataEntry(const std::string _name,const int _plz,const int _age,const  double _income);
void set_name(const std::string _val);
void set_plz(const int _val);
void set_age(const int _val);
void set_income(const double _val);

};
#endif //PRAKTIKUM2TREE_DATAENTRY_H
