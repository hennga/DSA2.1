//
// Created by henn on 26.04.17.
//




#ifndef PRAKTIKUM2TREE_TREE_H
#define PRAKTIKUM2TREE_TREE_H
#include "TreeNode.h"

class Tree {

private:
	TreeNode* Anker= nullptr;
	int NumberOfNodes;

public:
	Tree(bool _create_anchor);
	void setAnker(TreeNode* newAnker);
	void CallProcedure(std::string MenueFlag);
	TreeNode* getAnker(void);
	bool fromManualEntryNewNode();
	TreeNode* insertNewNode(TreeNode* newNode);
	void treeAusgeben(void);
	TreeNode* searchNode(std::string searchData);
	int get_non();

//DESTRUCTOR ?
};

#endif //PRAKTIKUM2TREE_TREE_H

