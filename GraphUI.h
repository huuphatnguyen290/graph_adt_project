#ifndef GRAPH_UI_H
#define GRAPH_UI_H

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


// Helper Function
void printLine() {
    std::cout << "+======================================+\n";
}

/*  =======================================
    [Helper Function for userInteraction()] 
    Display options menu
    =======================================*/
inline void displayOptions() {
//  std::cout << "" << "\n";
    printLine();
    std::cout << "| What would you like to do?           |" << "\n";
    printLine();
    std::cout << "|1. Find edges incident on a vertex    |" << "\n";
    std::cout << "|2. Find a path in the graph           |" << "\n";
    std::cout << "|3. Insert an edge                     |" << "\n";
    std::cout << "|4. Erase a vertex                     |" << "\n";
    std::cout << "|5. Exit                               |" << "\n";
    printLine();
}

/*  =======================================
    [Helper Function for userInteraction()] 
    Get user's int input
    Check range: min < input < max
    =======================================*/
inline int getInput(int min, int max) {
    while (true) {
        std::string input;
        std::cout << "Input: ";
        std::cin >> input;

        // Check that input is all digits
        bool valid = true;
        for (char c : input) {
            if (!isdigit(static_cast<unsigned char>(c))) {
                valid = false;
                break;
            }
        }

        // Input check
        if (!valid || input.empty()) {
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        // Range check
        int value = std::stoi(input);
        if (value < min || value > max) {
            std::cout << "Input of out range (" << min << "-" << max << ")";
            continue;
        }

        return value;
    }
}

template <typename V, typename E> static void userInteraction(Graph<V, E>& graph) {
    int input;
    while (true) {
        displayOptions();
        input = getInput(1, 5);

        switch (input) {
        case 1: {
            printLine();
            std::cout << "| List of vertices (" << graph.vertices().size() <<"):                |\n"; 
            printLine();
            int i = 0;
            for (Vertex<V, E>* v : graph.vertices()) {
                std::cout << "|" << i++ << ". " << **v << "                                  |\n";
            }
            
            printLine();
            std::cout << "| Please specify the vertex            |\n"; 
            printLine();
    
            // Validate user's input
            int index = getInput(0,graph.vertices().size());

            Vertex<V, E>* specificVertex = graph.vertices()[index];
            printLine();
            std::cout << "| Here is all the incident edges       |\n";
            std::cout << "| Format: [vertex 1] [vertex 2] [data] |\n";
            i = 0;
            for (Edge<V, E>* e : specificVertex->incidentEdges()) {
                std::pair<Vertex<V, E>*, Vertex<V, E>*> p = e->endVertices();   
                std::cout << "|" << i++ << ". " << **e << "  |\n";
            }
            break;
        }
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