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

//  Function prototype
// trim(string s) -> "    s" = "s"
static inline std::string trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \t");
    size_t end = s.find_last_not_of(" \t");

    if (start == std::string::npos) return "";
    return s.substr(start, end - start + 1);
}

/*  ===============================================================================
    [Helper Function for loadGraph()] get file name and open file, repeat if failed
    ===============================================================================*/
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

        std::string u, v, w;

        // split by TAB
        std::getline(ss, u, '\t');
        std::getline(ss, v, '\t');
        std::getline(ss, w, '\t');

        u = trim(u);
        v = trim(v);
        w = trim(w);

        // skip malformed lines
        if (u.empty() || v.empty() || w.empty()) continue;

        double weight = std::stod(w); // Turn string into number

        // create vertices if they don’t exist
        if (!map.count(u))
            map[u] = g.insertVertex(u);

        if (!map.count(v))
            map[v] = g.insertVertex(v);

        // create edge
        g.insertEdge(map[u], map[v], weight);
    }

    return g;
}

/*  =======================================
    [Helper Function for userInteraction()] 
    Display options menu and get int input
    =======================================*/
inline int getInput() {
    std::string input;

    //  std::cout << "" << "\n";
    std::cout << "+==================================+" << "\n";
    std::cout << "| What would you like to do?       |" << "\n";
    std::cout << "+==================================+" << "\n";
    std::cout << "|1. Find edges incident on a vertex|" << "\n";
    std::cout << "|2. Find a path in the graph       |" << "\n";
    std::cout << "|3. Insert an edge                 |" << "\n";
    std::cout << "|4. Erase a vertex                 |" << "\n";
    std::cout << "|5. Exit                           |" << "\n";
    std::cout << "+==================================+" << "\n";
    std::cout << "Input: ";
    std::cin >> input;


    // Check that input is all digits
    bool valid = true;
    for (size_t i = 0; i < input.size(); i++) {
        if (!isdigit(static_cast<unsigned char>(input[i]))) {
            valid = false;
            break;
        }
    }

    if (!valid || input.empty()) return -1;

    return std::stoi(input);
}

template <typename V, typename E> static void userInteraction(Graph<V, E>& graph) {
    int input;
    while (true) {
        input = getInput();
        if (input == -1) {
            std::cout << "Invalid input. Please try again.\n";
            continue;
        }

        switch (input) {
        case 1:
            
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            std::cout << "Goodbye!" << std::endl;
            return;
        default:
            break;
        }
    }

    
}

#endif