#ifndef EDGE_H
#define EDGE_H

#include <string>
// pair object
#include <utility>

template <typename T> class Vertex; // forward declaration

// An edge object is shortened to e
template <typename T> class Edge {
    private:
        T data;
        Vertex* u;
        Vertex* v;
    public:
        // Constructor
        Edge(Vertex* u, Vertex* v, T data) {
            this->u = u;
            this->v = v;
            this->data = data;
        }

        /*  ========
            Edge ADT
            ========*/
        //  Return data stored in e
        std::string operator*() {
            return label;
        }

        //  Return a list of e's two end vertices
        std::pair<Vertex*, Vertex*> endVertices() {
            return {u,v};
        }

        /*  Given vertex v, return the opposite vertex
            - Example: A--B, if endVertices(A) is called, return B
            - Error if vertex v is not part of the edge*/
        Vertex* opposite(Vertex* x) {
            if (x == u) return v;
            if (x == v) return u;
            return nullptr; // not incident
        }

        //  Test whether edges e and f share a common vertex (adjacent to f)
        bool isAdjacentTo(Edge* e) {
            std::pair<Vertex*, Vertex*> e1 = endVertices();
            std::pair<Vertex*, Vertex*> e2 = e->endVertices();
            return (e1.first == e2.first || e1.first == e2.second || e1.second == e2.first || e1.second == e2.second);
        }

        // Test whether e is connected to vertex x (incident on x)
        bool isIncidentOn(Vertex* x) {
                return (x == v) || (x == u);
        }
      
};

#endif