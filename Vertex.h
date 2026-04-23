#ifndef VERTEX_H
#define VERTEX_H

#include <list>
#include <algorithm>

template <typename V, typename E> class Edge; // forward declaration

template <typename V, typename E> class Vertex {
    private:
        /*  The vertex object for a vertex v storing 
            element x has member variables for: */
        //  Element x    
        V data;
        //
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
        //  Return data
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