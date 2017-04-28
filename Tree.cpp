//
// Created by henn on 26.04.17.
//

#include "Tree.h"
#include "DataEntry.h"
#include <iostream>
#include "string"
#include "Datareader.h"
#include <fstream>



TreeNode* Tree::getAnker() {
   return this->Anker;
}


void Tree::setAnker(TreeNode *newAnker) {
   this->Anker = newAnker;
}

bool Tree::fromFileInsertNewNodes() {
   Datareader Filereader;
   std::string CsvStringHolder[3];
   std::ifstream CsvStream = Filereader.createFileStream();
   
   std::string NewName;
   int NewPLZ;
   int NewAlter;
   double NewEinkommen;
   
   if (!CsvStream.is_open()) {
	  std::cout << "Es ist ein Fehler beim Oeffnen der CSV Datei aufgetreten" << std::endl;
	  return false;
   }
   
   while (CsvStream.good()) {
	  
	  Filereader.readStringsFromFile(CsvStream, CsvStringHolder);
	  
	  if (Filereader.canConvert(CsvStringHolder)) {
		 
		 
	  } else {
		 std::cout << "Es ist ein Fehler beim Konvertieren der Datentypen aus der CSV Datei " << std::endl;
		 return false;
	  }
	  
	  
   }
   
   
   bool Tree::fromManualEntryNewNode() {
	  
	  Datareader ManualReader;
	  DataEntry newEntry = ManualReader.getManualData();
	  
	  
   }
   
   void Tree::CallProcedure(std::string MenueFlag) {
	  
	  
	  if (MenueFlag == "1") {
		 this->fromManualEntryNewNode();
	  } else if (MenueFlag == "2") {
		 this->fromFileNewNodes();
	  } else if (MenueFlag == "3") {
		 
	  } else if (MenueFlag == "4") {
		 
	  } else if (MenueFlag == "5") {
		 
	  }
	  
   }
   
}


   TreeNode *Tree::insertNewNode(TreeNode *newNode) {
	  
	  if(this->Anker == nullptr){
		 Anker = newNode;
	  }
	  else {
		 TreeNode* tmp = Anker;
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

void Tree::treeAusgeben(void) {









}

TreeNode *Tree::searchNode(std::string searchData) {
   TreeNode* tmp = Anker;
   
   
   
   
   
   
   
   return nullptr;
}



