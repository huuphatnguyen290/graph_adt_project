#ifndef VERTEX_H
#define VERTEX_H

#include <list>
#include "Edge.h"

template <typename T> class Edge; // forward

template <typename T> class Vertex {
    private:
        /*  The vertex object for a vertex v storing 
            element x has member variables for: */
        // Element x    
        T data;
        // The position (or entry) of the vertex-object in collection V
        size_t pos;

        std::list<Edge<T>*> incidenceEdges;
    public:
        //  Constructor
        Vertex(const T& data, size_t pos) : data(data), pos(pos) {}

        //  Add an incident edge
        void addEdge(Edge<T>* newEdge) {
            incidenceEdges.push_back(newEdge);
        }

        /*  ==========
            Vertex ADT
            ==========*/
        //  Return data
        const T& operator*() const {
            return data;
        }
        //  Return a list of incident edges to v
        const std::list<Edge<T>*>& incidentEdges() const {
            return incidenceEdges;
        }    
        //  Test whether vertices u and v are adjacent
        bool isAdjacentTo(Vertex<T>* v) const {
            for (Edge<T>* e : incidenceEdges) {
                if (e->opposite(this) == v) 
                    return true;
            }
        return false;
        }
};

#endif