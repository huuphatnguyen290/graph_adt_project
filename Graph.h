#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include "Vertex.h"
#include "Edge.h"

template <typename T> class Graph {
    private:
        std::vector<Vertex*> vList;
        std::vector<Edge*> eList;
    public:
        //  Getter for vList;

        /*  =========
            Graph ADT
            =========*/
        //  Return a vertex list of all the vertices of the graph.
        std::vector<Vertex*> vertices() {
            return vList;
        }
        //  Return an edge list of all the edges of the graph.
        std::vector<Edge*> edges() {
            return eList;
        }

        /*  ===================================================
            These functions need to be implemented in Graph.cpp
            ===================================================*/
        //  Insert and return a new vertex storing element x
        template <typename T> Vertex<T>* Graph<T>::insertVertex(T data) {
            Vertex<T>* v = new Vertex(data);
            vList.push_back(v);
            return v;
        }
        /*  Insert and return a new undeirected edge with 
            end vertices v and w and storing element x*/
        template <typename T> Edge<T>* Graph<T>::insertEdge(Vertex* v, Vertex* w, T data) {
            Edge<T>* e = new Edge(v, w, data);
            eList.push_back(v);
            v->edgeList.push_back(e);
            return e;
        }
        //  Remove vertex v and all its incident edges
        void eraseVertex(Vertex<T>* v) {
    
        }
        // Remove edge e
        void eraseEdge(e) {

        }
};
#endif