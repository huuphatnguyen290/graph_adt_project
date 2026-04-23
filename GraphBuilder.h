#ifndef GRAPH_BUILDER_H
#define GRAPH_BUILDER_H

//  I/O stream
#include <iostream>
#include <fstream>
//  String parsing
#include <sstream>
#include <string>
//  Container
#include <vector>
#include <unordered_map>
//  Utilities
#include <algorithm>
#include <cctype>
#include <limits>

// Header files
#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"


/*  =====================================================
    [Helper Function for loadGraph()] 
    Removes leading and trailing whitespace from a string
    =====================================================*/
static inline std::string trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \t");
    size_t end = s.find_last_not_of(" \t");

    if (start == std::string::npos) return "";
    return s.substr(start, end - start + 1);
}

/*  =============================================
    [Helper Function for loadGraph()] 
    get file name and open file, repeat if failed
    =============================================*/
static inline void openFile(std::ifstream& file) {
    std::string filename;

    while (true) {
        std::cout << "Enter file name: ";
        std::getline(std::cin >> std::ws, filename);
        file.open(filename);

        if (file.is_open()) {
            std::cout << "Thank you. your graph from " << filename << " is ready.\n";
            return;
        }

        std::cout << "Error: could not open " << filename << ". Try again\n";
        file.clear(); // reset error state
    }
}

template <typename V, typename E> Graph<V, E> loadGraph() {
    // Try to open file
    std::ifstream file;
    openFile(file);

    Graph<V, E> g;

    std::unordered_map<std::string, Vertex<V, E>*> map;
    std::string line;

    // Read line if there is a line
    while (std::getline(file, line)) {
        if (line.empty()) continue; // Skip empty lines

        std::stringstream ss(line);

        // Header line: comma-separated vertices
        if (line.find(',') != std::string::npos) {
            std::string v;

            while (std::getline(ss, v, ',')) {
                v = trim(v);
                if (!v.empty()) {
                    map[v] = g.insertVertex(v);
                }
            }
            continue;
        }

        // Edge line: whitespace-separated
        std::string u, v;
        double w;

        if (!(ss >> u >> v >> w)) continue;

        // create vertices if they don’t exist
        if (!map.count(u))
            map[u] = g.insertVertex(u);

        if (!map.count(v))
            map[v] = g.insertVertex(v);

        // create edge
        g.insertEdge(map[u], map[v], w);
    }

    return g;
}

#endif