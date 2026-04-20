#ifndef GRAPH_H
#define GRAPH_H
// forward declaration
class Vertex;
class Edge;

template <typename T> class Graph {
    private:
        
    public:
        //   Return a vertex list of all the vertices of the graph.
        vertices()
        //  Return an edge list of all the edges of the graph.
        edges()
        //  Insert and return a new vertex storing element x
        insertVertex(x)
        /*  Insert and return a new undeirected edge with 
            end vertices v and w and storing element x*/
        insertEdge(v,w,x)
        //  Remove vertex v and all its incident edges
        eraseVertex(v)
        // Remove edge e
        eraseEdge(e)
};
#endif