#ifndef VERTEX_H
#define VERTEX_H

#include <list>
#include <algorithm>

template <typename V, typename E> class Edge; // forward declaration

// A vertex object is shortened to v
template <typename V, typename E> class Vertex {
    private:
        //
        V data;
        // List all edge incident to v
        std::list<Edge<V, E>*> incidenceEdges;
    public:
        //  Constructor
        Vertex(const V& data) : data(data) {}

        //  Add an incident edge
        void addEdge(Edge<V, E>* newEdge) {
            incidenceEdges.push_back(newEdge);
        }

        //  Remove specific incident edge
        void removeEdge(Edge<V, E>* e) {
            incidenceEdges.remove(e);
        }

        /*  ==========
            Vertex ADT
            ==========*/
        //  Overload the (*) operator, return data
        const V& operator*() const {
            return data;
        }
        //  Return a list of incident edges to v
        const std::list<Edge<V, E>*>& incidentEdges() const {
            return incidenceEdges;
        }    
        //  Test whether vertices u and v are adjacent
        bool isAdjacentTo(Vertex<V, E>* v) const {
            for (Edge<V, E>* e : incidenceEdges) {
                if (e->opposite(this) == v) 
                    return true;
            }
        return false;
        }
};

#endif