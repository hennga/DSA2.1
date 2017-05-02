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
	  if(this->Anker == nullptr){
		 this->Anker = newNode;
		 this->NumberOfNodes++;
		 return newNode;
	  }
	  else {
		 TreeNode* tmp = this->Anker;
		 while (tmp!= nullptr){

			if (tmp->getNodePosID()>=newNode->getNodePosID()) {
			
			if(tmp->getLinksNode()== nullptr){
			   tmp->setLinksNode(newNode);
			   return newNode;
			}
			
			if(tmp->getLinksNode()->getNodePosID()<=newNode->getNodePosID()) {

			   newNode->setLinksNode(tmp->getLinksNode());

			   tmp->setLinksNode(newNode);
			   //neuer knoten liegt links vom Elternknoten tmp
			   NumberOfNodes++;
			   return newNode;
			}
			   else {
				  tmp = tmp->getLinksNode();
				  
			   }
			}

			else if (tmp->getNodePosID()<=newNode->getNodePosID()){
			   
			   if(tmp->getRechtsNode()== nullptr){
				  tmp->setRechtsNode(newNode);
				  return newNode;
			   }
			   
			   if(tmp->getRechtsNode()->getNodePosID()>=newNode->getNodePosID()){

				  newNode->setRechtsNode(tmp->getRechtsNode());
				  tmp->setRechtsNode(newNode);
				  NumberOfNodes++;
				  return newNode;
				  // neuer Knoten liegt rechts vom Elternknoten tmp
			   }
			   else {
				  tmp= tmp->getRechtsNode();
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

void Tree::searchNode( const std::string& searchData, TreeNode* _anker) {
   if(_anker!= nullptr){
	  if(_anker->getName()==searchData){_anker->printData();}
	  this->searchNode(searchData,_anker->getLinksNode());
	  this->searchNode(searchData,_anker->getRechtsNode());
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

int Tree::deleteNode(const int _pos)
{
	if (NumberOfNodes== 0) {
		return -2;
	}
	else if (NumberOfNodes < 0) {
		return -1;
}
	//baum durchlaufen
	//node mit pos suchen
	//löschen
	//pointer biegen
	//ret 0 ok
	//ret 1 error
	return 0;
}
