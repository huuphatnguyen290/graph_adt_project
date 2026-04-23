#include <iostream>
#include <vector>
#include <string>

#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"
#include "GraphBuilder.h"

int main() {
    
    Graph<std::string, double> graph = loadGraph<std::string, double>();
    userInteraction(graph);
    return 0;
}