//
// Created by henn on 01.06.17.
//

#include "DisjointSet.h"

void DisjointSet::UnionSet(int set1, int set2) {
  
   Parent[set1] = set2;
  
}

 int DisjointSet::findParentOf(int item) {

   if (Parent[item]==item)
	  return item;
	  else
	  return findParentOf(Parent[item]);
}

DisjointSet::DisjointSet(std::vector<GraphNode*> _nodes) {
   
   for (auto &ed: _nodes) {
	  
	  Parent[ed->_key] = ed->_key;
   }
   
}
