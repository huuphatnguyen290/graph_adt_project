#ifndef GRAPH_H
#define GRAPH_H

#include <list>

// forward declaration
class Vertex;
class Edge;

template <typename T> class Graph {
    private:
        std::list<Vertex*> adjList; // Adjacency List
        std::vector<Vertex*> vList;
        std::vector<Edge*> eList;
    public:
        //   Return a vertex list of all the vertices of the graph.
        std::vector<Vertex*> vertices() {
            return vList;
        }
        //  Return an edge list of all the edges of the graph.
        std::vector<Edge*> edges() {
            return eList;
        }
        //  Insert and return a new vertex storing element x
        Vertex::Vertex* insertVertex(x);
        /*  Insert and return a new undeirected edge with 
            end vertices v and w and storing element x*/
        Edge::Edge* insertEdge(v,w,x);
        //  Remove vertex v and all its incident edges
        void eraseVertex(v);
        // Remove edge e
        void eraseEdge(e);
};
#endif