#include "P4_graph.h"
#include "DisjointSet.h"
#include <set>



bool less(const GraphNode a, const GraphNode b) {
   return a._key > b._key;
}






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





bool Graph::depthSearchRecStart(int startKey)
{
   
    //all auf unbesucht sitzen
    for (int i = 0; i < _nodes.size(); ++i) {
        _nodes.at(i)->_visited = false;
    }
    //START SEARCH AND RETURN BOOLD
   depthSearchRec(_nodes.at(0), startKey); //suche mit dem root node beginnen
   
   for (int i = 0; i < _nodes.size(); ++i) {
	  if (_nodes.at(i)->_visited = false){
		 return false;
	  }
	  return true;
   }
   
}

//DFS REK FUNC
bool Graph::depthSearchRec(GraphNode* x, int key){
x->_visited = true;
   // if(x->_key == key){return true;}
    for (int i = 0; i < x->_edges.size(); ++i) {
        if(!x->_edges.at(i).node->_visited){
            return Graph::depthSearchRec(x->_edges.at(i).node,key);
        }
    }
    //return false;
}


bool Graph::breadthSearchIter(int startKey)
{
   for (int i = 0; i < _nodes.size(); ++i) {
	  _nodes.at(i)->_visited = false;
   }
   GraphNode * rootNode = _nodes.at(0);
   
   std::queue<GraphNode*> qu;
   qu.push(rootNode);
   rootNode->_visited = true;
   
   while(!qu.empty()){
	  
	  GraphNode* tmpNode = qu.front();
	  tmpNode->_visited=true;
	  
	  if(tmpNode->_key == startKey) {
		 //return true;
	  }
		 
	  for( auto &ed : tmpNode->_edges){
		 
		 if (ed.node->_visited == false ){
			qu.push(ed.node);
		 }
	  }
	  qu.pop();
   }
   
   for (int i = 0; i < _nodes.size(); ++i) {
	  
	  if(!_nodes.at(i)->_visited){
		 return false;
	  }
   }
   
    return true;
}

//This must be done by you
double Graph::prim(int startKey) {
   
   double AufwandWeight = 0.000;
   
   for (int i = 0; i < _nodes.size(); ++i) {
	  
	  _nodes.at(i)->_component = 99999.0;
	  _nodes.at(i)->_prev = nullptr;
   }
   
   _nodes.at(startKey)->_component = 0.0;   // Einfach dem Knoten an 0 des graphen den Keywert 0 zugewiesen, damit wird dieser Knoten Startpunkt
   
   std::priority_queue<GraphNode> pQ;
   
   std::set<GraphNode> setOfGraphNodes;
   std::vector<GraphNode *> vectorOfGraphNodes = _nodes;
   
   for (int i = 0; i < _nodes.size(); ++i) {
	  
	  setOfGraphNodes.insert(*_nodes.at(i));
   }
   
   /* for (int i = 0; i < _nodes.size(); ++i) {
	   
	   vectorOfGraphNodes.push_back(_nodes.at(i));
	} */
   
   
   
   while (!vectorOfGraphNodes.empty()) {
	  
	
	  double ComponentMinimum = vectorOfGraphNodes.at(0)->_component;
	  int indexOfMinimum = 0;
	  for (int i = 0; i < vectorOfGraphNodes.size(); ++i)
		 {
			if (ComponentMinimum > vectorOfGraphNodes.at(i)->_component) {
			   ComponentMinimum = vectorOfGraphNodes.at(i)->_component;
			   indexOfMinimum = i;
			}
		 }
		 
		 //  std::set<GraphNode>::iterator minKeyNode = setOfGraphNodes.begin();
		 //std::cout <<"New key MinkeyNode"<<minKeyNode->_key << std::endl;
	  
		 std::cout  << "Index von Minimum ist bei " << indexOfMinimum <<" mit dem Wert" <<vectorOfGraphNodes.at(indexOfMinimum)->_component  << " bei Knoten" << vectorOfGraphNodes.at(indexOfMinimum)->_key << std::endl;
		 for (auto &ed : vectorOfGraphNodes.at(indexOfMinimum)->_edges) {
		 
			
			// bool gefunden = false;
			
			// std::set<GraphNode>::iterator FoundNode = setOfGraphNodes.find(GraphNode(ed.node->_key));
			//
			//bool gefunden = FoundNode != setOfGraphNodes.end();
		 
			//std::cout  << "Kante von Knoten " << vectorOfGraphNodes.at(indexOfMinimum)->_key <<" Zu Knoten " << ed.node->_key <<std::endl;
			
			
			bool gefunden = false;
			for (int i = 0; i < vectorOfGraphNodes.size(); ++i) {
			   
			   if (ed.node->_key == vectorOfGraphNodes.at(i)->_key) {
				  gefunden = true;
			   }
			}
			if (!gefunden) {
			   // std::cout  << "Key nicht gefunden " << ed.node->_key <<std::endl;
			}
			
			if (gefunden && ed.value < ed.node->_component) {
			   
			  // std::cout  << "Key" << ed.node->_key << "   Gewicht " << ed.value << " Komponent Wert " << ed.node->_component << std::endl;
			 
			   //ed.node->_prev = minKeyNode;
			   ed.node->_component = ed.value;
			}
		 }
		 
	     vectorOfGraphNodes.at(indexOfMinimum)->_visited = true;
		 vectorOfGraphNodes.erase(vectorOfGraphNodes.begin() + indexOfMinimum);
	  }
	  
   
   
   for (int i = 0; i < _nodes.size(); ++i) {
	  
	  AufwandWeight += _nodes.at(i)->_component;
	  std::cout << "Key's " << _nodes.at(i)->_key << " new component value is " << _nodes.at(i)->_component << std::endl;
   }

   
   
   return AufwandWeight;
}

bool Graph::is_edge_in_list (){

    return true;
}

double Graph::kruskal() {
   
   double AufwandKruskal = 0.0;
   
   DisjointSet dS(this->_nodes);
   
   std::vector<KRUSAL_EDGE> edges_to_sort;
   edges_to_sort.clear();
   for (int i = 0; i < _nodes.size(); ++i) {
	  for (int k = 0; k < _nodes.at(i)->_edges.size(); ++k) {
		 KRUSAL_EDGE tmp_edge;
		 tmp_edge.distance = _nodes.at(i)->_edges.at(k).value;
		 tmp_edge.from = _nodes.at(i)->_key;
		 tmp_edge.to = _nodes.at(i)->_edges.at(k).node->_key;
		 edges_to_sort.push_back(tmp_edge);
	  }
   }
   
  
   
   // sortieren der Kanten aufsteigend.
   
   
   int j,i;
   for ( i = 0; i < edges_to_sort.size() - 1; ++i) {
	  for ( j = 0; j < edges_to_sort.size() -i - 1; ++j) {
	  if (edges_to_sort.at(j).distance > edges_to_sort.at(j + 1).distance) {
		 KRUSAL_EDGE tmp_e;
		 tmp_e = edges_to_sort.at(j);
		 edges_to_sort.at(j) = edges_to_sort.at(j + 1);
		 edges_to_sort.at(j + 1) = tmp_e;
	  }
	  }
   }
   
   
   for (auto &ed : edges_to_sort) {
	  //std::cout << "From "<< ed.from << "to " << ed.to << " mit Aufwand " <<   ed.distance << std::endl;
	  
   }
   
   std::vector<int> BesuchteKnoten;
   
   for (int i =0;i < edges_to_sort.size() - 1; ++i ) {
   
	  
      bool duplicate = false;
	  for (auto &besKnoten : BesuchteKnoten) {
		 
		 if (edges_to_sort.at(i).to == besKnoten){
			duplicate = true;
		 }
	  
	  }
	  
	 int  root1 = dS.findParentOf(edges_to_sort.at(i).from);
	  int  root2 = dS.findParentOf(edges_to_sort.at(i).to);
	  
	  if (root1!=root2 ) {
		
		 int altparent = dS.findParentOf(edges_to_sort.at(i).to);
		 std::cout << "Parentknoten from "<<dS.findParentOf(edges_to_sort.at(i).from) << " Parentknoten to " << dS.findParentOf(edges_to_sort.at(i).to)<< std::endl;
		 std::cout << "From "<< edges_to_sort.at(i).from << "to " << edges_to_sort.at(i).to << " mit Aufwand " <<   edges_to_sort.at(i).distance << std::endl;
		 
		 dS.UnionSet(root1, root2);
		 std::cout << "Parentknoten von TO vor Union " << altparent << " nach Union " << dS.findParentOf(edges_to_sort.at(i).to) << std::endl;
		 std::cout << "__________________________" <<std::endl;
		 
		 BesuchteKnoten.push_back(edges_to_sort.at(i).from);
		 
		 AufwandKruskal += edges_to_sort.at(i).distance;
	  }
   }
   return AufwandKruskal;
}
	
	
	
	
 /*   bool all_wapped = true;
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
    } */
    //print sorted edge lsit
   // for (int j = 0; j < edges_to_sort.size(); ++j) {
     //   std::cout << "FROM:" << edges_to_sort.at(j).from << " --" << edges_to_sort.at(j).distance << "--> TO:" << edges_to_sort.at(j).to << std::endl;
    //}

		 
		 
		 
		 
		 
		 
		 
		 
	/*
    while(edges_to_sort.size() > 0){

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
            //FÜGE WEG ZUM FINAL PFAD HINZU
        final_path.push_back(kleinste_kante);
        }
    }
   
    //berechne weg auf dem pfad
    for (int m = 0; m < final_path.size(); ++m) {
        kruskal_weight += final_path.at(m).distance;
    }
    //FERTIG
    return kruskal_weight; */

