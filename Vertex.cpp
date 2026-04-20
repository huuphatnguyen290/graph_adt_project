#include "Vertex.h"
#include "Edge.h"


//  Constructor
Vertex::Vertex(std::string name) {
    this->name = name;
}
// Return the element associated with u
    std::string Vertex::operator*() {
return name;
}
// Return an edge list of the edges incident on u
std::vector<Edge*> Vertex::incidentEdges() {
    return edgeList;
}    
// Test whether vertices u and v are adjacent
bool Vertex::isAdjacentTo(Vertex* v) {
    for (Edge* e : edgeList) {
        if (e->opposite(this) == v) 
            return true;
        }
        return false;
}