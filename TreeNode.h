//
// Created by henn on 26.04.17.
//
#ifndef PRAKTIKUM2TREE_TREENODE_H
#define PRAKTIKUM2TREE_TREENODE_H


#include <string>
#include "DataEntry.h"
#include <iostream>

class TreeNode {

private:
	int NodePosID;
	int NodeID;
	std::string Name;
	int Alter;
	double Einkommen;
	int PLZ;
	TreeNode* links= nullptr;
	TreeNode* rechts= nullptr;

public:
	TreeNode(const  int _pos,const int _id,const std::string _name,const int _age,const double _income,const int _plz);
	TreeNode(const int _id,const std::string _name,const int _age,const double _income,const int _plz);
		TreeNode(const int _id,const DataEntry* _data);
	std::string getName(void);
	int getAlter(void);
	double getEinkommen(void);
	int getPLZ(void);
	int getNodeID(void);
	void setNamen(const std::string _name);
	void setAlter(const int _age);
	void setEinkommen(const double _income);
	void setPLZ(const int _plz);
	void printData(void);
	int getNodePosID(void);
	TreeNode* getLinksNode(void);
	TreeNode* getRechtsNode(void);
	void setRechtsNode(TreeNode* ToSet);
	void setLinksNode(TreeNode* ToSet);
};









#endif //PRAKTIKUM2TREE_TREENODE_H
