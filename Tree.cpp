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



void Tree::traversePrintWhenCondition(bool condition, TreeNode *_anker) {
   
   //TODO Eventuell search und printtree zu einer Funktion zusammenlegen und Ausgabe ueber Bedingung steuern?
   
   
   if(_anker!= nullptr){
	  if(condition){_anker->printData();}
	  this->treeAusgeben(_anker->getLinksNode());
	  this->treeAusgeben(_anker->getRechtsNode());
   }
   
   
}

int Tree::deleteNode(const int _pos) {
   if (NumberOfNodes == 0) {
	  return -2;
   } else if (NumberOfNodes < 0) {
	  return -1;
   }
   TreeNode *tmp = this->getAnker();
   TreeNode *result= nullptr;
   TreeNode *previous= nullptr;
   
   searchSingleNodeByPos(_pos, tmp, result,
						 previous); // result zeigt jetzt auf den entsprechenden Knoten oder ist noch nullptr
   
   if (!result) {
	  
	  return 3;
   }
   
   else {
   
	  // Es ist nur ein Knoten im Baum, der Anker.
	  if(result==this->getAnker()){
		 delete result;
		 this->decrementNumberOfNodes();
		 this->setAnker(nullptr);
		 return 0;
	  }
	  
	  
	  if(this->checkRelationship(result,previous)==1){
		 //// Result liegt links vom previous Knoten
	  
		 if (result->getLinksNode()== nullptr && result->getRechtsNode()== nullptr){
		 
			delete result;
			previous->setLinksNode(nullptr);
			this->decrementNumberOfNodes();
			return 0;
		 }
		 
		 else if (result->getLinksNode()== nullptr){
			previous ->setLinksNode(result->getRechtsNode());
			delete result;
			this->decrementNumberOfNodes();
			return 0;
		 }
		
		 else if (result->getRechtsNode() == nullptr){
			previous ->setLinksNode(result->getLinksNode());
			delete result;
			this->decrementNumberOfNodes();
			return 0;
		 }
		 else {
			//Result hat links und rechts Knoten
			
			
			previous->setLinksNode(result->getRechtsNode());
			
			
			
			
			
		 }
		 
		 
		 
		 
	  }
	  
	  else if (this->checkRelationship(result,previous)==2){
		 //Result liegt rechts vom previous Knoten
	  
		 if (result->getLinksNode()== nullptr && result->getRechtsNode()== nullptr){
		 //Result hat keine Blaetter mehr
			delete result;
			previous->setRechtsNode(nullptr);
			this->decrementNumberOfNodes();
			return 0;
		 }
		
		 else if (result->getLinksNode()== nullptr){
			//Result hat keinen Knoten links dessen Wert kleiner ist, jedoch hat result einen rechten Knoten
			previous ->setRechtsNode(result->getRechtsNode());
			delete result;
			this->decrementNumberOfNodes();
			return 0;
		 }
		
		 else if (result->getRechtsNode()== nullptr){
			//Result hat keinen Knoten rechts dessen Wert groesser ist, jedoch hat result einen rechten Knoten
			previous ->setRechtsNode(result->getLinksNode());
			delete result;
			this->decrementNumberOfNodes();
			return 0;
		 }
		 
		 else {
			//Result hat links und rechts Knoten
			
			previous->setRechtsNode(result->getRechtsNode());
			
			//TODO tree rebalancing
			
			return 0;
			
			
		 }
		 
		 
		 
		 
	  }
	  
   }
   
   
   
   return 0;
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

int Tree::checkRelationship(TreeNode *result, TreeNode *previous) {
   
   if (result->getNodePosID()<=previous->getNodePosID()) {
	  return 1; // Result liegt links vom previous Knoten
   }
   
   else if (result->getNodePosID()>=previous->getNodePosID()) {
	  return 2; // Result liegt rechts vom previous Knoten
   }
   
   return 0;
}

void Tree::incrementNumberOfNodes() {
   this->NumberOfNodes += 1;
}

void Tree::decrementNumberOfNodes() {
   this->NumberOfNodes -= 1;
}
