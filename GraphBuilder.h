#ifndef GRAPH_BUILDER_H
#define GRAPH_BUILDER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"


// Remove leading and trailing whitespace
static inline std::string trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end   = s.find_last_not_of(" \t\r\n");
    if (start == std::string::npos) return "";
    return s.substr(start, end - start + 1);
}

// Ask user for a file name and open it, retry on failure
static inline void openFile(std::ifstream& file) {
    std::string filename;
    while (true) {
        std::cout << "Enter the file name: ";
        std::getline(std::cin >> std::ws, filename);
        file.open(filename);
        if (file.is_open()) {
            std::cout << "Thank you. Your graph is ready.\n\n";
            return;
        }
        std::cout << "Error: could not open \"" << filename << "\". Please try again.\n";
        file.clear();
    }
}

// Build a Graph from a file.
// Line 1: vertex list separated by commas or tabs
// Remaining lines: edge lines with format: vertex1  vertex2  weight
template <typename V, typename E>
Graph<V, E> loadGraph() {
    std::ifstream file;
    openFile(file);

    Graph<V, E> g;
    std::unordered_map<std::string, Vertex<V, E>*> map;
    std::string line;

    // First line: vertex list (comma-separated or tab-separated)
    if (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        char delim = (line.find(',') != std::string::npos) ? ',' : '\t';
        while (std::getline(ss, token, delim)) {
            token = trim(token);
            if (!token.empty()) {
                map[token] = g.insertVertex(token);
            }
        }
    }

    // Remaining lines: edge lines
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string u, v;
        double w;
        if (!(ss >> u >> v >> w)) continue;

        // Create vertices if they are not already in the map
        if (!map.count(u)) map[u] = g.insertVertex(u);
        if (!map.count(v)) map[v] = g.insertVertex(v);

        g.insertEdge(map[u], map[v], w);
    }

    return g;
}

#endif
