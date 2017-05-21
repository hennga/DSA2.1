#include "P4_graph.h"

Graph::Graph()
{
    is_init = false;
    _anzKnoten = 0;
    _nodes.clear();
}

Graph::~Graph()
{
    is_init = false;
    for (int i = 0; i < _nodes.size(); i++) {
        delete _nodes[i];
    }
    _nodes.clear();
}

//Get the node pointer by given key
GraphNode* Graph::GetNodeByKey(int key)
{
    for(int i = 0; i < _anzKnoten; i++)
    {
        GraphNode* currentNode = _nodes[i];
        if(currentNode->_key == key)
        {
            return currentNode;
        }
    }
    return nullptr;
}

//iterate all nodes and set _visited to false
void Graph::setAllUnvisited()
{
    for(int i = 0; i < _nodes.size(); i++)
    {
        GraphNode* currentNode = _nodes[i];
        currentNode->_visited = false;
    }
}

//Check if all nodes are set to visited
bool Graph::checkVisited()
{
    for(int i = 0; i < _nodes.size(); i++)
    {
        GraphNode* currentNode = _nodes[i];
        if(currentNode->_visited == false)
            return false;
    }
    return true;
}

bool Graph::init(std::string path)
{
    {
    std::ifstream file;
    file.open(path, std::ios_base::in);

    if (!file)
    {
        std::cout << "Cannot open file." << std::endl;
        return false;
    }
    else
    {
        std::cout << "Start reading" << std::endl;

        std::string line = "";
        std::getline(file, line);
        std::istringstream iss(line);

        std::cout << "Insert _anzKnoten" << std::endl;
        iss >> _anzKnoten;

        std::cout << "Create all Nodes" << std::endl;
        //Alle Knoten anlegen
        for(int i = 0; i < _anzKnoten; i++)
        {
            GraphNode* currentNode = new GraphNode(i);
            _nodes.push_back(currentNode);
        }

        std::cout << "Start creating edges" << std::endl;
        while (std::getline(file, line))
        {


            std::stringstream edges(line);
            int from, value, to;
            if (!(edges >> from >> to >> value)) { break; } // error

            std::cout << "From: " << from << " To: " << to << " Value: " << value << std::endl;
            GraphNode* currentNode = GetNodeByKey(from);
            GraphNode* currentNeighbour = GetNodeByKey(to);
            //Hinrichrung:
            GraphNode::edge edge(currentNeighbour, value);
            currentNode->_edges.push_back(edge);
            //Rückrichtung:
            GraphNode::edge backEdge(currentNode, value);
            currentNeighbour->_edges.push_back(backEdge);
        }
        is_init = true;
       return true;
    }

    return false;
}

}

bool Graph::print() {
    if(_nodes.empty()){
        return false;
        }
    //Print with Node ID: 1st neighbour, 2nd neighbour ...
    for(int i = 0; i < _anzKnoten; i++)
    {
        GraphNode* currentNode = _nodes[i];
        std::cout << currentNode->_key << " ";
        for(int k = 0; k < currentNode->_edges.size(); k++)
        {
            if(!currentNode->_edges.empty()){
                GraphNode::edge currentEdge = currentNode->_edges[k];
                std::cout << " -> " << currentEdge.node->_key << " [" << currentEdge.value << "] ";
            }
        }
        std::cout << std::endl;
    }
   return true;
}




//TODO DAS IST EINE BREITENSUCHE ODER ?
//Or this
//OR DEINE MAM
bool Graph::depthSearchRecStart(int startKey)
{
    //all auf unbesucht sitzen
    for (int i = 0; i < _nodes.size(); ++i) {
        _nodes.at(i)->_visited = false;
    }
    //START SEARCH AND RETURN BOOLD
    return   depthSearchRec(_nodes.at(0), startKey); //suche mit dem root node beginnen
}

//DFS REK FUNC
bool Graph::depthSearchRec(GraphNode* x, int key){
x->_visited = true;
    if(x->_key == key){return true;}
    for (int i = 0; i < x->_edges.size(); ++i) {
        if(!x->_edges.at(i).node->_visited){
            return Graph::depthSearchRec(x->_edges.at(i).node,key);
        }
    }
    return false;
}


bool Graph::breadthSearchIter(int startKey)
{
    GraphNode * rootNode = _nodes.at(0);
    std::queue qu;
    qu.push(rootNode); //wir fangen mit dem root node an



    /*


while ( !queue.isEmpty() ) {
currentNode = getNextNode(queue);
// mach was mit currentNode
}

Wobei getNextNode in etwa so definiert wäre:

Node getNextNode( Queue q ) {
Node node = null;

if ( !q.isEmpty() ) {
node = q.pop(); // liest und entfernt erstes Element der Queue
Iterator it = node.getChildNodes();
while ( it.hasNext() )
q.push( it.next() ); // hängt it.next() an die Queue an
}

return node;
}
     */


    return false;
}




//This must be done by you
double Graph::prim(int startKey){
    return 5.;
}

double Graph::kruskal()
{
    return 5.;
}
