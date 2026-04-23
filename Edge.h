#ifndef EDGE_H
#define EDGE_H

// pair object
#include <utility>

template <typename V, typename E> class Vertex; // forward declaration

// An edge object is shortened to e
template <typename V, typename E> class Edge {
    private:
        E data;
        Vertex<V, E>* u;
        Vertex<V, E>* v;    // Indices of endpoints
    public:
        // Constructor
        Edge(Vertex<V, E>* u, Vertex<V, E>* v, E data) {
            this->u = u;
            this->v = v;
            this->data = data;
        }

        /*  ========
            Edge ADT
            ========*/
        //  Return data stored in e
        const E& operator*() const {
            return data;
        }

        //  Return a list of e's two end vertices
        const std::pair<Vertex<V, E>*, Vertex<V, E>*> endVertices() const {
            return {u,v};
        }

        /*  Given vertex v, return the opposite vertex
            - Example: A--B, if endVertices(A) is called, return B
            - Error if vertex v is not part of the edge*/
        Vertex<V, E>* opposite(Vertex<V, E>* x) const {
            if (x == u) return v;
            if (x == v) return u;
            return nullptr; // not incident
        }

        //  Test whether edges e and f share a common vertex (adjacent to f)
        bool isAdjacentTo(Edge<V, E>* e) const {
            std::pair<Vertex<V, E>*, Vertex<V, E>*> e1 = endVertices();
            std::pair<Vertex<V, E>*, Vertex<V, E>*> e2 = e->endVertices();
            return (e1.first == e2.first || e1.first == e2.second || e1.second == e2.first || e1.second == e2.second);
        }

        // Test whether e is connected to vertex x (incident on x)
        bool isIncidentOn(Vertex<V, E>*x) const {
                return (x == v) || (x == u);
        }
};

#endif