//
// Created by henn on 26.04.17.
//

#include "TreeNode.h"


#ifndef PRAKTIKUM2TREE_TREE_H
#define PRAKTIKUM2TREE_TREE_H

#endif //PRAKTIKUM2TREE_TREE_H


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

//DESTRUCTOR ?
};
