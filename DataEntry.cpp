//
// Created by henn on 26.04.17.
//
#include "DataEntry.h"

DataEntry::DataEntry(const std::string _name,const int _plz,const int _age,const  double _income){
  Name = _name;
  Alter = _age;
  PLZ = _plz;
  Einkommen = _income;
}

void DataEntry::set_name(const std::string _val){Name = _val;}
void DataEntry::set_plz(const int _val){PLZ = _val;}
void DataEntry::set_age(const int _val){Alter = _val;}
void DataEntry::set_income(const double _val){einkommen = _val;}
