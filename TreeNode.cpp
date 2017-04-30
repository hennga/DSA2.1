//
// Created by henn on 26.04.17.
//

#include "TreeNode.h"
#include <iostream>

TreeNode::TreeNode(const int _pos,const  int _id,const  std::string _name,const  int _age,const double _income,const int _plz) {
   this->NodePosID=_pos;
   this->NodeID=_id;
   this->Name=_name;
   this->Alter=_age;
   this->Einkommen=_income;
   this->PLZ= _plz;
}
TreeNode::TreeNode(const int _id,const std::string _name,const int _age,const double _income,const int _plz){
  this->NodePosID= _age + _plz + (int)_income;
  this->NodeID=_id;
  this->Name=_name;
  this->Alter=_age;
  this->Einkommen=_income;
  this->PLZ= _plz;
}
TreeNode::TreeNode(const int _id,const DataEntry* _data){
  this->NodePosID= _data->Alter + _data->PLZ + (int)_data->Einkommen;
  this->NodeID=_id;
  this->Name=_data->Name;
  this->Alter=_data->Alter;
  this->Einkommen=_data->Einkommen;
  this->PLZ= _data->PLZ;

}
int TreeNode::getNodePosID(void) {
   return this->NodePosID;
}

TreeNode *TreeNode::getLinksNode(void) {
   return links;
}

TreeNode *TreeNode::getRechtsNode(void) {
   return rechts;
}

void TreeNode::setRechtsNode(TreeNode *ToSet) {
   this->rechts=ToSet;
}

void TreeNode::setLinksNode(TreeNode *ToSet) {
   this->links=ToSet;
}

std::string TreeNode::getName(void){
  return Name;
}

int TreeNode::getAlter(void){
  return Alter;
}

double TreeNode::getEinkommen(void)
{
	return Einkommen;
}


int TreeNode::getPLZ(void){
  return PLZ;
}

void TreeNode::setNamen(const std::string _name){
  Name = _name;
}

void TreeNode::setAlter(const int _age){
  Alter = _age;
}

void TreeNode::setEinkommen(const double _income){
  Einkommen = _income;
}

void TreeNode::setPLZ(const int _plz){
  PLZ =  _plz;
}

void TreeNode::printData(void){
//format id
std::cout << NodePosID;
if(NodeID < 10){
  std::cout << "  ";
}
if(NodeID > 9 && NodeID < 100){
  std::cout << " ";
}

//FORMAT NAME
int w =32 - Name.size();
if(w < 0 || w == 0){
  std::cout << Name;
}else {
  for (size_t i = 0; i < w; i++) {
    std::cout << " ";
  }
  std::cout << Name;
}

//FORMAT AGE
//mal echt jetzt ich habe keine lust mehr auf das passend formatierte
std::cout << this->Alter << " | ";
std::cout << this->Einkommen << " | ";
std::cout << this->PLZ << " | ";
std::cout << this->NodeID << std::endl;

}
