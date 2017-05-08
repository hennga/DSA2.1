
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
	if (_data == nullptr && _id != -1) {
		std::cout << "treenode warning nullptr " << __LINE__ << ":" << __FILE__ << std::endl;
		return;
	}
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
	if (this == nullptr) {
		return;
	}
std::cout << NodeID << " | ";
std::cout << Name << "  | ";
std::cout << this->Alter << " | ";
std::cout << this->Einkommen << "   | ";
std::cout << this->PLZ << "   | ";
std::cout << this->NodePosID << std::endl;
}

int TreeNode::getNodeID(void) {
   return this->NodeID;
}
