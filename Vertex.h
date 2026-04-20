#ifndef VERTEX_H
#define VERTEX_H
#include <string>
#include <vector>
#include "Edge.h"

class Vertex {
    private:
        std::string name;
        std::vector<Edge*> edgeList;
    public:
        //  Constructor
        Vertex(std::string name) {
            this->name = name;
        }
        // Return the element associated with u
        std::string operator*() {
            return name;
        }
        // Return an edge list of the edges incident on u
        std::vector<Edge*> incidentEdges() {
            return edgeList;
        }
        // Test whether vertices u and v are adjacent
        bool isAdjacentTo(Vertex* v) {
            for (Edge* e : edgeList) {
                if (e->opposite(this) == v) 
                    return true;
            }
            return false;
        }
};

#endif