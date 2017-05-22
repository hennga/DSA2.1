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
//    std::queue qu;
  //  qu.push(rootNode); //wir fangen mit dem root node an



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




bool Graph::is_edge_in_list(){

    return true;
}

double Graph::kruskal()
{
std::cout << "START KRUSKAL" <<std::endl;
    double kruskal_weight = 0.0f;

//erstelle liste mit kanten
    std::vector<KRUSAL_EDGE> edges_to_sort;
    edges_to_sort.clear();
    //now insert all edges to the list1
    for (int i = 0; i < _nodes.size(); ++i) {
        for (int k = 0; k < _nodes.at(i)->_edges.size(); ++k) {
            KRUSAL_EDGE tmp_edge;
            tmp_edge.distance =  _nodes.at(i)->_edges.at(k).value;
            tmp_edge.from = _nodes.at(i)->_key;
            tmp_edge.to = _nodes.at(i)->_edges.at(k).node->_key;
            edges_to_sort.push_back(tmp_edge);
        }
    }
    //NOW SORT LIST BY WEIGHT
    //IMPLEMENATION OF A SIMPLE BUBBLESORT
    bool all_wapped = true;
    int it1 = 0;
    KRUSAL_EDGE tmp_e;
    while(all_wapped){
        all_wapped = false;
        it1++;
        for (int i = 0; i < edges_to_sort.size()-1; ++i) {
            if(edges_to_sort.at(i).distance > edges_to_sort.at(i+1).distance){
                tmp_e = edges_to_sort.at(i);
                edges_to_sort.at(i) = edges_to_sort.at(i+1);
                edges_to_sort.at(i+1) = tmp_e;
                all_wapped = true;
            }
        }
    }
    //print sorted edge lsit
    for (int j = 0; j < edges_to_sort.size(); ++j) {
        std::cout << "FROM:" << edges_to_sort.at(j).from << " --" << edges_to_sort.at(j).distance << "--> TO:" << edges_to_sort.at(j).to << std::endl;
    }

    while(edges_to_sort.size() > 0){
        std::cout << edges_to_sort.size() << std::endl;
        KRUSAL_EDGE kleinste_kante = edges_to_sort.back();
        //TODO REMOVE AUS ege_to_sort bis auf das erste element
        std::vector<KRUSAL_EDGE> tmp_del;
    if(edges_to_sort.size() > 1) {
        for (int l = 1; l < edges_to_sort.size(); ++l) {
            tmp_del.push_back((KRUSAL_EDGE) edges_to_sort.at(l));
        }
        edges_to_sort = tmp_del;
    }else{
        std::cout << "WARNING REMOVE FAILED TODO IMPLEMENT" << std::endl;
    }

        //kreis ?
        if(true){

        }
    }







    return kruskal_weight;
}
