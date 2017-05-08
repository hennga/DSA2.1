//
// Created by henn on 26.04.17.
//

#include "Tree.h"
#include "DataEntry.h"
#include <iostream>
#include "string"
#include "Datareader.h"
#include <fstream>


Tree::Tree(bool _create_anchor){
   NumberOfNodes = 0;
   if(_create_anchor){
//Anker = new TreeNode();
//TODO
   }
   
}


int Tree::get_non() {
   return NumberOfNodes;
}

TreeNode* Tree::getAnker() {
   return this->Anker;
}

void Tree::setAnker(TreeNode *newAnker) {
   this->Anker = newAnker;
}

TreeNode* Tree::insertNewNode(TreeNode *newNode) {
   if (this->Anker == nullptr) {
	  this->Anker = newNode;
	  this->incrementNumberOfNodes();
	  return newNode;
   } else {
	  TreeNode *tmp = this->Anker;
	  while (tmp != nullptr) {
		 
		 if (tmp->getNodePosID() >= newNode->getNodePosID()) {
			
			if (tmp->getLinksNode() == nullptr) {
			   tmp->setLinksNode(newNode);
			   this->incrementNumberOfNodes();
			   return newNode;
			}
			
			if (tmp->getLinksNode()->getNodePosID() <= newNode->getNodePosID()) {
			   
			   newNode->setLinksNode(tmp->getLinksNode());
			   
			   tmp->setLinksNode(newNode);
			   //neuer knoten liegt links vom Elternknoten tmp
			   this->incrementNumberOfNodes();
			   return newNode;
			} else {
			   tmp = tmp->getLinksNode();
			   
			}
		 } else if (tmp->getNodePosID() <= newNode->getNodePosID()) {
			
			if (tmp->getRechtsNode() == nullptr) {
			   tmp->setRechtsNode(newNode);
			   this->incrementNumberOfNodes();
			   return newNode;
			}
			
			if (tmp->getRechtsNode()->getNodePosID() >= newNode->getNodePosID()) {
			   
			   newNode->setRechtsNode(tmp->getRechtsNode());
			   tmp->setRechtsNode(newNode);
			   this->incrementNumberOfNodes();;
			   return newNode;
			   // neuer Knoten liegt rechts vom Elternknoten tmp
			} else {
			   tmp = tmp->getRechtsNode();
			}
		 }
	  }
   }
   return nullptr;
}

void Tree::treeAusgeben( TreeNode* _anker) {
   if(_anker!= nullptr){
	  
	  this->treeAusgeben(_anker->getLinksNode());
	  _anker->printData();
	  this->treeAusgeben(_anker->getRechtsNode());
   }
}

void Tree::searchNodeAndPrint( const std::string& searchData, TreeNode* _anker) {
   if(_anker!= nullptr){
	  if(_anker->getName()==searchData){_anker->printData();}
	  this->searchNodeAndPrint(searchData,_anker->getLinksNode());
	  this->searchNodeAndPrint(searchData,_anker->getRechtsNode());
   }
}


int Tree::removeNode(const int _pos) {

   this->deleteNode(_pos,this->getAnker());
   
   return 0;  // TODO codes funktionieren jetzt nicht mehr zuverlaessig wegen der Rekursion....

}

void Tree::searchSingleNodeByPos(const int _pos, TreeNode *_anker,TreeNode*& result,TreeNode*& previous) {
   
   
   if(_anker!= nullptr){
	  if(_anker->getNodeID()==_pos){
		 result=_anker;
		 return;
	  }
	  previous =_anker;
	  
	  this->searchSingleNodeByPos(_pos,_anker->getLinksNode(),result,previous);
	  this->searchSingleNodeByPos(_pos,_anker->getRechtsNode(),result,previous);
   }
   
}


void Tree::incrementNumberOfNodes() {
   this->NumberOfNodes += 1;
}

void Tree::deleteNode(const int _pos, TreeNode *NodeToBeSearched) {

if (this->getAnker()!= nullptr) {
   
   if (this->getAnker()->getNodePosID() == _pos) {
	  
	  this->deleteAnkerMatch();
	  
   } else {
	  
	  if (_pos < NodeToBeSearched->getNodePosID() && NodeToBeSearched->getLinksNode() != nullptr) {
		 
		 NodeToBeSearched->getLinksNode()->getNodePosID() == _pos ?
		 this->removeHit(NodeToBeSearched, NodeToBeSearched->getLinksNode(), true) :
		 this->deleteNode(_pos, NodeToBeSearched->getLinksNode());
		 
	  } else if (_pos > NodeToBeSearched->getNodePosID() && NodeToBeSearched->getRechtsNode() != nullptr) {
		 
		 NodeToBeSearched->getRechtsNode()->getNodePosID() == _pos ?
		 this->removeHit(NodeToBeSearched, NodeToBeSearched->getRechtsNode(), false) :
		 this->deleteNode(_pos, NodeToBeSearched->getRechtsNode());
	  }
	  
	  
   }
 
}




}

void Tree::deleteAnkerMatch(void) {
   
   TreeNode *toBeDeleted = this->getAnker();

// 1 Fall : Anker ist der einzige Knoten im Baum und hat keine Blaetterknoten;
   if (toBeDeleted->getLinksNode() == nullptr && toBeDeleted->getRechtsNode() == nullptr) {
	  delete toBeDeleted;
	  this->setAnker(nullptr);
   }

// 2 Fall : Anker hat nur einen Blattknoten, entweder den Linken oder Rechten
   else if (toBeDeleted->getRechtsNode() != nullptr && toBeDeleted->getLinksNode() == nullptr) {
	  this->setAnker(toBeDeleted->getRechtsNode());
	  delete toBeDeleted;
   } else if (toBeDeleted->getRechtsNode() == nullptr && toBeDeleted->getLinksNode() != nullptr) {
	  this->setAnker(toBeDeleted->getLinksNode());
	  delete toBeDeleted;
   }

// Fall 3 : Anker hat sowohl rechten als auch linken
   else {
	  
	  //Finde den Knoten mit dem kleinsten PosID Wert im Rechten TeilBaum
	  // Danach finde man den Knoten dessen linker Knoten der vorher gefundene kleinste Knoten ist
	  
	  TreeNode *SmallestInRight = findSmallestInTree(this->getAnker()->getRechtsNode());
	  TreeNode *BeforeSmallestInRight = nullptr;
	  
	  if (SmallestInRight != nullptr) {
		 BeforeSmallestInRight = beforeSmallestinTree(Anker->getRechtsNode(), SmallestInRight);
		 
		 if (BeforeSmallestInRight != this->getAnker()) {
			// Es kann sein, dass der kleinste Knoten im Rechten Teilbaum noch einen rechten Knoten hatte,
			//  in diesem Fall ist dieser der neue linke Knoten des Knotens BeforeSmallestInRight
			// ansonsten ist dies ein nullptr
			
			if (SmallestInRight->getRechtsNode() != nullptr) {
			   BeforeSmallestInRight->setLinksNode(SmallestInRight->getRechtsNode());
			} else {
			   BeforeSmallestInRight->setLinksNode(nullptr);
			}
			
			
			// Nun wird der Anker mit dem kleinsten Knoten des Rechten Teilbaums ersetzt.
			// zuerst werden dem zukuenftigen Anker die alten Rechts- und Linksknoten des alten Ankers zugewiesen
			
		
			SmallestInRight->setLinksNode(toBeDeleted->getLinksNode());
			this->setAnker(SmallestInRight);
			// Nun wird der alte Anker Knoten geloescht
			delete toBeDeleted;
		 } else {
			
			SmallestInRight->setRechtsNode(toBeDeleted->getRechtsNode());
			SmallestInRight->setLinksNode(toBeDeleted->getLinksNode());
			this->setAnker(SmallestInRight);
			// Nun wird der alte Anker Knoten geloescht
			delete toBeDeleted;
		 }
		 
	  }
	  
   }
}

TreeNode* Tree::findSmallestInTree(TreeNode *Ptr) {
   
   if(this->getAnker()== nullptr){
	  return nullptr;
   }
   else {
	  if (Ptr->getLinksNode()!= nullptr){
		 
		 return findSmallestInTree(Ptr->getLinksNode());
	  }
	  else { return Ptr;}
   }
}

TreeNode *Tree::beforeSmallestinTree(TreeNode *ptr,TreeNode* smallest) {
  
  if(ptr==smallest){
	 return smallest;
		
  }
  else if(ptr->getLinksNode()==smallest){
	  return ptr;
   }
   else {
	  return beforeSmallestinTree(ptr->getLinksNode(),smallest);
   }
}

void Tree::removeHit(TreeNode *parent, TreeNode *NodeToBeSearched, bool PassingLinksNode) {
   
   if (NodeToBeSearched->getLinksNode() == nullptr && NodeToBeSearched->getRechtsNode() == nullptr) {
	  delete NodeToBeSearched;
	  PassingLinksNode ? parent->setLinksNode(nullptr) : parent->setRechtsNode(nullptr);
	  
   } else if (NodeToBeSearched->getRechtsNode() != nullptr && NodeToBeSearched->getLinksNode() == nullptr) {
	  PassingLinksNode ? parent->setLinksNode(NodeToBeSearched->getRechtsNode()) : parent->setRechtsNode(NodeToBeSearched->getRechtsNode());
	  delete NodeToBeSearched;
	  
   } else if (NodeToBeSearched->getRechtsNode() == nullptr && NodeToBeSearched->getLinksNode() != nullptr) {
	  PassingLinksNode ? parent->setLinksNode(NodeToBeSearched->getLinksNode()) : parent->setRechtsNode(NodeToBeSearched->getLinksNode());
	  delete NodeToBeSearched;
   }
	  
	  // der Hit hat zwei Unterbaeume links und rechts
   else {
   
	  //Finde den Knoten mit dem kleinsten PosID Wert im Rechten TeilBaum
	  // Danach finde man den Knoten dessen linker Knoten der vorher gefundene kleinste Knoten ist
   
	  TreeNode *SmallestInRight = findSmallestInTree(NodeToBeSearched->getRechtsNode());
	  TreeNode *BeforeSmallestInRight = nullptr;
   
	  if (SmallestInRight != nullptr) {
		 BeforeSmallestInRight = beforeSmallestinTree(NodeToBeSearched->getRechtsNode(), SmallestInRight);
	  
	  
		 if (SmallestInRight->getRechtsNode() != nullptr) {
			BeforeSmallestInRight->setLinksNode(SmallestInRight->getRechtsNode());
		 } else {
			BeforeSmallestInRight->setLinksNode(nullptr);
		 }
	  
		 SmallestInRight->setRechtsNode(NodeToBeSearched->getRechtsNode());
		 SmallestInRight->setLinksNode(NodeToBeSearched->getLinksNode());
		 
		 PassingLinksNode ? parent->setLinksNode(SmallestInRight): parent->setRechtsNode(SmallestInRight);
		 
		 delete  NodeToBeSearched;
		 
	  }
	  
   }



}