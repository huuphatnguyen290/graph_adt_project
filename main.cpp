#include <iostream>
#include <vector>
#include <string>

#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"
#include "GraphBuilder.h"
#include "GraphUI.h"
int main() {
    std::cout << "Hello!\n";
    Graph<std::string, double> graph = loadGraph<std::string, double>();
    
    userInteraction(graph);
    
    return 0;
}