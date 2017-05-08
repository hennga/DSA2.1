
#ifndef PRAKTIKUM2TREE_TREE_H
#define PRAKTIKUM2TREE_TREE_H
#include "TreeNode.h"
#include <vector>
class Tree {

private:
	TreeNode* Anker= nullptr;
	int NumberOfNodes;
	void deleteNode(const int _pos,TreeNode* NodeToBeSearched);
	void deleteAnkerMatch(void);
	void removeHit(TreeNode* parent,TreeNode* NodeToBeFound,bool PassingLinksNode);

public:
	Tree(bool _create_anchor);
	void setAnker(TreeNode* newAnker);
	TreeNode* getAnker(void);
	TreeNode* insertNewNode(TreeNode* newNode);
	void treeAusgeben( TreeNode* _anker); // Default auf Anker fuer start der Rekursion
	void searchNodeAndPrint( const std::string& searchData, TreeNode* _anker);
	void searchSingleNodeByPos(const int _pos,TreeNode* _anker,TreeNode*& result,TreeNode*& previous);
	int removeNode(const int _pos);
	int get_non();
	TreeNode* beforeSmallestinTree(TreeNode* ptr,TreeNode* smallest);
	TreeNode* findSmallestInTree(TreeNode* Ptr);
	void incrementNumberOfNodes();


//DESTRUCTOR ?
};

#endif //PRAKTIKUM2TREE_TREE_H
