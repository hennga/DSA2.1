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
	TreeNode* getAnker(void);
	TreeNode* insertNewNode(TreeNode* newNode);
	void treeAusgeben( TreeNode* _anker); // Default auf Anker fuer start der Rekursion
	void searchNode( const std::string& searchData, TreeNode* _anker);
	void traversePrintWhenCondition(bool condition,TreeNode* _anker);
	int deleteNode(const int _pos);
	int get_non();

//DESTRUCTOR ?
};

#endif //PRAKTIKUM2TREE_TREE_H

