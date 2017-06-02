//
// Created by henn on 01.06.17.
//

#ifndef P4_DISJOINTSET_H
#define P4_DISJOINTSET_H


#include <unordered_map>
#include <vector>
#include "P4_graphnode.h"
# include "P4_graph.h"

class DisjointSet {
public:

	
	std::unordered_map<int ,int> Parent;  // child und parent
	
	DisjointSet( std::vector<GraphNode*> _nodes);
	
	int findParentOf(int item );
	
	void UnionSet ( int set1, int set2);
	


};


#endif //P4_DISJOINTSET_H
