//
// Created by henn on 26.04.17.
//




#ifndef PRAKTIKUM2TREE_TREE_H
#define PRAKTIKUM2TREE_TREE_H
#include "TreeNode.h"
#include <vector>
class Tree {

private:
	TreeNode* Anker= nullptr;
	int NumberOfNodes;
    std::vector<TreeNode*> nodes_list;
public:
	Tree(bool _create_anchor);
	void setAnker(TreeNode* newAnker);
	TreeNode* getAnker(void);
	TreeNode* insertNewNode(TreeNode* newNode);
	void treeAusgeben( TreeNode* _anker); // Default auf Anker fuer start der Rekursion
	void searchNodeAndPrint( const std::string& searchData, TreeNode* _anker);
	void traversePrintWhenCondition(bool condition,TreeNode* _anker);
	void searchSingleNodeByPos(const int _pos,TreeNode* _anker,TreeNode*& result,TreeNode*& previous);
	int deleteNode(const int _pos);
	int get_non();
	int checkRelationship(TreeNode* result,TreeNode* previous);
	void incrementNumberOfNodes();
	void decrementNumberOfNodes();

//DESTRUCTOR ?
};

#endif //PRAKTIKUM2TREE_TREE_H

