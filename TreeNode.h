//
// Created by henn on 26.04.17.
//

#include <string>


#ifndef PRAKTIKUM2TREE_TREENODE_H
#define PRAKTIKUM2TREE_TREENODE_H

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
	TreeNode(int NodePosId,int NodeID,std::string NewName,int NewAlter,double NewEinkommen,int NewPLZ);
	std::string getName(void);
	int getAlter(void);
	double getEinkommen(void);
	int getPLZ(void);
	void setNamen(std::string newName);
	void setAlter(int newAlter);
	void setEinkommen(double newEinkommen);
	void setPLZ(int newPLZ);
	void printData(void);
	int getNodePosID(void);
	TreeNode* getLinksNode(void);
	TreeNode* getRechtsNode(void);
	void setRechtsNode(TreeNode* ToSet);
	void setLinksNode(TreeNode* ToSet);
	
	
	
};









#endif //PRAKTIKUM2TREE_TREENODE_H
