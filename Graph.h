#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <utility>
#include <algorithm>
#include "Vertex.h"
#include "Edge.h"

// Separate data type for vertex and edge
template <typename V, typename E> class Graph {
    private:
        //  Vector of all vertex of graph
        std::vector<Vertex<V, E>*> vList;
        // Incidence Collection I(v)
        std::vector<Edge<V, E>*> eList;
    public:
        //  No-argument constructor
        Graph() {}

        // Parameterized constructor, int vertices tell the program to create that many vertices
        Graph(int vertices) {}

        /*  =========
            Graph ADT
            =========*/
        //  Return a vertex list of all the vertices of the graph.
        std::vector<Vertex<V, E>*>& vertices() {
            return vList;
        }
        //  Return an edge list of all the edges of the graph.
        std::vector<Edge<V, E>*>& edges() {
            return eList;
        }

        /*  ===================================================
            These functions need to be implemented in Graph.cpp
            ===================================================*/
        //  Insert and return a new vertex storing element x
        Vertex<V, E>* insertVertex(V data) {
            Vertex<V, E>* v = new Vertex<V, E>(data);
            vList.push_back(v);
            return v;
        }
        /*  Insert and return a new undeirected edge with 
            end vertices v and w and storing element x*/
        Edge<V, E>* insertEdge(Vertex<V, E>* v, Vertex<V, E>* w, E data) {
            Edge<V, E>* e = new Edge<V, E>(v, w, data);
            eList.push_back(e);
            v->addEdge(e);
            w->addEdge(e);
            return e;
        }
        
        /*  Remove vertex v and all its incident edges
            1. Remove all incident edges
            2. Remove edge from eList
            3. Delete vertex v*/
        void eraseVertex(Vertex<V, E>* v) {
            // Go through each incident edges of vertex v
            for (Edge<V, E>* e : v->incidentEdges()) {
                
                // Access the two end vertices
                std::pair<Vertex<V, E>*, Vertex<V, E>*> ends = e->endVertices();
                // Remove edge from both end vertices
                ends.first->removeEdge(e);
                ends.second->removeEdge(e);

                // remove edge from eList
                eList.erase(std::remove(eList.begin(), eList.end(), e), eList.end());
                // delete that edges
                delete e;
            }

            // 2. Remove vertex from global vertex list
            vList.erase(std::remove(vList.begin(), vList.end(), v), vList.end());

            // 3. Delete vertex itself
            delete v;
        }
        // Remove edge e
        void eraseEdge(Edge<V, E>* e) {
            eList.erase(std::remove(eList.begin(), eList.end(), e), eList.end());
            delete e;
        }
};
#endif