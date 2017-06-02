#ifndef GRAPH_H
#define GRAPH_H

#include "P4_graphnode.h"

#include <deque>
#include <map>
#include <queue>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stack>



class Graph
{
public:
    Graph();
    ~Graph();

    GraphNode* GetNodeByKey(int key);
    void setAllUnvisited();
    bool checkVisited();
    bool init(std::string path);
    bool print();

    //Implement this:


    //Or this
    bool depthSearchRecStart(int startKey);
    bool depthSearchRec(GraphNode* x, int key);
    bool breadthSearchIter(int startKey);

    //This must be done by you
    double prim(int startKey);
    double kruskal();
public:
    //They might be helpful
    int _anzKnoten;
    bool _ger, _gew;
    bool is_init;
    std::vector<GraphNode*> _nodes;



    //für den krusal brauche wir noch en struct was das sortieren einfacher macht
    struct KRUSAL_EDGE{
        int from;
        int to;
        double distance;
    };
	
	struct Disjoint_set {
	
	
	
	};

    bool is_edge_in_list();
};

#endif // GRAPH_H
