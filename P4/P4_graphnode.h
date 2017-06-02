#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <vector>
#include <list>

class GraphNode
{
public:

    struct edge {
        GraphNode *node; //Destination node
        double value; //Edge Weight

        edge(){
            node = nullptr;
            value = 0;

        }
        edge(GraphNode * n, double val)
        {
            node = n;
            value = val;
        }

        bool operator<(const edge& comp) const
            {
                return value < comp.value;
            }
    };

    //Maybe helpful for your Work
    GraphNode(int key);
    bool hasNeighbor(int neighborKey);
    edge getEdgeByNeigborkey(int key);
	bool operator<(const GraphNode &comp) const;
	
    int _key;
    std::vector<edge> _edges;
    bool _visited;
    double _distance;
    GraphNode *_prev;
    double _component;
	
	

};

#endif // GRAPHNODE_H
