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

bool Tree::fromManualEntryNewNode() {

	  Datareader ManualReader;
	  DataEntry newEntry = ManualReader.getManualData();
	  return true;
 }

   void Tree::CallProcedure(std::string MenueFlag) {

	   /*
	  if (MenueFlag == "1") {
		 this->fromManualEntryNewNode();
	  } else if (MenueFlag == "2") {
		 this->fromFileNewNodes();
	  } else if (MenueFlag == "3") {

	  } else if (MenueFlag == "4") {

	  } else if (MenueFlag == "5") {

	  }
	  */

   //}

}


   TreeNode* Tree::insertNewNode(TreeNode *newNode) {

	  if(this->Anker == nullptr){
		 this->Anker = newNode;
		 this->NumberOfNodes++;
	  }
	  else {
		 TreeNode* tmp = this->Anker;
		 while (tmp!= nullptr){

			if (tmp->getNodePosID()>=newNode->getNodePosID()) {
			if(tmp->getLinksNode()->getNodePosID()<=newNode->getNodePosID()) {

			   newNode->setLinksNode(tmp->getLinksNode());

			   tmp->setLinksNode(newNode);
			   //neuer knoten liegt links vom Elternknoten tmp
			   NumberOfNodes++;
			   break;
			}
			   else {
				  tmp = tmp->getLinksNode();
				  continue;
			   }
			}

			else if (tmp->getNodePosID()<=newNode->getNodePosID()){
			   if(tmp->getRechtsNode()->getNodePosID()>=newNode->getNodePosID()){

				  newNode->setRechtsNode(tmp->getRechtsNode());
				  tmp->setRechtsNode(newNode);
				  NumberOfNodes++;
				  break;
				  // neuer Knoten liegt rechts vom Elternknoten tmp
			   }
			   else {
				  tmp= tmp->getRechtsNode();
			   }

			}

		 }

	  }

   }

void Tree::treeAusgeben( TreeNode* _anker) {
   
   
   
   if(_anker!= nullptr){
	  
	  _anker->printData();
	  this->treeAusgeben(_anker->getLinksNode());
	  this->treeAusgeben(_anker->getRechtsNode());
   }
   

//TODO DURCH JEDEN NODE DA print AUSGEBEN

   
   
   
   
   
   
   
   
   this->Anker->printData();
}

void Tree::searchNode( const std::string& searchData, TreeNode* _anker) {
   
   
   if(_anker!= nullptr){
	  
	  if(_anker->getName()==searchData){_anker->printData();}
	  this->searchNode(searchData,_anker->getLinksNode());
	  this->searchNode(searchData,_anker->getRechtsNode());
   }
   
}

TreeNode *Tree::deleteNode() {
   //TODO Loeschen der unterschiedlichen Faelle von child nodes...
   
   
   
  
  
  
  
  
  
  
  
   return nullptr;
}

void Tree::traversePrintWhenCondition(bool condition, TreeNode *_anker) {
   
   //TODO Eventuell search und printtree zu einer Funktion zusammenlegen und Ausgabe ueber Bedingung steuern?
   
   
   if(_anker!= nullptr){
	  
	  if(condition){_anker->printData();}
	  this->treeAusgeben(_anker->getLinksNode());
	  this->treeAusgeben(_anker->getRechtsNode());
   }
   
   
}
