#ifndef GRAPH_UI_H
#define GRAPH_UI_H

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"


void printLine() {
    std::cout << "+======================================+\n";
}

// Display the main menu
inline void displayOptions() {
    printLine();
    std::cout << "| What would you like to do?           |\n";
    printLine();
    std::cout << "| 1. Find edges incident on a vertex   |\n";
    std::cout << "| 2. Find a path in the graph          |\n";
    std::cout << "| 3. Insert an edge                    |\n";
    std::cout << "| 4. Erase a vertex                    |\n";
    std::cout << "| 5. Exit                              |\n";
    printLine();
}

// Read and validate an integer from the user
inline int getMenuInput() {
    std::string input;
    std::cout << "Input: ";
    std::cin >> input;

    for (char c : input) {
        if (!isdigit((unsigned char)c)) return -1;
    }
    if (input.empty()) return -1;
    return std::stoi(input);
}

// Read a full line of text from the user
inline std::string getStringInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin >> std::ws, input);
    return input;
}

// Find a vertex by its name, returns nullptr if not found
template <typename V, typename E>
Vertex<V, E>* findVertex(Graph<V, E>& graph, const std::string& name) {
    for (Vertex<V, E>* v : graph.vertices()) {
        if (**v == name) return v;
    }
    return nullptr;
}

// Check if an edge already exists between two vertices
template <typename V, typename E>
bool edgeExists(Vertex<V, E>* v, Vertex<V, E>* w) {
    for (Edge<V, E>* e : v->incidentEdges()) {
        if (e->opposite(v) == w) return true;
    }
    return false;
}

// DFS to find a path from current to target, returns true if found
template <typename V, typename E>
bool dfs(Vertex<V, E>* current, Vertex<V, E>* target,
         std::vector<Vertex<V, E>*>& path,
         std::vector<Vertex<V, E>*>& visited) {
    visited.push_back(current);
    path.push_back(current);

    if (current == target) return true;

    for (Edge<V, E>* e : current->incidentEdges()) {
        Vertex<V, E>* neighbor = e->opposite(current);

        bool seen = false;
        for (Vertex<V, E>* v : visited) {
            if (v == neighbor) { seen = true; break; }
        }

        if (!seen) {
            if (dfs(neighbor, target, path, visited)) return true;
        }
    }

    path.pop_back();
    return false;
}


template <typename V, typename E>
static void userInteraction(Graph<V, E>& graph) {
    int input;
    while (true) {
        displayOptions();
        input = getMenuInput();
        if (input == -1) {
            std::cout << "Invalid input. Please try again.\n\n";
            continue;
        }

        switch (input) {

        // Option 1: Find edges incident on a vertex
        case 1: {
            printLine();
            std::cout << "| List of vertices (" << graph.vertices().size() << "):                 |\n";
            printLine();
            int i = 0;
            for (Vertex<V, E>* v : graph.vertices()) {
                std::cout << "| " << i++ << ". " << **v << "\n";
            }
            printLine();
            std::cout << "| Please enter vertex number:          |\n";
            printLine();

            int index = getMenuInput();
            if (index < 0 || index >= (int)graph.vertices().size()) {
                std::cout << "Invalid input.\n\n";
                break;
            }

            Vertex<V, E>* v = graph.vertices()[index];
            std::cout << "\nIncident edges for " << **v << ":\n";
            for (Edge<V, E>* e : v->incidentEdges()) {
                Vertex<V, E>* other = e->opposite(v);
                std::cout << **v << " to " << **other << " is " << **e << " mi\n";
            }
            std::cout << "\n";
            break;
        }

        // Option 2: Find a path between two vertices (DFS, at least 3 vertices)
        case 2: {
            std::string startName = getStringInput("Enter starting vertex: ");
            std::string endName   = getStringInput("Enter destination vertex: ");

            Vertex<V, E>* start = findVertex(graph, startName);
            Vertex<V, E>* end   = findVertex(graph, endName);

            if (!start) { std::cout << "Vertex \"" << startName << "\" not found.\n\n"; break; }
            if (!end)   { std::cout << "Vertex \"" << endName   << "\" not found.\n\n"; break; }
            if (start == end) { std::cout << "Start and destination must be different.\n\n"; break; }

            std::vector<Vertex<V, E>*> path, visited;
            bool found = dfs(start, end, path, visited);

            if (!found || (int)path.size() < 3) {
                std::cout << "No path with at least 3 vertices found.\n\n";
                break;
            }

            for (size_t j = 0; j < path.size(); j++) {
                if (j > 0) std::cout << " to ";
                std::cout << **path[j];
            }
            std::cout << "\n\n";
            break;
        }

        // Option 3: Insert a new edge
        case 3: {
            std::string v1Name = getStringInput("Enter first vertex: ");
            std::string v2Name = getStringInput("Enter second vertex: ");
            std::string wStr   = getStringInput("Enter edge weight: ");

            Vertex<V, E>* v1 = findVertex(graph, v1Name);
            Vertex<V, E>* v2 = findVertex(graph, v2Name);

            if (!v1) { std::cout << "Vertex \"" << v1Name << "\" not found.\n\n"; break; }
            if (!v2) { std::cout << "Vertex \"" << v2Name << "\" not found.\n\n"; break; }
            if (edgeExists(v1, v2)) { std::cout << "Edge already exists.\n\n"; break; }

            double weight;
            try { weight = std::stod(wStr); }
            catch (...) { std::cout << "Invalid weight.\n\n"; break; }

            graph.insertEdge(v1, v2, weight);
            std::cout << "Edge inserted.\n\n";
            break;
        }

        // Option 4: Erase a vertex and all its edges
        case 4: {
            std::string vName = getStringInput("Enter vertex to remove: ");
            Vertex<V, E>* v = findVertex(graph, vName);

            if (!v) { std::cout << "Vertex \"" << vName << "\" not found.\n\n"; break; }

            graph.eraseVertex(v);
            std::cout << "Vertex removed.\n\n";
            break;
        }

        case 5:
            std::cout << "Goodbye!\n";
            return;

        default:
            std::cout << "Invalid option.\n\n";
            break;
        }
    }
}

#endif
