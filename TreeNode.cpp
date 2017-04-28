//
// Created by henn on 26.04.17.
//

#include "TreeNode.h"


TreeNode::TreeNode(int NodePosId, int NodeID, std::string NewName, int NewAlter, double NewEinkommen, int NewPLZ) {
   
   this->NodePosID=NodePosId;
   this->NodeID=NodeID;
   this->Name=NewName;
   this->Alter=NewAlter;
   this->Einkommen=NewEinkommen;
   this->PLZ= NewPLZ;
}

int TreeNode::getNodePosID(void) {
   return this->NodePosID;
}

TreeNode *TreeNode::getLinksNode(void) {
   return links;
}

TreeNode *TreeNode::getRechtsNode(void) {
   return rechts;
}

void TreeNode::setRechtsNode(TreeNode *ToSet) {
   this->rechts=ToSet;
}

void TreeNode::setLinksNode(TreeNode *ToSet) {
   this->links=ToSet;
}
